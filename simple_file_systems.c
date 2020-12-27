//2020/운영체제/hw4-SFS 파일 시스템/김정천
// Simple FIle System
// Student Name : 김정천
// Student Number : B611045
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* optional */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/***********/

#include "sfs_types.h"
#include "sfs_func.h"
#include "sfs_disk.h"
#include "sfs.h"

void dump_directory();

/* BIT operation Macros */
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1 << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1 << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1 << (b)))
#define BIT_CHECK(a, b) ((a) & (1 << (b)))

static struct sfs_super spb;                // superblock
static struct sfs_dir sd_cwd = {SFS_NOINO}; // current working directory

void error_message(const char *message, const char *path, int error_code)
{
    switch (error_code)
    {
    case -1:
        printf("%s: %s: No such file or directory\n", message, path);
        return;
    case -2:
        printf("%s: %s: Not a directory\n", message, path);
        return;
    case -3:
        printf("%s: %s: Directory full\n", message, path);
        return;
    case -4:
        printf("%s: %s: No block available\n", message, path);
        return;
    case -5:
        printf("%s: %s: Not a directory\n", message, path);
        return;
    case -6:
        printf("%s: %s: Already exists\n", message, path);
        return;
    case -7:
        printf("%s: %s: Directory not empty\n", message, path);
        return;
    case -8:
        printf("%s: %s: Invalid argument\n", message, path);
        return;
    case -9:
        printf("%s: %s: Is a directory\n", message, path);
        return;
    case -10:
        printf("%s: %s: Is not a file\n", message, path);
        return;
    case -11:
        printf("%s: can't open %s input file\n", message, path);
        return;
    default:
        printf("unknown error code\n");
        return;
    }
}

//슈퍼블록의 정보 넣어준다고 생각.
void sfs_mount(const char *path)
{
    if (sd_cwd.sfd_ino != SFS_NOINO)
    {
        //umount
        disk_close();
        printf("%s, unmounted\n", spb.sp_volname);
        bzero(&spb, sizeof(struct sfs_super));
        sd_cwd.sfd_ino = SFS_NOINO;
    }

    printf("Disk image: %s\n", path);

    disk_open(path);
    disk_read(&spb, SFS_SB_LOCATION);

    printf("Superblock magic: %x\n", spb.sp_magic);

    assert(spb.sp_magic == SFS_MAGIC);

    printf("Number of blocks: %d\n", spb.sp_nblocks);
    printf("Volume name: %s\n", spb.sp_volname);
    printf("%s, mounted\n", spb.sp_volname);

    // 루트에 있는 inode 번호, 이름 (처음 마운트 했을 때의 현재 디렉토리 상태)
    sd_cwd.sfd_ino = 1; //init at root
    sd_cwd.sfd_name[0] = '/';
    sd_cwd.sfd_name[1] = '\0';
}

void sfs_umount()
{

    if (sd_cwd.sfd_ino != SFS_NOINO)
    {
        //umount
        disk_close();
        printf("%s, unmounted\n", spb.sp_volname);
        bzero(&spb, sizeof(struct sfs_super));
        sd_cwd.sfd_ino = SFS_NOINO;
    }
}

void sfs_touch(const char *path)
{
    int i, j, l, m, block_num;
    int tag_1 = 0;
    int tag_2 = 0;
    int bit_end = SFS_MAP_LOCATION + (spb.sp_nblocks / SFS_BLOCKBITS);
    int tag = 0;
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_inode newbie;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
    char bitmap_1[512];

    disk_read(&inode, sd_cwd.sfd_ino);

    for (i = 0; i < SFS_NDIRECT; i++)
    { // 이미 존재하는 경우 찾자
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (strcmp(dir_entry[j].sfd_name, path) == 0)
            { // 이미 이름이 있는 경우
                error_message("touch", path, -6);
                return;
            }
        }
    }

    for (i = SFS_MAP_LOCATION; i <= bit_end; i++)
    { // 비트맵이 꽉 차 있는지 확인.
        disk_read(bitmap_1, i);
        for (j = 0; j < 512; j++)
        {
            if (bitmap_1[j] != -1)
            {
                tag = 1;
                break;
            }
        }
    }
    if (tag == 0)
    { // 꽉 차 있는 경우
        error_message("touch", path, -4);
        return;
    }

    for (l = 0; l < SFS_NDIRECT; l++)
    {
        if (inode.sfi_direct[l] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[l]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (dir_entry[j].sfd_ino == 0)
            { // 0 인 부분에 데이터를 넣는다. block num 구하기
                tag_2 = 1;
                for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
                { // 빈 블록 찾기 (한 개 찾기)
                    if (tag_1 == 1)
                    { // 하나 할당했으면
                        break;
                    }
                    disk_read(bitmap_1, m);
                    for (i = 0; i < 512; i++)
                    {
                        if (bitmap_1[i] != -1)
                        {
                            if (bitmap_1[i] == 0)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i);
                                bitmap_1[i] = 1;
                            }
                            else if (bitmap_1[i] == 1)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i) + 1;
                                bitmap_1[i] = 3;
                            }
                            else if (bitmap_1[i] == 3)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i) + 2;
                                bitmap_1[i] = 7;
                            }
                            else if (bitmap_1[i] == 7)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i) + 3;
                                bitmap_1[i] = 15;
                            }
                            else if (bitmap_1[i] == 15)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i) + 4;
                                bitmap_1[i] = 31;
                            }
                            else if (bitmap_1[i] == 31)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i) + 5;
                                bitmap_1[i] = 63;
                            }
                            else if (bitmap_1[i] == 63)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i) + 6;
                                bitmap_1[i] = 127;
                            }
                            else if (bitmap_1[i] == 127)
                            {
                                block_num = ((m - 2) * 4096) + (8 * i) + 7;
                                bitmap_1[i] = -1;
                            }
                            tag_1 = 1;
                            disk_write(bitmap_1, m);
                            break;
                        }
                    }
                }

                dir_entry[j].sfd_ino = block_num;
                strncpy(dir_entry[j].sfd_name, path, SFS_NAMELEN);
                disk_write(dir_entry, inode.sfi_direct[l]);

                inode.sfi_size += sizeof(struct sfs_dir);
                disk_write(&inode, sd_cwd.sfd_ino);

                bzero(&newbie, SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect
                newbie.sfi_size = 0;
                newbie.sfi_type = SFS_TYPE_FILE;

                disk_write(&newbie, block_num);
                return;
            }
        }
    }
    if (tag_2 == 0)
    {
        error_message("touch", path, -3);
    }
}

void sfs_cd(const char *path)
{ //path의 위치를 찾아야돼
    int i, j;
    int flag = 0;
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];

    disk_read(&inode, sd_cwd.sfd_ino);

    if (path == NULL)
    { // root 디렉토리로 간다.
        sd_cwd.sfd_ino = 1;
        sd_cwd.sfd_name[0] = '/';
        sd_cwd.sfd_name[1] = '\0';
        return;
    }

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (inode.sfi_direct[i] == 0)
            break;
        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (dir_entry[j].sfd_ino == 0)
            { // 파일의 끝에 도달했을 때
                continue;
            }

            disk_read(&inode_1, dir_entry[j].sfd_ino);

            if (strcmp(dir_entry[j].sfd_name, path) == 0)
            {
                flag = 1;
                if (inode_1.sfi_type == SFS_TYPE_FILE)
                { // 디렉토리 엔트리가 파일인 경우일 때
                    error_message("cd", path, -5);
                }
                else
                { // 디렉토리 엔트리가 디렉토리인 경우일 때
                    sd_cwd.sfd_ino = dir_entry[j].sfd_ino;
                    strcpy(sd_cwd.sfd_name, path);
                }
                return;
            }
        }
    }

    if (flag == 0)
    { // 그런 파일이 없을때
        error_message("cd", path, -1);
    }
}

void sfs_ls(const char *path)
{
    //현재 상태에 있는 블록의 번호를 받아서 i-node 에 담는다.
    int i, j, k, m;
    int flag = 0; // 값이 있으면 1, 값이 없으면 0
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_inode inode_2;
    struct sfs_inode inode_3;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
    struct sfs_dir dir_entry_1[SFS_DENTRYPERBLOCK];

    // i-node 번호 받았어
    disk_read(&inode, sd_cwd.sfd_ino);

    if (path == NULL)
    { // 현재 있는 위치의 정보를 알려줄 때
        flag = 1;
        for (i = 0; i < SFS_NDIRECT; i++)
        {
            if (inode.sfi_direct[i] == 0)
                break;
            // 값이 0이 아닌 경우 - node 의 값(숫자 1개)을 읽어들여 디렉토리 엔트리(8개)를 분석
            disk_read(dir_entry, inode.sfi_direct[i]);

            //8개 파일 이름 or 디렉토리 이름 출력
            for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
            {
                if (dir_entry[j].sfd_ino == 0)
                { // 파일의 끝에 도달했을 때
                    continue;
                }

                disk_read(&inode_1, dir_entry[j].sfd_ino);

                if (inode_1.sfi_type == SFS_TYPE_FILE)
                { // 디렉토리 엔트리가 파일인 경우일 때
                    printf("%s", dir_entry[j].sfd_name);
                }
                else
                { // 디렉토리 엔트리가 디렉토리인 경우일 때
                    printf("%s/", dir_entry[j].sfd_name);
                }
                printf("\t");
            }
        }
        printf("\n");
    }
    else
    { // ls [path]인 경우 path가 어디있는지 찾아야됨
        for (i = 0; i < SFS_NDIRECT; i++)
        {
            if (inode.sfi_direct[i] == 0)
                break;

            // 값이 0이 아닌 경우 - node 의 값(숫자 1개)을 읽어들여 디렉토리 엔트리(8개)를 분석
            disk_read(dir_entry, inode.sfi_direct[i]);

            //8개 파일 이름 or 디렉토리 이름 출력
            for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
            {
                if (dir_entry[j].sfd_ino == 0)
                { // 파일의 끝에 도달했을 때
                    continue;
                }
                // dir_entry[j].sfd_name 과 path 가 같은지 확인하는 것!
                if (strcmp(dir_entry[j].sfd_name, path) == 0)
                {
                    flag = 1;
                    disk_read(&inode_1, dir_entry[j].sfd_ino);

                    if (inode_1.sfi_type == SFS_TYPE_FILE)
                    { // 찾은 것이 파일 일때
                        printf("%s\n", dir_entry[j].sfd_name);
                        return;
                    }
                    else
                    { // 찾은 것이 디렉토리 일때
                        disk_read(&inode_2, dir_entry[j].sfd_ino);

                        for (k = 0; k < SFS_NDIRECT; k++)
                        {
                            if (inode_2.sfi_direct[k] == 0)
                                break;
                            // 값이 0이 아닌 경우 - node 의 값(숫자 1개)을 읽어들여 디렉토리 엔트리(8개)를 분석
                            disk_read(dir_entry_1, inode_2.sfi_direct[k]);

                            //8개 파일 이름 or 디렉토리 이름 출력
                            for (m = 0; m < SFS_DENTRYPERBLOCK; m++)
                            {
                                if (dir_entry_1[m].sfd_ino == 0)
                                { // 파일의 끝에 도달했을 때
                                    continue;
                                }

                                disk_read(&inode_3, dir_entry_1[m].sfd_ino);

                                if (inode_3.sfi_type == SFS_TYPE_FILE)
                                { // 디렉토리 엔트리가 파일인 경우일 때
                                    printf("%s", dir_entry_1[m].sfd_name);
                                }
                                else
                                { // 디렉토리 엔트리가 디렉토리인 경우일 때
                                    printf("%s/", dir_entry_1[m].sfd_name);
                                }
                                printf("\t");
                            }
                        }
                        printf("\n");
                        return;
                    }
                }
            }
        }
    }

    if (flag == 0)
    {
        error_message("ls", path, -1);
    }
}

void sfs_mkdir(const char *org_path)
{
    int i, j, l, m, block_num;
    int flag_1 = 0;
    int flag = 0;
    int tag = 0;
    int tag_1 = 0;
    int bit_end = SFS_MAP_LOCATION + (spb.sp_nblocks / SFS_BLOCKBITS);
    char bitmap_1[512];
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
    struct sfs_dir dir_entry_1[SFS_DENTRYPERBLOCK];

    disk_read(&inode, sd_cwd.sfd_ino);
    for (i = 0; i < SFS_NDIRECT; i++)
    { // 이미 존재하는 경우 찾자
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (strcmp(dir_entry[j].sfd_name, org_path) == 0)
            { // 이미 이름이 있는 경우
                error_message("mkdir", org_path, -6);
                return;
            }
        }
    }

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (flag_1 == 1)
        {
            break;
        }
        disk_read(dir_entry, inode.sfi_direct[i]);
        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (dir_entry[j].sfd_ino == 0)
            {
                flag_1 = 1;
                break;
            }
        }
    }
    if (flag_1 == 0)
    {
        error_message("mkdir", org_path, -3);
        return;
    }

    // 비트맵으로 꽉 차 있는지 확인
    for (i = SFS_MAP_LOCATION; i <= bit_end; i++)
    { // 비트맵이 꽉 차 있는지 확인.
        disk_read(bitmap_1, i);
        for (j = 0; j < 512; j++)
        {
            if (bitmap_1[j] != -1)
            {
                tag = 1;
                break;
            }
        }
    }

    if (tag == 0)
    { // 꽉 차 있는 경우
        error_message("mkdir", org_path, -4);
        return;
    }

    for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
    { // 빈 블록 찾기 (한 개 찾기)
        if (tag_1 == 1)
        { // 하나 할당했으면
            break;
        }
        disk_read(bitmap_1, m);
        for (i = 0; i < 512; i++)
        {
            if (bitmap_1[i] != -1)
            {
                if (bitmap_1[i] == 0)
                {
                    block_num = ((m - 2) * 4096) + (8 * i);
                    bitmap_1[i] = 1;
                }
                else if (bitmap_1[i] == 1)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 1;
                    bitmap_1[i] = 3;
                }
                else if (bitmap_1[i] == 3)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 2;
                    bitmap_1[i] = 7;
                }
                else if (bitmap_1[i] == 7)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 3;
                    bitmap_1[i] = 15;
                }
                else if (bitmap_1[i] == 15)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 4;
                    bitmap_1[i] = 31;
                }
                else if (bitmap_1[i] == 31)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 5;
                    bitmap_1[i] = 63;
                }
                else if (bitmap_1[i] == 63)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 6;
                    bitmap_1[i] = 127;
                }
                else if (bitmap_1[i] == 127)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 7;
                    bitmap_1[i] = -1;
                }
                tag_1 = 1;
                disk_write(bitmap_1, m);
                break;
            }
        }
    }
    tag_1 = 0;

    //block_num이 다음에 할당 할 빈 공간

    for (l = 0; l < SFS_NDIRECT; l++)
    {
        if (flag == 1)
        {
            break;
        }

        if (inode.sfi_direct[l] == 0)
        { // 다 꽉차서 새롭게 할당해야 할 때
            // 블록 번호 비트 볼록에 추가
            int k;
            struct sfs_inode newbie;
            int index = 0;
            // 블록 추가로 2개 표시해야됨
            // 빈 블록 찾기 (두 개 찾기)
            for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
            {
                if (tag_1 == 1)
                { // 두 개 할당했으면
                    break;
                }
                disk_read(bitmap_1, m);
                for (i = 0; i < 512; i++)
                {
                    if (bitmap_1[i] != -1)
                    {
                        if (bitmap_1[i] >= 0)
                        { //0보다 크면 왼쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] << 1) | 1;
                        }
                        else
                        { // 0보다 작으면 오른쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] >> 1) | (1 << 7);
                        }
                        disk_write(bitmap_1, m);
                        tag_1 = 1;
                        break;
                    }
                }
            }
            tag_1 = 0;

            for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
            {
                if (tag_1 == 1)
                { // 두 개 할당했으면
                    break;
                }
                disk_read(bitmap_1, m);
                for (i = 0; i < 512; i++)
                {
                    if (bitmap_1[i] != -1)
                    {
                        if (bitmap_1[i] >= 0)
                        { //0보다 크면 왼쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] << 1) | 1;
                        }
                        else
                        { // 0보다 작으면 오른쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] >> 1) | (1 << 7);
                        }
                        disk_write(bitmap_1, m);
                        tag_1 = 1;
                        break;
                    }
                }
            }

            // 블록 3개를 할당해줘야한다. (1. 루트에 있는 다이렉트 블록에, 2. 디렉토리 엔트리, 3. 디렉토리 안의 블록)
            inode.sfi_direct[l] = block_num;

            for (k = 0; k < SFS_DENTRYPERBLOCK; k++)
            {
                dir_entry[k].sfd_ino = 0;
                strncpy(dir_entry[k].sfd_name, "", SFS_NAMELEN);
            }
            dir_entry[0].sfd_ino = block_num + 1;
            strncpy(dir_entry[0].sfd_name, org_path, SFS_NAMELEN);
            disk_write(dir_entry, inode.sfi_direct[l]);

            inode.sfi_size += sizeof(struct sfs_dir);
            disk_write(&inode, sd_cwd.sfd_ino);

            bzero(&newbie, SFS_BLOCKSIZE);
            newbie.sfi_size = 128;
            newbie.sfi_type = SFS_TYPE_DIR;

            newbie.sfi_direct[index] = block_num + 2;
            disk_read(dir_entry_1, newbie.sfi_direct[index]);

            for (k = 0; k < SFS_DENTRYPERBLOCK; k++)
            {
                dir_entry_1[k].sfd_ino = 0;
                strncpy(dir_entry_1[k].sfd_name, "", SFS_NAMELEN);
            }
            dir_entry_1[index].sfd_ino = block_num + 1;
            strncpy(dir_entry_1[index].sfd_name, ".", SFS_NAMELEN);

            dir_entry_1[index + 1].sfd_ino = sd_cwd.sfd_ino;
            strncpy(dir_entry_1[index + 1].sfd_name, "..", SFS_NAMELEN);

            disk_write(dir_entry_1, newbie.sfi_direct[index]);

            disk_write(&newbie, block_num + 1);
            return;
        }
        else
        { //다이렉트 엔트리의 번호가 0이 아닐 때
            //8개 파일 이름 or 디렉토리 이름 출력
            //블록 하나 추가로 할당해야돼
            for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
            {
                if (tag_1 == 1)
                { // 한 개 할당했으면
                    break;
                }
                disk_read(bitmap_1, m);
                for (i = 0; i < 512; i++)
                {
                    if (bitmap_1[i] != -1)
                    {
                        if (bitmap_1[i] >= 0)
                        { //0보다 크면 왼쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] << 1) | 1;
                        }
                        else
                        { // 0보다 작으면 오른쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] >> 1) | (1 << 7);
                        }
                        disk_write(bitmap_1, m);
                        tag_1++;
                        break;
                    }
                }
            }

            disk_read(dir_entry, inode.sfi_direct[l]);

            for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
            {
                if (strcmp(dir_entry[j].sfd_name, org_path) == 0)
                {
                    error_message("mkdir", org_path, -6);
                    return;
                }

                if (dir_entry[j].sfd_ino == 0)
                { // 빈 파일에 도달했을 때
                    //새로운 블록의 번호와 이름을 정보에 넣는다.
                    struct sfs_inode newbie;
                    int k;
                    int index = 0;
                    flag = 1;

                    dir_entry[j].sfd_ino = block_num;
                    strncpy(dir_entry[j].sfd_name, org_path, SFS_NAMELEN);
                    disk_write(dir_entry, inode.sfi_direct[l]);

                    inode.sfi_size += sizeof(struct sfs_dir);
                    disk_write(&inode, sd_cwd.sfd_ino);

                    bzero(&newbie, SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect

                    newbie.sfi_size = 128;
                    newbie.sfi_type = SFS_TYPE_DIR;

                    newbie.sfi_direct[index] = block_num + 1;

                    //디렉토리 엔트리 초기화
                    for (k = 0; k < SFS_DENTRYPERBLOCK; k++)
                    {
                        dir_entry_1[k].sfd_ino = 0;
                        strncpy(dir_entry_1[k].sfd_name, "", SFS_NAMELEN);
                    }
                    //. , .. 값 입력
                    dir_entry_1[index].sfd_ino = block_num;
                    strncpy(dir_entry_1[index].sfd_name, ".", SFS_NAMELEN);
                    dir_entry_1[index + 1].sfd_ino = sd_cwd.sfd_ino;
                    strncpy(dir_entry_1[index + 1].sfd_name, "..", SFS_NAMELEN);

                    disk_write(dir_entry_1, newbie.sfi_direct[index]);

                    disk_write(&newbie, block_num);
                    disk_write(bitmap_1, 2);
                    return;
                }
            }
        }
    }
}

void sfs_rmdir(const char *org_path)
{
    int i, j;
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    int index = 2;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
    char bitmap_1[512];
    int size_1, num_1, size_2, num_2;

    disk_read(&inode, sd_cwd.sfd_ino);

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            disk_read(&inode_1, dir_entry[j].sfd_ino);
            if (strcmp(dir_entry[j].sfd_name, org_path) == 0)
            { // 같은 이름을 찾았을 때
                if (strcmp(org_path, ".") == 0)
                {
                    error_message("rmdir", org_path, -8);
                    return;
                }

                if (inode_1.sfi_type == SFS_TYPE_FILE)
                { // 파일일때 Not a directory
                    error_message("rmdir", org_path, -5);
                }
                else
                { // 폴더일 때 (1. 전체 사이즈 줄여, 2. 지워야 할 블록 2개 (비트맵에 표시))
                    //블록 번호 dir_entry[j].sfd_ino , inode_1.sfi_direct[0] 없앤다.
                    if (inode_1.sfi_size > 128)
                    { //디렉토리가 안 비어있을 때
                        error_message("rmdir", org_path, -7);
                        return;
                    }
                    disk_read(bitmap_1, index);
                    size_1 = dir_entry[j].sfd_ino / 8; // 번호
                    num_1 = dir_entry[j].sfd_ino - (size_1 * 8);
                    if (num_1 == 7)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 127;
                    }
                    else if (num_1 == 6)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 191;
                    }
                    else if (num_1 == 5)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 223;
                    }
                    else if (num_1 == 4)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 239;
                    }
                    else if (num_1 == 3)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 247;
                    }
                    else if (num_1 == 2)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 251;
                    }
                    else if (num_1 == 1)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 253;
                    }
                    else
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 254;
                    }

                    size_2 = inode_1.sfi_direct[0] / 8; // index값
                    num_2 = inode_1.sfi_direct[0] - (size_2 * 8);
                    if (num_2 == 7)
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 127;
                    }
                    else if (num_2 == 6)
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 191;
                    }
                    else if (num_2 == 5)
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 223;
                    }
                    else if (num_2 == 4)
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 239;
                    }
                    else if (num_2 == 3)
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 247;
                    }
                    else if (num_2 == 2)
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 251;
                    }
                    else if (num_2 == 1)
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 253;
                    }
                    else
                    {
                        bitmap_1[size_2] = bitmap_1[size_2] & 254;
                    }
                    disk_write(bitmap_1, index);

                    dir_entry[j].sfd_ino = SFS_NOINO;
                    disk_write(dir_entry, inode.sfi_direct[i]);

                    inode.sfi_size -= sizeof(struct sfs_dir);
                    disk_write(&inode, sd_cwd.sfd_ino);
                }
                return;
            }
        }
    }

    //못 찾은 경우 에러!
    error_message("rmdir", org_path, -1);
}

void sfs_mv(const char *src_name, const char *dst_name)
{
    int i, j;
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];

    disk_read(&inode, sd_cwd.sfd_ino);

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (strcmp(dir_entry[j].sfd_name, dst_name) == 0)
            { // 바꾸려는 이름이 이미 존재하는 경우
                error_message("mv", dst_name, -6);
                return;
            }
        }
    }

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (strcmp(dir_entry[j].sfd_name, src_name) == 0)
            {
                strcpy(dir_entry[j].sfd_name, dst_name);
                disk_write(dir_entry, inode.sfi_direct[i]);
                disk_write(&inode, sd_cwd.sfd_ino);
                return;
            }
        }
    }

    //해당하는 파일이 없을 때
    error_message("mv", src_name, -1);
}

void sfs_rm(const char *path)
{
    int i, j, k;
    int index = 2;
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
    char bitmap_1[512];
    int size_1, num_1;

    disk_read(&inode, sd_cwd.sfd_ino);

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            disk_read(&inode_1, dir_entry[j].sfd_ino);

            if (strcmp(dir_entry[j].sfd_name, path) == 0)
            {
                if (inode_1.sfi_type == SFS_TYPE_DIR)
                { // 가리키는 것이 폴더일때
                    error_message("rm", path, -9);
                    return;
                }
                else
                { // 파일 일때
                    //dir_entry[j].sfd_ino를 비트맵으로 돌려줘, 0으로 할당
                    disk_read(bitmap_1, index);
                    size_1 = dir_entry[j].sfd_ino / 8; // index값
                    num_1 = dir_entry[j].sfd_ino - (size_1 * 8);

                    if (num_1 == 7)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 127;
                    }
                    else if (num_1 == 6)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 191;
                    }
                    else if (num_1 == 5)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 223;
                    }
                    else if (num_1 == 4)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 239;
                    }
                    else if (num_1 == 3)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 247;
                    }
                    else if (num_1 == 2)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 251;
                    }
                    else if (num_1 == 1)
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 253;
                    }
                    else
                    {
                        bitmap_1[size_1] = bitmap_1[size_1] & 254;
                    }

                    for (k = 0; k < SFS_NDIRECT; k++)
                    { // 다이렉트 포인터에 있는 값
                        if (inode_1.sfi_direct[k] == 0)
                            break;
                        else
                        {
                            size_1 = inode_1.sfi_direct[k] / 8; // index값
                            num_1 = inode_1.sfi_direct[k] - (size_1 * 8);
                            if (num_1 == 7)
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 127;
                            }
                            else if (num_1 == 6)
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 191;
                            }
                            else if (num_1 == 5)
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 223;
                            }
                            else if (num_1 == 4)
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 239;
                            }
                            else if (num_1 == 3)
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 247;
                            }
                            else if (num_1 == 2)
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 251;
                            }
                            else if (num_1 == 1)
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 253;
                            }
                            else
                            {
                                bitmap_1[size_1] = bitmap_1[size_1] & 254;
                            }
                        }
                    }

                    dir_entry[j].sfd_ino = SFS_NOINO;
                    disk_write(dir_entry, inode.sfi_direct[i]);

                    inode.sfi_size -= sizeof(struct sfs_dir);
                    disk_write(&inode, sd_cwd.sfd_ino);
                    disk_write(bitmap_1, index);
                    return;
                }
            }
        }
    }

    error_message("rm", path, -1);
}

void sfs_cpin(const char *local_path, const char *path)
{ // local_path 새로운 파일로 복사, path : 파일 시스템에 존재
    off_t len;
    int kd, i, j, l, block_num, m, size_1, num_1, temp;
    int tag_1 = 0;
    u_int32_t num_indirect[128];
    char buf[512];
    int index_last;
    int bit_end = SFS_MAP_LOCATION + (spb.sp_nblocks / SFS_BLOCKBITS);
    int tag = 0;
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_inode newbie;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
    char bitmap_1[512];

    //kd 파일 디스크립터
    if ((kd = open(path, O_RDONLY)) < 0)
    { //파일 읽기 실패 했을 경우
        error_message("cpin", path, -11);
        return;
    }
    // 크기 받아온다.
    len = lseek(kd, 0, SEEK_END);

    if (len > (128 + 15) * 512)
    { // 허용되는 파일의 사이즈를 넘어가는 경우
        printf("cpin: input file size exceeds the max file size\n");
        return;
    }

    disk_read(&inode, sd_cwd.sfd_ino);
    //이미 파일이 존재하는지 확인
    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (strcmp(dir_entry[j].sfd_name, local_path) == 0)
            {
                error_message("cpin", local_path, -6);
                return;
            }
        }
    }
    // 비트맵으로 꽉 차 있는지 확인
    for (i = SFS_MAP_LOCATION; i <= bit_end; i++)
    { // 비트맵이 꽉 차 있는지 확인.
        disk_read(bitmap_1, i);
        for (j = 0; j < 512; j++)
        {
            if (bitmap_1[j] != -1)
            {
                tag = 1;
                break;
            }
        }
    }

    if (tag == 0)
    { // 꽉 차 있는 경우
        error_message("cpin", local_path, -4);
        return;
    }

    //블록 넘버를 구하자
    for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
    { // 빈 블록 찾기
        if (tag_1 == 1)
        {
            break;
        }
        disk_read(bitmap_1, m);
        for (i = 0; i < 512; i++)
        {
            if (bitmap_1[i] != -1)
            {
                if (bitmap_1[i] == 0)
                {
                    block_num = ((m - 2) * 4096) + (8 * i);
                }
                else if (bitmap_1[i] == 1)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 1;
                }
                else if (bitmap_1[i] == 3)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 2;
                }
                else if (bitmap_1[i] == 7)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 3;
                }
                else if (bitmap_1[i] == 15)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 4;
                }
                else if (bitmap_1[i] == 31)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 5;
                }
                else if (bitmap_1[i] == 63)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 6;
                }
                else if (bitmap_1[i] == 127)
                {
                    block_num = ((m - 2) * 4096) + (8 * i) + 7;
                }
                tag_1 = 1;
                break;
            }
        }
    }
    tag_1 = 0;

    // 파일의 길이: len 길이 할당하자.
    for (l = 0; l < SFS_NDIRECT; l++)
    {
        if (tag_1 == 1)
        {
            break;
        }

        if (inode.sfi_direct[l] == 0)
        { // 새롭게 할당해야 할 때, 블록 하나 더 필요하다.
            //하나 할당.
            int k;
            for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
            {
                if (tag_1 == 1)
                {
                    break;
                }
                disk_read(bitmap_1, m);
                for (i = 0; i < 512; i++)
                {
                    if (bitmap_1[i] != -1)
                    {
                        if (bitmap_1[i] >= 0)
                        { //0보다 크면 왼쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] << 1) | 1;
                        }
                        else
                        { // 0보다 작으면 오른쪽으로 한 칸 이동
                            bitmap_1[i] = (bitmap_1[i] >> 1) | (1 << 7);
                        }
                        disk_write(bitmap_1, m);
                        tag_1 = 1;
                        break;
                    }
                }
            }
            tag_1 = 0;

            inode.sfi_direct[l] = block_num++;
            for (k = 0; k < SFS_DENTRYPERBLOCK; k++)
            {
                dir_entry[k].sfd_ino = 0;
                strncpy(dir_entry[k].sfd_name, "", SFS_NAMELEN);
            }
            dir_entry[0].sfd_ino = block_num;
            strncpy(dir_entry[0].sfd_name, local_path, SFS_NAMELEN);
            disk_write(dir_entry, inode.sfi_direct[l]);

            inode.sfi_size += sizeof(struct sfs_dir);
            disk_write(&inode, sd_cwd.sfd_ino);

            bzero(&newbie, SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect
            newbie.sfi_size = len;         // 사이즈보다 작으면 뒤에서 수정
            newbie.sfi_type = SFS_TYPE_FILE;
            for (i = 0; i < SFS_NDIRECT; i++)
            {
                newbie.sfi_direct[i] = (block_num + 1) + i;
            }
            newbie.sfi_indirect = (block_num + 1) + SFS_NDIRECT;
            disk_write(&newbie, block_num);
            tag_1 = 1;
            break;
        }
        else
        { //블록을 새롭게 할당하지 않아도 될 때
            disk_read(dir_entry, inode.sfi_direct[l]);

            for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
            {
                if (dir_entry[j].sfd_ino == 0)
                { // 빈 파일에 도달했을 때 ( 다이렉트 블록이랑 인 다이렉트 블록에 할당하자)

                    dir_entry[j].sfd_ino = block_num;
                    strncpy(dir_entry[j].sfd_name, local_path, SFS_NAMELEN);
                    disk_write(dir_entry, inode.sfi_direct[l]);

                    inode.sfi_size += sizeof(struct sfs_dir);
                    disk_write(&inode, sd_cwd.sfd_ino);

                    bzero(&newbie, SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect
                    newbie.sfi_size = len;         // 사이즈보다 작으면 뒤에서 수정
                    newbie.sfi_type = SFS_TYPE_FILE;
                    for (i = 0; i < SFS_NDIRECT; i++)
                    {
                        newbie.sfi_direct[i] = (block_num + 1) + i;
                    }
                    newbie.sfi_indirect = (block_num + 1) + SFS_NDIRECT;
                    disk_write(&newbie, block_num);
                    tag_1 = 1;
                    break;
                }
            }
        }
    }

    lseek(kd, 0, SEEK_SET);

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        //newbie.sfi_direct[i] = (block_num + 1) + i;
        read(kd, buf, SFS_BLOCKSIZE);
        disk_write(buf, (block_num + 1) + i);
    }

    //비트맵 다 차지 않았을 때 newbie.sfi_size 수정,
    //파일 디스크립터 kd에 write, block_num~ index_last 까지
    index_last = block_num + (len / SFS_BLOCKSIZE + 3);
    temp = block_num;
    while (temp <= index_last)
    { // 해당하는 block_num을 bitmap에서 1로 해준다.
        // bitmap이 꽉찼을 때 len 수정
        //꽉찼을 때

        for (i = SFS_MAP_LOCATION; i <= bit_end; i++)
        { // 비트맵이 꽉 차 있는지 확인.
            disk_read(bitmap_1, i);
            for (j = 0; j < 512; j++)
            {
                if (bitmap_1[j] != -1)
                {
                    tag = 1;
                    break;
                }
            }
        }
        if (tag == 0)
        { // 꽉 차 있는 경우
            newbie.sfi_size = (temp - block_num - 3) * SFS_BLOCKSIZE;
            for (i = 0; i < 128; i++)
            {
                num_indirect[i] = 0;
            }
            for (i = 0; i < (temp - 1) - newbie.sfi_indirect - 1; i++)
            {
                num_indirect[i] = newbie.sfi_indirect + 1 + i;
                read(kd, buf, SFS_BLOCKSIZE);
                disk_write(buf, newbie.sfi_indirect + 1 + i);
            }
            disk_write(num_indirect, newbie.sfi_indirect);
            disk_write(&newbie, block_num);
            error_message("cpin", local_path, -4);
            close(kd);
            return;
        }
        tag = 0;

        //하나 할당
        for (m = SFS_MAP_LOCATION; m <= bit_end; m++)
        {
            if (tag_1 == 1)
            {
                break;
            }
            disk_read(bitmap_1, m);
            for (i = 0; i < 512; i++)
            {
                if (bitmap_1[i] != -1)
                {
                    if (bitmap_1[i] >= 0)
                    { //0보다 크면 왼쪽으로 한 칸 이동
                        bitmap_1[i] = (bitmap_1[i] << 1) | 1;
                    }
                    else
                    { // 0보다 작으면 오른쪽으로 한 칸 이동
                        bitmap_1[i] = (bitmap_1[i] >> 1) | (1 << 7);
                    }
                    disk_write(bitmap_1, m);
                    tag_1 = 1;
                    break;
                }
            }
        }
        tag_1 = 0;
        temp++;
    }

    for (i = 0; i < 128; i++)
    {
        num_indirect[i] = 0;
    }
    for (i = 0; i < (temp - 1) - newbie.sfi_indirect - 1; i++)
    {
        num_indirect[i] = newbie.sfi_indirect + 1 + i;
        if (i == ((temp - 1) - newbie.sfi_indirect - 2))
        {

            read(kd, buf, len % SFS_BLOCKSIZE);
        }
        else
        {

            read(kd, buf, SFS_BLOCKSIZE);
        }

        disk_write(buf, newbie.sfi_indirect + 1 + i);
    }
    disk_write(num_indirect, newbie.sfi_indirect);
    disk_write(&newbie, block_num);
    close(kd);
}

void sfs_cpout(const char *local_path, const char *path)
{
    //Already exists(path에 파일이 있을 때)
    //no such file or directory (그런 파일이 local에 없을 때)
    int i, j, k, kd;
    int num;
    struct sfs_inode inode;
    struct sfs_inode inode_1;
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
    char buf[512];
    u_int32_t num_indirect[128];

    if ((kd = open(path, O_RDONLY)) > 0)
    { // 파일 읽기 성공 -> Already exists
        error_message("cpout", path, -6);
        return;
    }

    disk_read(&inode, sd_cwd.sfd_ino);

    for (i = 0; i < SFS_NDIRECT; i++)
    {
        if (inode.sfi_direct[i] == 0)
            break;

        disk_read(dir_entry, inode.sfi_direct[i]);

        for (j = 0; j < SFS_DENTRYPERBLOCK; j++)
        {
            if (strcmp(dir_entry[j].sfd_name, local_path) == 0)
            { // 같은 파일을 찾았을 때-> 밖에다 써주자
                disk_read(&inode_1, dir_entry[j].sfd_ino);
                kd = open(path, O_RDWR | O_APPEND | O_CREAT, 0666);
                for (k = 0; k < SFS_NDIRECT; k++)
                { // 다이렉트 포인터에 있는 것 쓰기
                    disk_read(buf, inode_1.sfi_direct[k]);
                    write(kd, buf, sizeof(buf));
                }

                disk_read(num_indirect, inode_1.sfi_indirect);

                for (k = 0; k < SFS_DBPERIDB; k++)
                {
                    if (num_indirect[k] == 0)
                    {
                        num = k;
                        break;
                    }
                }

                for (k = 0; k < SFS_DBPERIDB; k++)
                {
                    if (num_indirect[k] != 0)
                    {
                        if (k == num - 1)
                        {
                            disk_read(buf, num_indirect[k]);
                            write(kd, buf, inode_1.sfi_size % SFS_BLOCKSIZE);
                        }
                        else
                        {
                            disk_read(buf, num_indirect[k]);
                            write(kd, buf, sizeof(buf));
                        }
                    }
                }
                close(kd);
                return;
            }
        }
    }

    //그런 파일이 local 에 없을 때
    error_message("cpout", local_path, -1);
}

//current working directory의 번호 받아왔어
//  i-node의 정보를 가지고 다루기
void dump_inode(struct sfs_inode inode)
{
    int i;
    // 배열의 크기 8인 것. ( 디렉토리 엔트리 )- 한 개의 데이터 블록에 해당되는 것
    struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];

    // i-node의 사이즈와 어떤 타입인지 출력
    printf("size %d type %d direct ", inode.sfi_size, inode.sfi_type);

    // i-node의 다이렉트 포인터의 값을 출력한다.
    for (i = 0; i < SFS_NDIRECT; i++)
    {
        printf(" %d ", inode.sfi_direct[i]);
    }

    // i-node의 인 다이렉트 포인터의 값을 출력한다.
    printf(" indirect %d", inode.sfi_indirect);
    printf("\n");

    // type 이 SFS_TYPE_DIR 일 때
    if (inode.sfi_type == SFS_TYPE_DIR)
    {
        for (i = 0; i < SFS_NDIRECT; i++)
        {
            // 값이 0이라는 것은 node에 값이 없다는 뜻이다.
            if (inode.sfi_direct[i] == 0)
                break;
            // 값이 0이 아닌 경우 - node 의 값(숫자 1개)을 읽어들여 디렉토리 엔트리(8개)를 분석
            disk_read(dir_entry, inode.sfi_direct[i]);
            //받은 dir_entry(8개 있는 것)을 dump_directory!
            dump_directory(dir_entry);
        }
    }
}

void dump_directory(struct sfs_dir dir_entry[])
{
    int i;
    struct sfs_inode inode;

    // for 문을 통해 8번 실행
    for (i = 0; i < SFS_DENTRYPERBLOCK; i++)
    {
        //디렉토리 엔트리의 번호랑 이름
        printf("%d %s\n", dir_entry[i].sfd_ino, dir_entry[i].sfd_name);
        disk_read(&inode, dir_entry[i].sfd_ino);

        // 디렉토리 엔트리가 파일인 경우일 때
        if (inode.sfi_type == SFS_TYPE_FILE)
        {
            printf("\t");
            dump_inode(inode);
        }
    }
}

void sfs_dump()
{
    // dump the current directory structure
    struct sfs_inode c_inode;

    // 블록의 번호를 받는다. ( current working directory에서 정보 받아오기 )
    disk_read(&c_inode, sd_cwd.sfd_ino);
    //current working directory의 정보 print 해주기
    printf("cwd inode %d name %s\n", sd_cwd.sfd_ino, sd_cwd.sfd_name);
    // current working directory의 번호를 가지고 dump_inode ( 정보 출력하려고 )
    dump_inode(c_inode);
    printf("\n");
}
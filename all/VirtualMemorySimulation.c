//
// Virual Memory Simulator Homework
// One-level page table system with FIFO and LRU
// Two-level page table system with LRU
// Inverted page table with a hashing system
// Submission Year:
// Student Name: 김정천
// Student Number: B611045
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#define PAGESIZEBITS 12    // page size = 4Kbytes
#define VIRTUALADDRBITS 32 // virtual address space size = 4Gbytes

int numProcess;

struct procEntry
{
    char *traceName;          // the memory trace name
    int pid;                  // process (trace) id
    int ntraces;              // the number of memory traces
    int num2ndLevelPageTable; // The 2nd level page created(allocated);
    int numIHTConflictAccess; // The number of Inverted Hash Table Conflict Accesses
    int numIHTNULLAccess;     // The number of Empty Inverted Hash Table Accesses
    int numIHTNonNULLAcess;   // The number of Non Empty Inverted Hash Table Accesses
    int numPageFault;         // The number of page faults
    int numPageHit;           // The number of page hits
    struct pageTableEntry *firstLevelPageTable;
    FILE *tracefp;
} * procTable;

struct pageTableEntry
{                //firstlevelPageTable의 구조체이다.
    int in_data; //2차 테이블에 데이터가 있는지 ( 2차 테이블 개수 세어주려고 )
};

struct physicalMemory
{
    int in_data; // 데이터가 안에 있는지
    int p_id;    //연결된 프로세스 id
    int count;
    unsigned vt_page_num; // 연결된 virtual page number
} * pmTable;

struct HashTable
{
    int p_id;
    unsigned vt_page_num;
    unsigned page_frame;
    struct HashTable *next;
} * hashTable;

void oneLevelVMSim()
{
    int i;
    for (i = 0; i < numProcess; i++)
    {
        printf("**** %s *****\n", procTable[i].traceName);
        printf("Proc %d Num of traces %d\n", i, procTable[i].ntraces);
        printf("Proc %d Num of Page Faults %d\n", i, procTable[i].numPageFault);
        printf("Proc %d Num of Page Hit %d\n", i, procTable[i].numPageHit);
        assert(procTable[i].numPageHit + procTable[i].numPageFault == procTable[i].ntraces);
    }
}

void oneLevelfifo(int num_frame)
{
    //procTable[i].tracefp = fopen(argv[i + 4], "r");
    int trace_num = 0;
    int num_table = 0;
    int k = 0;
    int x;

    while (!feof(procTable[num_table].tracefp))
    {
        unsigned addr, addr1, addr2;
        char rw;
        int i = 0;
        fscanf(procTable[num_table].tracefp, "%x %c\n", &addr, &rw);
        addr1 = addr / (1 << PAGESIZEBITS); // virtual page number
        addr2 = addr % (1 << PAGESIZEBITS); // offset
        if (num_table == 0)
            trace_num++;
        while (1)
        {
            if (i == num_frame)
            { // FIFO의 경우 프레임의 제일 앞의 것을 replace 해준다.
                pmTable[k % num_frame].vt_page_num = addr1;
                pmTable[k % num_frame].p_id = num_table;
                procTable[num_table].numPageFault++;
                addr2 = addr2 + (k % num_frame) * (1 << PAGESIZEBITS);
                k++;
                break;
            }

            if (pmTable[i].in_data == 0)
            {
                pmTable[i].vt_page_num = addr1;
                pmTable[i].in_data = 1;
                pmTable[i].p_id = num_table;
                procTable[num_table].numPageFault++;
                addr2 = addr2 + i * (1 << PAGESIZEBITS);
                break;
            }

            if (pmTable[i].vt_page_num == addr1 && pmTable[i].p_id == num_table)
            {
                procTable[num_table].numPageHit++;
                addr2 = addr2 + i * (1 << PAGESIZEBITS);
                break;
            }

            i++;
        }
        procTable[num_table].ntraces = trace_num;
        num_table = (num_table + 1) % numProcess;
    }
    for (x = 0; x < numProcess; x++)
    {
        fclose(procTable[x].tracefp);
    }
}

void oneLevelLRU(int num_frame)
{
    //procTable[i].tracefp = fopen(argv[i + 4], "r");
    int trace_num = 0;
    int num_table = 0;
    int x; // fclose할때 필요한 변수
    int count_num = 1;

    while (!feof(procTable[num_table].tracefp))
    {
        unsigned addr, addr1, addr2;
        char rw;
        int i = 0;
        fscanf(procTable[num_table].tracefp, "%x %c\n", &addr, &rw);
        addr1 = addr / (1 << PAGESIZEBITS); // virtual page number
        addr2 = addr % (1 << PAGESIZEBITS); // offset
        if (num_table == 0)
            trace_num++;
        while (1)
        {
            if (i == num_frame)
            {
                //count의 값이 제일 작은 것을 replace 해주고 count값 최신화 시켜준다.
                int index = 0; // count 값 최소인 pmTable index
                int min = count_num;
                int y;
                for (y = 0; y < num_frame; y++)
                {
                    if (pmTable[y].count < min)
                    {
                        min = pmTable[y].count;
                        index = y;
                    }
                }
                pmTable[index].count = count_num++;
                pmTable[index].vt_page_num = addr1;
                pmTable[index].p_id = num_table;
                addr2 = addr2 + i * (1 << PAGESIZEBITS);
                procTable[num_table].numPageFault++;
                break;
            }

            if (pmTable[i].in_data == 0)
            {
                pmTable[i].vt_page_num = addr1;
                pmTable[i].in_data = 1;
                pmTable[i].p_id = num_table;
                pmTable[i].count = count_num++;
                procTable[num_table].numPageFault++;
                addr2 = addr2 + i * (1 << PAGESIZEBITS);
                break;
            }

            if (pmTable[i].vt_page_num == addr1 && pmTable[i].p_id == num_table)
            {
                procTable[num_table].numPageHit++;
                pmTable[i].count = count_num++;
                addr2 = addr2 + i * (1 << PAGESIZEBITS);
                break;
            }

            i++;
        }
        procTable[num_table].ntraces = trace_num;
        num_table = (num_table + 1) % numProcess;
    }
    for (x = 0; x < numProcess; x++)
    {
        fclose(procTable[x].tracefp);
    }
}

void twoLevelVMSim()
{
    int i;
    for (i = 0; i < numProcess; i++)
    {
        printf("**** %s *****\n", procTable[i].traceName);
        printf("Proc %d Num of traces %d\n", i, procTable[i].ntraces);
        printf("Proc %d Num of second level page tables allocated %d\n", i, procTable[i].num2ndLevelPageTable);
        printf("Proc %d Num of Page Faults %d\n", i, procTable[i].numPageFault);
        printf("Proc %d Num of Page Hit %d\n", i, procTable[i].numPageHit);
        assert(procTable[i].numPageHit + procTable[i].numPageFault == procTable[i].ntraces);
    }
}

void twolevelLRU(int first_level_bit, int num_frame)
{
    //procTable[i].tracefp = fopen(argv[i + 4], "r");
    int trace_num = 0;
    int num_table = 0;
    int x;
    int count_num = 1;
    int second_level_bit = VIRTUALADDRBITS - (PAGESIZEBITS + first_level_bit);

    while (!feof(procTable[num_table].tracefp))
    {
        unsigned addr, addr1, addr2, addr3, addr4;
        char rw;
        int i = 0;
        fscanf(procTable[num_table].tracefp, "%x %c\n", &addr, &rw);
        addr1 = addr / (1 << PAGESIZEBITS);      // virtual page number(first level + second level)
        addr2 = addr1 / (1 << second_level_bit); // first level bit
        addr3 = addr1 % (1 << second_level_bit); // second level bit
        addr4 = addr % (1 << PAGESIZEBITS);      // offset

        if (num_table == 0)
            trace_num++;

        while (1)
        {
            if (i == num_frame)
            {                  // physical frame 중에 count 값 제일 낮은 것 replace 해준다.
                int index = 0; // count 값 최소인 pmTable index
                int min = count_num;
                int y;
                for (y = 0; y < num_frame; y++)
                {
                    if (pmTable[y].count < min)
                    {
                        min = pmTable[y].count;
                        index = y;
                    }
                }

                if (procTable[num_table].firstLevelPageTable[addr2].in_data == 0)
                { // 2차 테이블이 만들어지기 전 일때, 2차 테이블 만들고 개수 하나 올려준다.
                    procTable[num_table].firstLevelPageTable[addr2].in_data = 1;
                    procTable[num_table].num2ndLevelPageTable++;
                }

                pmTable[index].count = count_num++;
                pmTable[index].vt_page_num = addr1;
                pmTable[index].p_id = num_table;
                procTable[num_table].numPageFault++;
                addr4 = addr4 + i * (1 << PAGESIZEBITS);
                break;
            }

            if (pmTable[i].in_data == 0)
            {                                   //physical process가 비어있을 때 값을 넣어주면 됨.
                pmTable[i].vt_page_num = addr1; // virtual page number 를 넣어준다.

                if (procTable[num_table].firstLevelPageTable[addr2].in_data == 0)
                { // 2차 테이블이 만들어지기 전 일때, 2차 테이블 만들고 개수 하나 올려준다.
                    procTable[num_table].firstLevelPageTable[addr2].in_data = 1;
                    procTable[num_table].num2ndLevelPageTable++;
                }

                pmTable[i].in_data = 1;
                pmTable[i].p_id = num_table;
                pmTable[i].count = count_num++;
                procTable[num_table].numPageFault++;
                addr4 = addr4 + i * (1 << PAGESIZEBITS);
                break;
            }

            if (pmTable[i].vt_page_num == addr1 && pmTable[i].p_id == num_table)
            { // hit의 경우
                procTable[num_table].numPageHit++;
                pmTable[i].count = count_num++; // 우선순위를 높여야돼
                addr4 = addr4 + i * (1 << PAGESIZEBITS);
                break;
            }

            i++;
        }
        procTable[num_table].ntraces = trace_num;
        num_table = (num_table + 1) % numProcess;
    }
    for (x = 0; x < numProcess; x++)
    {
        fclose(procTable[x].tracefp);
    }
}

void InvertedPageSystem(int num_frame)
{
    //procTable[i].tracefp = fopen(argv[i + 4], "r");
    int trace_num = 0;
    int num_table = 0;
    int x; // fclose할때 필요한 변수
    int count_num = 1;
    int i = 0;

    while (!feof(procTable[num_table].tracefp))
    {
        unsigned addr, addr1, addr2;
        int hash_index;
        char rw;

        fscanf(procTable[num_table].tracefp, "%x %c\n", &addr, &rw);
        addr1 = addr / (1 << PAGESIZEBITS); // virtual page number
        addr2 = addr % (1 << PAGESIZEBITS); // offset
        //hash index 값을 계산한다.
        hash_index = (addr1 + num_table) % num_frame;

        if (num_table == 0)
            trace_num++;

        //헤시테이블이 빈 곳인지 확인한다.
        if (hashTable[hash_index].next == NULL)
        { //해시 테이블이 빈 곳 일때 -> pagefault, numIHTNULLAccess 늘어난다.
            struct HashTable *node1 = malloc(sizeof(struct HashTable));
            procTable[num_table].numIHTNULLAccess++;
            procTable[num_table].numPageFault++;
            node1->p_id = num_table;
            node1->vt_page_num = addr1;

            //page frame의 위치 정해야돼(physical memory 꽉 찼을 때, 차지 않았을 때)
            if (i < num_frame)
            { //physical memory 꽉 차지 않았을 때
                node1->page_frame = i;
                pmTable[i].count = count_num++;
                pmTable[i].p_id = num_table;
                pmTable[i].vt_page_num = addr1;
                hashTable[hash_index].next = node1;
                i++;
            }
            else
            { //physical memory 꽉 찼을 경우이다. -> count 중 가장 작은 것을 replace 해준다.
                //hash 테이블 위치에 있는 값도 제거해준다.
                int index = 0; // count 값 최소인 pmTable index
                int n_time = 0;
                int delete_hash_index;
                struct HashTable *delete_node = malloc(sizeof(struct HashTable));
                struct HashTable *prev_node = malloc(sizeof(struct HashTable));
                int min = count_num;
                int y;
                for (y = 0; y < num_frame; y++)
                {
                    if (pmTable[y].count < min)
                    {
                        min = pmTable[y].count;
                        index = y;
                    }
                }
                // count 값이 제일 작은 것으로 replace 해준다.
                node1->page_frame = index;
                hashTable[hash_index].next = node1;
                // physical memory에 지정된 노드를 삭제시켜준다.
                // pmTable[index].p_id, pmTable[index].vt_page_num, index
                delete_hash_index = (pmTable[index].p_id + pmTable[index].vt_page_num) % num_frame;
                delete_node = hashTable[delete_hash_index].next;

                while (1)
                {

                    if ((delete_node->vt_page_num == pmTable[index].vt_page_num) && (delete_node->p_id == pmTable[index].p_id))
                    { // pmTable의 정보와 같으면 삭제시켜준다.
                        if (n_time == 0)
                        { //바로 처음의 경우
                            hashTable[delete_hash_index].next = delete_node->next;
                        }
                        else
                        { //중간에 있을 경우
                            prev_node->next = delete_node->next;
                        }

                        break;
                    }
                    else
                    { //pmTable의 정보와 다르면
                        prev_node = delete_node;
                        delete_node = delete_node->next;
                    }
                    n_time++;
                }

                //새로 넣어준 값으로 변경해준다.
                pmTable[index].count = count_num++;
                pmTable[index].vt_page_num = addr1;
                pmTable[index].p_id = num_table;
            }
        }
        else
        {
            // 해시테이블이 빈 곳이 아닐 경우
            int is_check = 0;
            struct HashTable *check_node = malloc(sizeof(struct HashTable));

            check_node = hashTable[hash_index].next;

            procTable[num_table].numIHTNonNULLAcess++; // 헤시 테이블 빈 곳 아닌 곳 접근
            //hash_index
            //검사했을 때 있는 경우 ( hit )
            while (check_node != NULL)
            {
                procTable[num_table].numIHTConflictAccess++;
                if ((check_node->vt_page_num == addr1) && (check_node->p_id == num_table))
                {
                    procTable[num_table].numPageHit++;
                    pmTable[check_node->page_frame].count = count_num++;
                    is_check = 1;
                    break;
                }
                else
                {
                    check_node = check_node->next;
                }
            }

            //검사했을 때 없는 경우 ( fault ) -> 노드 앞에 추가
            //physical memory 꽉 찼을 때, 비었을 때
            if (is_check == 0)
            {
                struct HashTable *node2 = malloc(sizeof(struct HashTable));
                node2->p_id = num_table;
                node2->vt_page_num = addr1;
                procTable[num_table].numPageFault++;

                if (i < num_frame)
                { //physical memory 비었을 때
                    node2->page_frame = i;
                    pmTable[i].count = count_num++;
                    pmTable[i].p_id = num_table;
                    pmTable[i].vt_page_num = addr1;
                    node2->next = hashTable[hash_index].next;
                    hashTable[hash_index].next = node2;
                    i++;
                }
                else
                { //physical memory 꽉 찼을 때
                    int index = 0;
                    int n_time = 0;
                    int delete_hash_index;
                    struct HashTable *delete_node = malloc(sizeof(struct HashTable));
                    struct HashTable *prev_node = malloc(sizeof(struct HashTable));
                    int min = count_num;
                    int y;
                    for (y = 0; y < num_frame; y++)
                    {
                        if (pmTable[y].count < min)
                        {
                            min = pmTable[y].count;
                            index = y;
                        }
                    }
                    node2->page_frame = index;
                    node2->next = hashTable[hash_index].next;
                    hashTable[hash_index].next = node2;

                    // 지정된 노드를 삭제시켜준다.
                    delete_hash_index = (pmTable[index].p_id + pmTable[index].vt_page_num) % num_frame;
                    delete_node = hashTable[delete_hash_index].next;

                    while (1)
                    {

                        if ((delete_node->vt_page_num == pmTable[index].vt_page_num) && (delete_node->p_id == pmTable[index].p_id))
                        { // pmTable의 정보와 같으면 삭제시켜준다.
                            if (n_time == 0)
                            { //바로 처음의 경우
                                hashTable[delete_hash_index].next = delete_node->next;
                            }
                            else
                            { //중간에 있을 경우
                                prev_node->next = delete_node->next;
                            }

                            break;
                        }
                        else
                        { //pmTable의 정보와 다르면
                            prev_node = delete_node;
                            delete_node = delete_node->next;
                        }
                        n_time++;
                    }

                    //새로 넣어준 값으로 변경해준다.
                    pmTable[index].count = count_num++;
                    pmTable[index].vt_page_num = addr1;
                    pmTable[index].p_id = num_table;
                }
            }
        }

        procTable[num_table].ntraces = trace_num;
        num_table = (num_table + 1) % numProcess;
    }

    for (x = 0; x < numProcess; x++)
    {
        fclose(procTable[x].tracefp);
    }
}

void invertedPageVMSim()
{
    int i;
    for (i = 0; i < numProcess; i++)
    {
        printf("**** %s *****\n", procTable[i].traceName);
        printf("Proc %d Num of traces %d\n", i, procTable[i].ntraces);
        printf("Proc %d Num of Inverted Hash Table Access Conflicts %d\n", i, procTable[i].numIHTConflictAccess);
        printf("Proc %d Num of Empty Inverted Hash Table Access %d\n", i, procTable[i].numIHTNULLAccess);
        printf("Proc %d Num of Non-Empty Inverted Hash Table Access %d\n", i, procTable[i].numIHTNonNULLAcess);
        printf("Proc %d Num of Page Faults %d\n", i, procTable[i].numPageFault);
        printf("Proc %d Num of Page Hit %d\n", i, procTable[i].numPageHit);
        assert(procTable[i].numPageHit + procTable[i].numPageFault == procTable[i].ntraces);
        assert(procTable[i].numIHTNULLAccess + procTable[i].numIHTNonNULLAcess == procTable[i].ntraces);
    }
}

int main(int argc, char *argv[])
{
    int i, c, simType, firstLevelBits;
    //number of Frames , phsical memory size
    int nFrame, phyMemSizeBits;

    phyMemSizeBits = atoi(argv[3]);                // 문자열을 정수로 변환.
    nFrame = 1 << (phyMemSizeBits - PAGESIZEBITS); // 제곱수로 바꿀 때
    numProcess = argc - 4;
    simType = atoi(argv[1]);
    firstLevelBits = atoi(argv[2]);

    // procTable 동적 선언하였다. (프로세스 개수만큼 procTable 선언)
    procTable = (struct procEntry *)malloc(sizeof(struct procEntry) * numProcess);
    pmTable = (struct physicalMemory *)malloc(sizeof(struct physicalMemory) * nFrame);
    hashTable = (struct HashTable *)malloc(sizeof(struct HashTable) * nFrame);

    // initialize procTable for Memory Simulations
    for (i = 0; i < numProcess; i++)
    {
        // opening a tracefile for the process
        printf("process %d opening %s\n", i, argv[i + 4]);
        procTable[i].traceName = argv[i + 4];
        procTable[i].tracefp = fopen(argv[i + 4], "r");
        procTable[i].pid = i;
        if (procTable[i].tracefp == NULL)
        { //파일이 없는 경우 NULL 반환
            printf("ERROR: can't open %s file; exiting...", argv[i + 4]);
            exit(1);
        }
    }

    printf("Num of Frames %d Physical Memory Size %ld bytes\n", nFrame, (1L << phyMemSizeBits));

    if (simType == 0)
    {
        printf("=============================================================\n");
        printf("The One-Level Page Table with FIFO Memory Simulation Starts .....\n");
        printf("=============================================================\n");
        oneLevelfifo(nFrame);
        oneLevelVMSim();
    }

    if (simType == 1)
    {
        printf("=============================================================\n");
        printf("The One-Level Page Table with LRU Memory Simulation Starts .....\n");
        printf("=============================================================\n");
        oneLevelLRU(nFrame);
        oneLevelVMSim();
    }

    if (simType == 2)
    {
        int y;
        for (y = 0; y < numProcess; y++)
        { //firstlevelbit만큼 할당
            procTable[y].firstLevelPageTable = (struct pageTableEntry *)malloc(sizeof(struct pageTableEntry) * (1 << firstLevelBits));
        }
        printf("=============================================================\n");
        printf("The Two-Level Page Table Memory Simulation Starts .....\n");
        printf("=============================================================\n");
        twolevelLRU(firstLevelBits, nFrame);
        twoLevelVMSim();
    }

    if (simType == 3)
    {

        printf("=============================================================\n");
        printf("The Inverted Page Table Memory Simulation Starts .....\n");
        printf("=============================================================\n");
        InvertedPageSystem(nFrame);
        invertedPageVMSim();
    }

    return (0);
}

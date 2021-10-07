#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    vector<char> arr(name.size(),'A');
    int answer=0;
    answer+= min(name[0]-arr[0], 1+'Z'-name[0]);
    arr[0]=name[0];
    
    int current_index=0;
    int left_index=0;
    int right_index=0;
    while(true){
        // 왼쪽이 더 가까운지 오른쪽이 더 가까운지 
        left_index=current_index-1;
        right_index=current_index+1;
        
        bool is_true = true;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=name[i]){
                is_true=false;
            }
        }
        if(is_true==true){
            break;
        }
        
        int left_cnt=1;
        while(current_index!=left_index){
            if(left_index<0){
                left_index=name.length()-1;
            }
            
            if(arr[left_index]!=name[left_index]){
                break;
            }    
            else{
                left_index--;
            }
            left_cnt++;
        }
        
        int right_cnt=1;
        while(current_index!=right_index){
            if(right_index==name.length()){
                right_index=0;
            }
            
            if(arr[right_index]!=name[right_index]){
                break;
            }    
            else{
                right_index++;
            }
            right_cnt++;
        }
        if(right_cnt>left_cnt){
            current_index=left_index;
        }
        else{
            current_index=right_index;
        }
        
        answer+=min(right_cnt,left_cnt);
        
        answer+= min(name[current_index]-arr[current_index], 1+'Z'-name[current_index]);
        arr[current_index]=name[current_index];
    }
    
    return answer;
}
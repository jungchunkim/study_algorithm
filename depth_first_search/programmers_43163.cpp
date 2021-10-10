#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// words의 최대 개수가 50개이므로 최대값으로 지정하자 ( answer는 나올 수 있는 최솟값을 구하는 것이기 때문에 )
int answer = 10000;

void dfs(string begin, string target, vector<string> words, vector<bool> &arr, int cnt){
    
    for(int i=0;i<words.size();i++){
        string s = words[i];
        
        if(arr[i]==true){
            continue;
        }
        
        int num_cnt=0;
        for(int j=0;j<s.length();j++){
            if(s[j]!=begin[j]){
                num_cnt++;
            }
        }
        
        if(num_cnt==1){
            // 바꿀수 있을때
            
            if(s==target){
                //결과면
                answer = min(answer,cnt+1);
                return;
            }
            
            arr[i]=true;
            dfs(s,target,words,arr,cnt+1);
            arr[i]=false;
        }
        
    }
    
    
}

int solution(string begin, string target, vector<string> words) {
    
    vector<bool> arr(words.size(),false);
    
    dfs(begin, target, words,arr,0);
    
    if(answer==10000){
        return 0;
    }
    else{
        return answer;    
    }
    
}
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> dq;
    
    for(int i=0;i<operations.size();i++){
        string s = operations[i];
        
        if(s[0]=='I'){
            //숫자 삽입
            int num=stoi(s.substr(2));
            dq.push_back(num);
            sort(dq.begin(),dq.end());
        }
        else if(s=="D 1"){
            //최댓값 삭제
            if(dq.empty()){
                continue;
            }
            else{
                dq.pop_back();    
            }
            
        }
        else{
            //최솟값 삭제
            if(dq.empty()){
                continue;
            }
            else{
                dq.pop_front();    
            }
        }
        
    }
    vector<int> answer;
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}
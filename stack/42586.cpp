#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> progresses_minus;
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        if((100-progresses[i])%speeds[i]==0){
            progresses_minus.push_back((100-progresses[i])/speeds[i]);    
        }
        else{
            progresses_minus.push_back((100-progresses[i])/speeds[i] +1);    
        }
    }
    stack<int> s;
    s.push(progresses_minus[0]);
    int cnt=1;
    for(int i=1;i<progresses_minus.size();i++){
        int front_num = s.top();
        if(front_num<progresses_minus[i]){
            answer.push_back(cnt);
            s.pop();
            s.push(progresses_minus[i]);
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}
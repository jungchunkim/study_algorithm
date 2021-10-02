#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue<int> pq;
    
    for(int i=0;i<scoville.size();i++){
        pq.push(-scoville[i]);
    }
    
    int answer = 0;
    while(true){
        if(-pq.top()>=K){
            break;
        }
        int a = -pq.top();
        pq.pop();
        if(pq.empty()){
            return -1;
        }
        int b = -pq.top();
        pq.pop();
        
        pq.push(-(a+2*b));
        answer++;
    }
    
    
    return answer;
}
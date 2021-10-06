#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    vector<int> student(n+2,0);
    
    for(int i=0;i<lost.size();i++){
        student[lost[i]]--;
    }
    
    for(int i=0;i<reserve.size();i++){
        student[reserve[i]]++;
    }
    
    
    for(int i=1;i<=n;i++){
        if(student[i]<0){
            if(student[i-1]>0){
                student[i-1]--;
                student[i]++;
            }
            else if(student[i+1]>0){
                student[i+1]--;
                student[i]++;
            }
            
        }
    }
    int answer=0;
    for(int i=1;i<=n;i++){
        if(student[i]>=0){
            answer++;
        }
    }
    
    return answer;
    
    
}
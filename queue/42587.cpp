#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q;
    
    vector<int> result;
    for(int i=0;i<priorities.size();i++){
        q.push({i,priorities[i]});
    }
    
    sort(priorities.begin(),priorities.end());
    reverse(priorities.begin(),priorities.end());
    int index=0;
    
    while(!q.empty()){
        int front_num=priorities[index];
        if(q.front().second==front_num){
            result.push_back(q.front().first);
            index++;
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    for(int i=0;i<result.size();i++){
        if(result[i]==location){
            return i+1;
        }
    }
    
}
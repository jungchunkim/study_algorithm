#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std;

int visited[10000] = {0};

vector<string> res;

bool DFS(string start, vector<vector<string>> tickets, int chkcnt){
 
    if(chkcnt==tickets.size()) 
        return true;
   
    for(int i = 0; i<tickets.size(); i++){
       if(visited[i]==0 && start == tickets[i][0]){
           visited[i] = 1;
           res.push_back(tickets[i][1]);
           
           // 다음 DFS 가 갈 곳이 있으면 true, 갈 곳이 없으면 false
           bool resbool = DFS(tickets[i][1], tickets, chkcnt+1);
           
           if(resbool) 
               return true;
           
           visited[i] = 0;
       }
    }
    
    res.pop_back();
    return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());

    string start = "ICN";
    res.push_back(start);

    DFS(start, tickets, 0);
    
    answer = res;
       
    return answer;
}
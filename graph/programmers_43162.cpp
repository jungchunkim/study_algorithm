#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[201];

int parent_node(int i){
    if(i==parent[i]){
        return i;
    }
    else{
        return parent[i]=parent_node(parent[i]);
    }
}

void union_node(int i,int j){
    int x =parent_node(i);
    int y =parent_node(j);
    
    if(x>y){
        parent[x]=y;
    }
    else{
        parent[y]=x;
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(computers[i][j]==1){
                union_node(i,j);
            }
        }
    }
    
    vector<int> result;   
    for(int i=0;i<n;i++){
        result.push_back(parent_node(i));    
    }
    sort(result.begin(),result.end());
    
    result.erase(unique(result.begin(),result.end()),result.end());
    
    return result.size();
}
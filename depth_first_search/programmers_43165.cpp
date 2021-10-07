#include <string>
#include <vector>

using namespace std;

vector<int> arr;
int answer = 0;
int tar;

void dfs(int sum,int n){
    if(n==arr.size()){
        if(sum==tar){
            answer++;    
        }
        return;
    }
    
    dfs(sum+arr[n],n+1);
    dfs(sum-arr[n],n+1);
    
}

int solution(vector<int> numbers, int target) {
    for(int i=0;i<numbers.size();i++){
        arr.push_back(numbers[i]);
    }    
    tar=target;
    
    dfs(0,0);
    
    return answer;
}
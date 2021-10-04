#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr1 = {1,2,3,4,5};
vector<int> arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    
    vector<int> answer;
    vector<int> cnt(3,0);
    
    for(int i=0;i<answers.size();i++){
        int num = answers[i];    
        
        if(arr1[i%arr1.size()]==num){
            cnt[0]++;
        }
        if(arr2[i%arr2.size()]==num){
            cnt[1]++;
        }
        if(arr3[i%arr3.size()]==num){
            cnt[2]++;
        }
    }
    int max_num = max(cnt[0],max(cnt[1],cnt[2]));
    for(int i=0;i<3;i++){
        if(max_num==cnt[i]){
            answer.push_back(i+1);
        }
    }   
    
    return answer;
}
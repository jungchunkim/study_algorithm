#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer;
    
    for (int k = 0; k < prices.size(); k++){
        int chk = 0;
        for(int i = k+1; i < prices.size(); i++){
            chk++;
            if(prices[k] > prices[i]) 
                break;
            }
        answer.push_back(chk); 
    }
    return answer;
}
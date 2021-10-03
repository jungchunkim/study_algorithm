#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i = 0 ; i < citations.size(); i++)
    {
        int H_Index = citations.size() - i;
        if(citations[i] >= H_Index) return H_Index;
    }
    return answer;
}


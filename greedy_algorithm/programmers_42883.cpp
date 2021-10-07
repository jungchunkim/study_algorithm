#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer="";
    
    int index=-1;
    for(int i=0;i<number.size()-k;i++){
        
        char num =' ';
        for(int j=index+1;j<=k+i;j++){
            if(number[j]>num){
                num=number[j];
                index=j;
            }
        }
        answer+=num;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a , int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    if(stoi(s1+s2)>stoi(s2+s1)){
        return true;
    }
    else{
        return false;
    }
}

string solution(vector<int> numbers) {
    
    if(numbers.size()>1){
        sort(numbers.begin(),numbers.end(),compare);    
    }
    
    
    string s="";
    for(int i=0;i<numbers.size();i++){
        s+=to_string(numbers[i]);
    }
 
    while(true){
        if(s.size()!=0 && s[0]=='0'){
            s=s.substr(1);
        }
        else{
            break;
        }
    }
    
    if(s.size()==0){
        return "0";
    }
    else{
        return s;    
    }
    
}
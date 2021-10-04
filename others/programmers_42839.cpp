#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int num){
    
    bool check_num=false;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            check_num=true;
        }
    }
    if(check_num==false && num > 1){
        return true;
    }
    else{
        return false;
    }
}


int solution(string numbers) {
    int answer = 0;
    
    vector<int> arr;
    
    for(int i=0;i<numbers.length();i++){
        arr.push_back(numbers[i]-'0');
    }
    sort(arr.begin(),arr.end());
    
    vector<int> temp;
    
    
    do{
        string s="";
        for(int i=0;i<arr.size();i++){
            s+=to_string(arr[i]);
            temp.push_back(stoi(s));
        }
    }while(next_permutation(arr.begin(),arr.end()));
    
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i=0;i<temp.size();i++){
        if(isPrime(temp[i])){
            answer++;
        }
    }
    return answer;
}
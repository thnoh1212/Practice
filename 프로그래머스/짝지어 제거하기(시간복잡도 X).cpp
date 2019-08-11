#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<int> check;
    int temp = 0, count = 1;
    check.assign(s.size(), 0);
    while(count != 0){
        count = 0;
        for(int i = 0; i < s.size(); i++){
            if(check[i] != 0)
                continue;
            
            temp = i+1;
            while(check[temp] != 0 && temp < s.size() - 1)
                temp += 1;
            if(s[i] == s[temp]){
                check[i] = 1;
                check[temp] = 1;
                count++;
            }
        }
    }
    answer = 1;
    for(int i = 0; i < check.size(); i++){
        if(check[i] == 0){
            answer = 0 ;
            break;
        }
    }
    return answer;
}

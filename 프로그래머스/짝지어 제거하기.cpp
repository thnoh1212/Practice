#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> test;
    int answer = 0;
    for(int i = 0; i < s.size(); i++){
        if(!test.empty()){
            if(s[i] == test.top()){
                test.pop();
            }
            else
                test.push(s[i]);
        }
        else
            test.push(s[i]);
        
    }
    if(test.empty())
        answer = 1;
    else
        answer = 0;
    return answer;
}

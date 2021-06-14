#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> stick;
    int count = 0;
    stick.push(arrangement[0]);
    for(int i = 1; i < arrangement.size(); i++){
        if(stick.top() == '(' && arrangement[i] == ')')
            answer += count;
        else if(stick.top() == '(')
           count++;
        else if(stick.top() != '(' && arrangement[i] == ')'){
            count--;
            answer++;    
        }
        stick.push(arrangement[i]);
    }
    return answer;
}

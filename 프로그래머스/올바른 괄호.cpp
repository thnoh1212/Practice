#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count[2] = {0, 0};
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            count[0] += 1;
        else if(s[i] == ')')
            count[1] +=1;
        if(count[1] > count[0]){
            answer = false;
            break;
        }    
    }
    if(count[0] == count[1])
        answer = true;
    else
        answer = false;
    return answer;
}

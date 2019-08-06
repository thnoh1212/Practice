#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count[2] = {0, };
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'p' || s[i] == 'P')
            count[0]++;
        else if(s[i] == 'y' || s[i] == 'Y')
            count[1]++;
    }
    if(count[0] == count[1])
        answer = true;
    else
        answer = false;
    return answer;
}

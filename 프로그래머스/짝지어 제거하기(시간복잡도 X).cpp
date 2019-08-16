#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int i = 0, check = 0;;
    while(s.size() >= 1){
        if(i >= s.size())
            i = 0;
        if(s[i] == s[i+1]){
            check = 0;       
            s.erase(i, 2);
        }
        else{
            i++;
            check++;
            if(check >= s.size())
                break;
        }
    }
    if(s.size() == 0)
        answer = 1;
    else
        answer = 0;
    return answer;
}

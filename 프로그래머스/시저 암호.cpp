#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.length(); i++){
        if (s[i] == ' '){
            answer += s[i];
            continue;
        }        
        if(s[i] <= 122 && s[i] >= 97){
            s[i] = (s[i] - 'a' + n)% 26 + 'a';
            answer += s[i];
            continue;

        }
        if(s[i] <= 90 && s[i] >= 65){
            s[i] = (s[i] - 'A' + n)% 26 + 'A';
            answer += s[i];

            
        }
        
    }
    return answer;
}

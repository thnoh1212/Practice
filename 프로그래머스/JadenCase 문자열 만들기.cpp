#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int check = 1;
    for(int i = 0; i < s.size(); i++){
         s[i] = tolower(s[i]);
        if(check == 1){
            check = 0;
            s[i] = toupper(s[i]);
        }
        if(s[i] == ' ')
            check = 1;
    }
    answer = s;
    return answer;
}

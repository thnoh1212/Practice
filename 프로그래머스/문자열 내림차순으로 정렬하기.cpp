#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char temp;
    for(int i = 0; i < s.length(); i++){
        for(int j = i; j < s.length(); j++){
            if(s[i] < s[j]){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    answer = s;
    return answer;
}

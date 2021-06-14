#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int num = s.length();
    if(num % 2 == 0){
        answer.push_back(s[num/2 -1]);
        answer.push_back(s[num/2]);
    }
    else{
        answer.push_back(s[num/2]);
    }
    return answer;
}

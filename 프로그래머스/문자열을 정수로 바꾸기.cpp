#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    int check = 0;
    if(s[0] == '+' || s[0] == '-'){
        if(s[0] == '+')
            check = 1;
        else
            check = 0;
        for(int i = 1; i < s.size(); i++){
            answer += (s[i]- 48) * pow(10, s.size() - i - 1);
            
        }
        if(check == 0)
                answer *= -1;
    }
    else
        for(int i = 0; i < s.size(); i++){
            answer += (s[i]- 48) * pow(10, s.size() - i - 1);
        }
    return answer;
}

#include <string>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1; i <= s.length()/2; i++){
        string word = s.substr(0, i);
        string remainder = s;
        int cnt = 1;
        remainder.erase(0,i);
        string t_answer = "";
        while(remainder.length() >= i){
            string temp = remainder.substr(0,i);
            remainder.erase(0, i);
            if(word == temp)
                cnt++;
            else{
                if(cnt != 1)
                    t_answer += to_string(cnt) + word;
                else
                    t_answer += temp;
                word = temp;
                cnt = 1;
            }
        }
        // 마지막에 계산하던 word값 추가
        if(cnt != 1)
            t_answer += to_string(cnt) + word;
        else
            t_answer += word;
        // 잘리지 않고 remainder 남아있는 값 추가
        if(remainder.length() != 0)
            t_answer += remainder;
        // 정답과 길이비교
        if(answer > t_answer.length())
            answer = t_answer.length();      
    }
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    char temp;
    for(int i = 0; n > 0;){
        if(n % 3 == 0){
            answer += '4';
            n = n / 3 - 1;
            continue;
        }
        else if(n % 3 == 1){
            temp = '1';
        }
        else{
            temp = '2';
        }
        answer += temp;
        n = n / 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}






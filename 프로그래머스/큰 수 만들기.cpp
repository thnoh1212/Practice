#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int need = number.length() - k; // 정답으로 제출할 문자열의 길이 계산
    int max = 0, cnt = 0;
    for (int i = need; i>0; i--) { // 정답 문자열의 길이만큼 반복
        max = 0;
        cnt = 0;
        for (int j = 0; j <= number.length() - i; j++) { // 삭제할 수 있는 값의 범위중 최댓값 탐색
            if (max<number[j]) {
                max = number[j];
                cnt = j;
            }
        }
        number.erase(0,cnt+1); // 최댓값 앞에있는 값들은 전부 삭제
        answer += to_string(max - 48); //최대값 삽입
    }
    return answer;
}

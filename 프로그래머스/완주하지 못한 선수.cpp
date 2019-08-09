#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int check = 0;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i = 0; i < completion.size(); i++){
        if(completion[i] != participant[i]){
            answer = participant[i];
            check = 1;
            break;
        }
    }
    if(check == 0)
        answer = participant[participant.size()-1];
    return answer;
}
/* 이 문제를 푸는데는 시작부터 잘못되게 들어가서 시간복잡도에서 실패.
   사전순으로 두 배열을 정렬한 후, 다른 이름이 나올 때 해당 선수가 실패한 선수. */

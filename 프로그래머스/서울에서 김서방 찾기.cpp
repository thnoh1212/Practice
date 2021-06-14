#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int temp;
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == "Kim"){
            temp = i;
            break;
        }
    }
    string position = to_string(temp);
    answer = "김서방은 " + position + "에 있다";
    cout << answer << endl;
    return answer;
}

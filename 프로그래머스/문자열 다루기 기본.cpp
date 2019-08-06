#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length() != 4){
        answer = false;
        return answer;
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] < 48 || s[i] > 57 ){
            answer = false;
            return answer;
        }
    }
    answer = true;
    return answer;
}

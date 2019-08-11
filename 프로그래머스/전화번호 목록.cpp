#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int check = 0;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size(); i++){
        for(int j = i+1; j < phone_book.size(); j++){
            if(phone_book[j].find(phone_book[i]) !=  string::npos){
                answer = false;
                check = 1;
                break;
            } 
        }
        if(check == 1)
            break;
    }
    
    return answer;
}
/* stiring.find() 함수를 사용할 때, 매칭되는 문자열이 없을 경우 -1을 반환하는 것이 아닌 굉장히 큰 값을 반환하기 때문에,
   string::npos 사용하여 매칭되지 않은 경우, 즉 접두어로 사용되지 않은 경우를 찾아내야 함. == -1 사용 불가 */

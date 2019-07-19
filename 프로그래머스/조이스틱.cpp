#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    float size = name.length();
    int cursor = 0;
    int temp = 0;
    int cursor_move[2] = {0, 0};
    int count = 0;
    int check_mv = 0;
    int i = 0;
    vector<char> name_t;
    vector<pair<int, int>> check;
    for(int i = 0; i < size; i++){
        name_t.push_back(name[i]);
        if(name[i] == 'A'){
            check.push_back(make_pair(1, 0));
            if(i >= size/2.0)
                cursor_move[1]++;
            else            
                cursor_move[0]++;
        }
        else{
            temp = (abs(name[i] - 65) >= abs(name[i] - 91) ? abs(name[i] - 91) : abs(name[i] - 65));
            check.push_back(make_pair(0, temp));
        }
    }
    //A의 위치에 따라 커서 이동방향 선택
    
   check_mv = (cursor_move[1] > cursor_move[0]) ?  0 : 1;
    
        
    while(1){
        //문자열 전부 탐색 완료시 반복문 종료
        if(count == size)
            break;
        
        count++;
        //뒤로 탐색하여 커서가 시작 -> 끝으로 넘어가는 경우
        if(i == -1){
            cursor = size;
            i = size - 1;
        }
        //입력 문자열이 A인 경우, 위치만 변경 후 반복문 계속
        if(check[i].first == 1){
            if(check_mv == 1)
                i--;
            else
                i++;
            continue;
        }
        else{
            
                if(check_mv == 1){
                    temp = abs(cursor - i);
                    check[i].second += temp;
                    check[i].first = 1;
                    cursor = i--;
                }
                else{
                    temp = abs(i - cursor);
                    check[i].second += temp;
                    check[i].first = 1;
                    cursor = i++;
                }
        }
        
    }
    for(int i = 0; i < size; i++){
        answer += check[i].second;
    }
    //A = 65;
    //Z = 90
    return answer;
}
#테스트케이스 11 안됨. 혼합결과 생각.

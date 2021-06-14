#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int flag = 0;
    int max = 0, min = 2147483647;
    for(int i = 0; i < operations.size(); i++){
        string operation = "";
        if(operations[i][0] == 'I'){// 추가연산
            operation = operations[i].erase(0, 2);
            int number = stoi(operation);
            
            if(max < number){ // 새로 받는 값이 최댓값인 경우
                max = number;
                answer.push_back(number);
            }
            else if(min > number){ // 새로 받는 값이 최솟값인 경우
                min = number;
                answer.insert(answer.begin(), number);
            }
            else{ // 둘 다 아닌경우
                flag = 0;
                answer.push_back(number);    
            }
        }
        else{// 삭제연산
            if(answer.size() == 0) continue;
            
            if(flag == 0){ // 정렬 후 값을 추가한 적이 있으면 재정렬
                sort(answer.begin(), answer.end());
                flag = 1;    
            }
            
            if(operations[i][2] == '1'){// 최댓값 삭제
                answer.pop_back();
                if(answer.size() != 0)// 새로운 최댓값 저장
                    max = answer[answer.size() - 1];
            }
            
            else{// 최솟값 삭제
                answer.erase(answer.begin());
                if(answer.size() != 0)// 새로운 최솟값 저장
                    min = answer[0];
            }
        }
    }
    if(answer.size() == 0)
        return {0, 0};
    
    else{
        if(flag == 0)
            sort(answer.begin(), answer.end());
        return {answer[answer.size() - 1], answer[0]};
    }
    return answer;
}

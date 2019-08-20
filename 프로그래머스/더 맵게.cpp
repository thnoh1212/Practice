#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int temp = 0, temp_2 = 0;
    priority_queue<int,vector<int>,greater<int>> test;
    
    for(int i = 0; i < scoville.size(); i++)
        test.push(scoville[i]);
    
    for(int i = 0; i < scoville.size()-1; i++){
        if(test.top() > K)
            break;
        temp = test.top();
        test.pop();
        temp_2 = test.top() * 2;
        test.pop();
        test.push(temp + temp_2);
        answer += 1;
    }
    
    if(test.top() < K)
        answer = -1;
 
    return answer;
}

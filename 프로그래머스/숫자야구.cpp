#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for(int i = 123; i <= 987; i++){
        int a = i / 100;
        int b = i % 100 / 10;
        int c = i % 10;
        if(a == 0 || b == 0 || c == 0) continue;
        if(a == b || b == c || a == c) continue;
        
        for(int j = 0; j < baseball.size(); j++){
            int temp = baseball[j][0];
            int _a = temp / 100;
            int _b = temp % 100 / 10;
            int _c = temp % 10;
            int strike = 0, ball = 0;
            
            if(a == _a) strike++;
            if(b == _b) strike++;
            if(c == _c) strike++;
            if(strike != baseball[j][1]) break;

            if(a == _b || a == _c) ball++;
            if(b == _a || b == _c) ball++;
            if(c == _a || c == _b) ball++;
            if(ball != baseball[j][2]) break;
            
            if(j == baseball.size()-1)
                answer++;
            
        }
    }
    return answer;
}

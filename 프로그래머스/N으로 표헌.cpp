#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<int> temp[9];
    
    temp[1].push_back(N);
    for(int i = 2; i <= 8; i++){
        temp[i].push_back(temp[i-1][0] * 10 + N);
    }
    
    for(int i = 2; i <= 8; i++){
        for(int j = 1; j <= i/2; j++){
            int k = i - j;
            for(auto a : temp[j]){
                for(auto b : temp[k]){
                    temp[i].push_back(a + b);
                    if(a * b != 0)
                        temp[i].push_back(a * b);
                    if(a - b != 0)
                        temp[i].push_back(abs(a - b));
                    if(a != 0 && b / a >= 1)
                        temp[i].push_back(b / a);
                    if(b != 0 && a / b >= 1)
                        temp[i].push_back(a / b);
                }
            }
        }
        for(auto a : temp[i])
            if(a == number)
                return i;
    }
    return -1;
}

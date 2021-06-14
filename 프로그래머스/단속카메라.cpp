#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] <= b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int range = -30000;
    
    for(auto &route : routes){// 배열 auto로 사용
        if(range < route[0]){
            answer += 1;
            range = route[1];
        }
    }
    return answer;
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0, i = 0;
    sort(d.begin(), d.end());
    while(sum <= budget && answer <= d.size()){
        sum += d[i++];
        answer++;
    }
    answer -= 1;

    return answer;
}

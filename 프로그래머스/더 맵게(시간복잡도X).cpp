#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int temp = 0;
    for(int i = 0; i < scoville.size()-1; i++){
        sort(scoville.begin(), scoville.end());
        if(scoville[i] >= K)
            break;
        scoville[i+1] = scoville[i] + (scoville[i+1] * 2);
        scoville[i] = 0;
        answer += 1;
        
    }
    if(scoville[scoville.size()-1] < K)
        answer = -1;
 
    return answer;
}

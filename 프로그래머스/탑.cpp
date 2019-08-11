#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    for(int i = heights.size()- 1; i > 0; i--){
        for(int j = i-1; j >= 0; j--){
            if(heights[i] < heights[j]){
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}

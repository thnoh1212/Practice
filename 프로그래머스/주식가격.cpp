#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;
    int dates = prices.size();
    for(int i = 0; i < dates; i++){
        for(int j = i+1; j < dates; j++){
            count++;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(count);
        count = 0;
        
    }

    return answer;
}

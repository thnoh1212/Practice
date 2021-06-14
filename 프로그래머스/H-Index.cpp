#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    int h = 0;
    int temp = 0;
    sort(citations.begin(), citations.end());
    for(int i = n-1; i >= 0; i--){
        h = n - i;
        if(citations[i] >= h)
           temp = h;
    }
    answer = temp;
    return answer;
}

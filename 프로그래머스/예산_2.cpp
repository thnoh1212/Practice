#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int sum = 0;
    int money = budgets.size();
    sort(budgets.begin(), budgets.end());
    for(auto a : budgets){
        while(answer < a && M > sum){
            sum += money;
            answer += 1;
        }
        money -= 1;
    }
    if(M < sum)
        answer -= 1;
    
    return answer;
}

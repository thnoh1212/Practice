#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> Fibo;
    Fibo.push_back(0);
    Fibo.push_back(1);
    Fibo.push_back(1);
    for(int i = 3; i <= n; i++)
        Fibo.push_back((Fibo[i-2] + Fibo[i-1])% 1234567);
    answer = Fibo[n];
    return answer;
}

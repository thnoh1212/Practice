#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long test[81];
    long long fibo[81];
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i = 3; i <= N; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    test[0] = 0;
    test[1] = 4;
    for(int i = 2; i <= N; i++)
        test[i] = fibo[i] * 4 + fibo[i-1] * 2;

    return test[N];
}

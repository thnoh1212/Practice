#include <vector>
#include <cmath>
using namespace std;

long long solution(int N) {
    long long answer = 0;
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            if(i%j == 0 && i != j && j != 1)
                break;
            else if(i == j)
                answer += i;
        }
    }
    return answer;
}
// 에라토스테네스의 체 적용 필요

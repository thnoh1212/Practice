#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long answer[60001] = { 0 };
	answer[1] = 1;
	answer[2] = 2;

	for (int i = 3; i <= n; i++){
		answer[i] = answer[i - 1] + answer[i - 2];
		answer[i] %= 1000000007;
	}
    return answer[n];
}

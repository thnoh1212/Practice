#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int modNum = 1000000000;
	int answer = 0;
	if (N < 10) {
		cout << 0;
		return 0;
	}
	int dp[101][10][1 << 10] = { 0 };

	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 1; k < 1024; k++) {
				if (j == 0)
					dp[i][0][k | 1 << j] += dp[i - 1][1][k];
				else if (j == 9)
					dp[i][9][k | 1 << j] += dp[i-1][8][k];
				else 
					dp[i][j][k | 1 << j] += (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]);
				dp[i][j][k] %= modNum;
			}
		}
	}
	for (int j = 0; j <= 9; j++) {
		answer += dp[N][j][1023];
		answer %= modNum;
	}
	cout << answer;

}

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, answer = 0;;
	cin >> N;
	vector<int> temp;
	vector<int> dp;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		temp.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		dp.push_back(1);
		for (int j = 0; j < i; j++) {
			if (temp[i] < temp[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		answer = max(answer, dp[i]);
	}

	cout << N - answer;
}

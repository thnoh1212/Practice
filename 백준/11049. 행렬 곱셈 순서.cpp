/*
  처음에는 단순dfs로 풀이하려 했으나, 시간초과 / 메모리 초과 둘 중 하나가 날 것으로 보여 dp로 접근
  dp배열을 선언하여 dp[i][j] = i번쨰 행렬부터 j번째 행렬까지의 연산 값 중 최솟값 을 저장
  반복횟수를 줄이기 위해 dfs시작부분에 dp[i][j] != 0인 경우 해당 값을 반환하는 조건 추가
  dfs를 실행한 후 1 ~ N구간의 최소 연산수가 저장된 dp[0][n-1] 출력
*/

#include <iostream>
#include <vector>

using namespace std;

int dp[500][500];
int arr[500][2];

int dfs(int left, int right) {
	if (left == right) return 0;
	if (dp[left][right] != 0) return dp[left][right];

	for (int i = left; i < right; i++) {
		int value = dfs(left, i) + dfs(i + 1, right) + arr[left][0] * arr[i][1] * arr[right][1];
		if (!dp[left][right] || value < dp[left][right])
			dp[left][right] = value;
	}
	
	return dp[left][right];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		arr[i][0] = arr[i][1] = 0;
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	dfs(0, N-1);

	cout << dp[0][N - 1];
	return 0;
}


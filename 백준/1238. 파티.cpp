#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, X, answer = 0;
	cin >> N >> M >> X;
	int costs[1001][1001] = { 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			costs[i][j] = 10000000;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		costs[a][b] = c;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (costs[i][k] == 10000000) continue;
			for (int j = 1; j <= N; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++){
		if (i == X) continue;
		answer = max(answer, costs[i][X] + costs[X][i]);
	}
	cout << answer;
}

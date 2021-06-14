#include <iostream>

using namespace std;

int map[500][500] = { 0 };
int answer[500][500] = { 0 };
int n;
int moves[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };


int dfs(int startI, int startJ) {
	
	if (answer[startI][startJ]) return answer[startI][startJ];
	answer[startI][startJ] = 1;
	for (int i = 0; i < 4; i++) {
		int nextI = startI + moves[i][0];
		int nextJ = startJ + moves[i][1];
		if (nextI >= n || nextI < 0 || nextJ >= n || nextJ < 0 || map[nextI][nextJ] >= map[startI][startJ]) continue;
		answer[startI][startJ] = max(answer[startI][startJ], dfs(nextI, nextJ) + 1);
	}
	return answer[startI][startJ];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				res = max(res, dfs(i, j));
		}
	}
	cout << res;
	return 0;
}

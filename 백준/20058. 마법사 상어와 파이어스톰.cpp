#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int map[64][64] = { 0 };
bool visited[64][64] = { 0 };

void rotateMap(int i, int j, int temp);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int moves[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	
	int N, L, sum = 0, answer = 0;
	cin >> N >> L;
	N = pow(2, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			sum += map[i][j];
		}
	}
	int temp;
	while (L) {
		L--;
		cin >> temp;
		temp = pow(2, temp);
		for (int i = 0; i < N; i += temp) {
			for (int j = 0; j < N; j += temp) {
				rotateMap(i, j, temp);
			}
		}
		queue<pair<int, int>> temp;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j]) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int ni = i + moves[k][0];
						int nj = j + moves[k][1];
						if (ni >= N || ni < 0 || nj >= N || nj < 0 || map[ni][nj] == 0) continue;
						cnt++;
					}
					if (cnt < 3) temp.push({ i, j });
				}
			}
		}
		while (!temp.empty()) {
			int i = temp.front().first;
			int j = temp.front().second;
			map[i][j] -= 1;
			sum -= 1;
			temp.pop();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				queue<pair<int, int>> que;
				int cnt = 1;
				que.push({ i, j });
				visited[i][j] = true;
				while (!que.empty()) {
					int ci = que.front().first;
					int cj = que.front().second;
					que.pop();
					for (int k = 0; k < 4; k++) {
						for (int k = 0; k < 4; k++) {
							int ni = ci + moves[k][0];
							int nj = cj + moves[k][1];
							if (ni >= N || ni < 0 || nj >= N || nj < 0 || visited[ni][nj] || map[ni][nj] == 0) continue;
							cnt += 1;
							visited[ni][nj] = true;
							que.push({ ni, nj });
						}
					}
				}
				if (cnt > 1) answer = max(answer, cnt);
			}
		}
	}

	cout << sum << '\n' << answer;
	return 0;
}

void rotateMap(int si, int sj, int temp) {
	queue<int> que;
	for (int i = si; i < si + temp; i++) {
		for (int j = sj; j < sj + temp; j++) {
			que.push(map[i][j]);
		}
	}
	for (int j = sj + temp - 1; j >= sj; j--) {
		for (int i = si; i < si + temp; i++) {
			map[i][j] = que.front();
			que.pop();
		}
	}
}

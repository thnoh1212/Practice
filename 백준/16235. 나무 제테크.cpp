#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int map[10][10];
	int A[10][10];
	vector<int> tree[10][10];
	int answer = 0;
	fill(&map[0][0], &map[9][10], 5);
	// fill은 0,0 ~ N-1,N
	int moves[8][2] = { {1, 0},{0, 1} ,{-1, 0} ,{0, -1} ,{-1, 1} ,{1, -1} ,{1, 1} ,{-1, -1} };

	int N, M, K;
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			A[i][j] = temp;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		x--; y--;
		tree[x][y].push_back(age);
	}

	while (K != 0) {
		int tFood[10][10] = { 0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tree[i][j].size() == 0) continue;
				sort(tree[i][j].begin(), tree[i][j].end());
				for(int k = 0; k < tree[i][j].size(); k++){
					if (map[i][j] >= tree[i][j][k]) {
						map[i][j] -= tree[i][j][k];
						tree[i][j][k] += 1;
					}
					else {
						tFood[i][j] += tree[i][j][k] / 2;
						tree[i][j].erase(tree[i][j].begin() + k);	
						k--;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] += (tFood[i][j] + A[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tree[i][j].size() == 0) continue;
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 != 0) continue;
					for (int l = 0; l < 8; l++) {
						int nexti = i + moves[l][0];
						int nextj = j + moves[l][1];
						if (nexti < 0 || nexti >= N || nextj < 0 || nextj >= N) continue;
						else
							tree[nexti][nextj].push_back(1);
					}
				}

			}
		}
		K--;
	}
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < N; j++) {
			answer += tree[i][j].size();
		}
	}
	
	cout << answer << endl;
	return 0;
}

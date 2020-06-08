#include <iostream>
#include <queue>

using namespace std;

int moves[4][2] = { {1,0}, {0,1}, {-1, 0}, {0, -1} };
int region[100][100];
int map[100][100] = { 0 };

void bfs(int min, int i, int j, int N) {

	queue<pair<int, int>> temp;
	temp.push(make_pair(i, j));
	map[i][j] = min;
	while (!temp.empty()) {
		int cur_i = temp.front().first;
		int cur_j = temp.front().second;
		temp.pop();
		for (int i = 0; i < 4; i++) {
			int next_i = cur_i + moves[i][0];
			int next_j = cur_j + moves[i][1];

			if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < N) {
				if (region[next_i][next_j] > min && map[next_i][next_j] != min) {
					map[next_i][next_j] = min;
					temp.push(make_pair(next_i, next_j));
				}
			}

		}
	}
}

int main()
{
	int N;
	int min = 100;
	int max = 0;
	int answer = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> region[i][j];
			if (min > region[i][j])
				min = region[i][j];
			if (max < region[i][j])
				max = region[i][j];
		}
	}

	while (min != max) {
		
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(map[i][j] != min && region[i][j] > min){
					bfs(min, i, j, N);
					cnt++;
				}
			}
		}
		if (cnt > answer)
			answer = cnt;
		min += 1;
	}
	cout << answer;
}

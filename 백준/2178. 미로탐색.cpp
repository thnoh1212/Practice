/*
 bfs사용. 2차원 배열을 사용하여 미로를 구성했을 때
 maze[x][y]좌표가 아닌 maze[y][x]임
 2차원배열 선언 다시 확인
*/

#include <iostream>
#include <queue>

char maze[101][101];
int visit[101][101];

using namespace std;

int N, M;

void bfs(int start_y, int start_x)
{
	queue<pair<int, int> > q;
	int move[4][2] = { {1,0},{-1,0}, {0,1}, {0,-1} };
	visit[start_y][start_x] = 1;
	q.push(make_pair(start_y, start_x));
	int cur_x = 0;
	int cur_y = 0;
	while (!q.empty()) {
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + move[i][0];
			int next_y = cur_y + move[i][1];
			if (next_x > 0 && next_x <= M && next_y > 0 && next_y <= N) {
				if (visit[next_y][next_x] == 0 && maze[next_y][next_x] == '1') {
					visit[next_y][next_x] = visit[cur_y][cur_x] + 1;
					q.push(make_pair(next_y, next_x));
				}
			}
			
		}

	}

}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}

	bfs(1, 1);
	cout << visit[N][M];
}


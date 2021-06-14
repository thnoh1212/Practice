/*
 도움없이 해결한 첫 bfs
 단지의 넘버링 없이 크기만 오름차순으로 출력하기 때문에 priority queue사용.
 백터 사용후 sort 사용해도 문제 없음
 전체적인 맵을 받아올 때 받는 값 사이 공백이 없기 때문에 char형 맵 사용
*/

#include <iostream>
#include <queue>

using namespace std;

char map[25][25];
char check[25][25];
int N;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
priority_queue<int, vector<int>, greater<int> > danji;

void bfs()
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && !check[i][j]) {
				check[i][j] = 1;
				int num = 1;
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int cur_i = q.front().first;
					int cur_j = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int next_i = cur_i + dir[i][0];
						int next_j = cur_j + dir[i][1];

						if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < N) {
							if (map[next_i][next_j] == '1' && !check[next_i][next_j]){
								num += 1;
								check[next_i][next_j] = 1;
								q.push(make_pair(next_i, next_j));
							}
						}
					}
				}
				danji.push(num);
				count += 1;
			}
		}
	}
	cout << count;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	
	while (!danji.empty()) {
		cout << '\n' << danji.top();
		danji.pop();
	}
}

/*
  과일이 한개가 아니므로 요일별로 담는 벡터와
  그 날의 과정을 진행하는 큐를 선언
  하루동안 과일이 익는 결과를 전부 벡터에 저장한 후
  큐가 비게되면 벡터의 값을 전부 큐로 옮기는 형식으로 구현
  전체 과일의 갯수를 bfs에 인자값으로 전달하여
  bfs를 진행하며 익는 과일의 개수와 전달받은 값의 갯수를 비교
  다르다면 익지 못한 과일이 있으므로 -1
  같다면 최소 날짜를 반환
*/

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int box[1000][1000];
int check[1000][1000];
int x, y;

int bfs(int count)
{
	int max = 0, tomato = 0;
	int move[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	queue<tuple<int, int, int> > q;
	vector<tuple<int, int, int> > temp;
	
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (box[i][j] == 1) {
				q.push(make_tuple(i, j, 0));
			}
		}
	}
	while (!q.empty()) {
		int cur_i = get<0>(q.front());
		int cur_j = get<1>(q.front());
		int day = get<2>(q.front());
		if (day > max)
			max = day;
		q.pop();
		tomato++;
		for (int k = 0; k < 4; k++) {
			int next_i = cur_i + move[k][0];
			int next_j = cur_j + move[k][1];
			if (next_i >= 0 && next_i < y && next_j >= 0 && next_j < x) {
				if (box[next_i][next_j] == 0 && !check[next_i][next_j]) {
					box[next_i][next_j] = 1;
					check[next_i][next_j] = 1;
					temp.push_back(make_tuple(next_i, next_j, day + 1));
				}
			}
		}
		if (q.empty()) {
			for (int i = 0; i < temp.size(); i++) {
				q.push(make_tuple(get<0>(temp[i]), get<1>(temp[i]), get<2>(temp[i])));
			}
			temp.clear();
		}
	}
	if (count == tomato)
		return max;
	else
		return -1;
}

int main()
{
	cin >> x >> y;
	int count = x * y;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> box[i][j];
			if (box[i][j] == -1)
				count -= 1;
		}
	}
	int answer = bfs(count);

	cout << answer;

	return 0;
}

/*
 dfs 기초
 특별한 사항 없음.
 아직 탐색하지 않은 정점을 만날 때 마다 dfs 진행하여 연결된 모든 정점 탐색
 dfs를 시작한다면 새로운 연결 요소를 만난 것이므로 count++ 진행
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int check[1001];
int count = 0;
vector<int> map[1001];

void dfs(int start) {

	if (check[start]) return;

	check[start] = 1;

	for (int i = 0; i < map[start].size(); i++) {
		dfs(map[start][i]);
	}
}

int main()
{
	int N, M, count = 0;
	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int temp_1, temp_2;

		cin >> temp_1 >> temp_2;

		map[temp_1].push_back(temp_2);
		map[temp_2].push_back(temp_1);
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			dfs(i);
			count++;
		}
	}
	cout << count << endl;
}

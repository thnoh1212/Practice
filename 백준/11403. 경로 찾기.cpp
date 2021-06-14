/*
  dfs문제
  처음에 start, cur값을 받은 후 dfs내부에서 모든 과정을 진행하려 햇으나 실패.
  메인 함수에서 vector값을 cur로 변경 후 dfs 진행
  플로이드-와샬 문제라고 함. 이걸로도 풀어보기
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int map[100][100] = { 0 };
vector<int> point[100];

void dfs(int start, int cur) {

	map[start][cur] = 1;

	for (int i = 0; i < point[cur].size(); i++) {
		if (!map[start][point[cur][i]])
			dfs(start, point[cur][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp) {
				point[i].push_back(j);
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < point[i].size(); j++)
			dfs(i, point[i][j]);

		for (int k = 0; k < N; k++)
			cout << map[i][k] << ' ';

		cout << endl;
	}
}

// chkstk.asm을 찾을 수 없음 오류 발생. VS에 기본 스택사이즈가 1MB인데 해당 크기보다 더 큰 배열을 스택에 선언할 경우 발생
// 스택사이즈 늘려서 해결

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int map[1001][1001];
	int N, T;
	vector<int> answer;
	cin >> N >> T;
	vector<bool> chk;
	vector<pair<int, int>> city;
	for (int i = 1; i <= N; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		if (s)
			chk.push_back(true);
		else
			chk.push_back(false);
		city.push_back({x, y});
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++)
			map[i][j] = 3000;
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (chk[i] && chk[j]){
				if (abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second) > T)
					map[i + 1][j + 1] = map[j + 1][i + 1] = T;
				else
					map[i + 1][j + 1] = map[j + 1][i + 1] = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
			}
			else {
				map[i + 1][j + 1] = map[j + 1][i + 1] = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];
			}
		}
	}
	int M;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int tx, ty;
		cin >> tx >> ty;
		answer.push_back(map[tx][ty]);
	}
	for (int i = 0; i < M; i++)
		cout << answer[i] << "\n";
}

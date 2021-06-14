#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int N, M;
	vector<int> map[201];
	vector<int> seq;
	bool findAnswer = true;
	cin >> N >> M;
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (temp) map[i].push_back(j);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		seq.push_back(temp);
	}

	int idx = 0;
	while (idx != M - 1) {
		bool visited[201] = { false };
		bool next = false;
		queue<int> que;
		que.push(seq[idx]);
		int target = seq[idx + 1];
		visited[seq[idx]] = true;
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == target) {
				next = true;
				break;
			}
			for (int i = 0; i < map[cur].size(); i++) {
				if (visited[map[cur][i]]) continue;
				que.push(map[cur][i]);
				visited[map[cur][i]] = true;
			}
		}
		if (!next) {
			findAnswer = false;
			break;
		}
		idx++;
	}
	if (findAnswer) cout << "YES";
	else cout << "NO";
	return 0;
}

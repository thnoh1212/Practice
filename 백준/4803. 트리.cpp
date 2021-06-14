#include <iostream>
#include <vector>

using namespace std;

bool* visited;
vector<int>* map;
int answer;
bool flag;

void dfs(int prePos, int curPos) {
	for (int i = 0; i < map[curPos].size(); i++) {
		if (map[curPos][i] == prePos) continue;

		if (visited[map[curPos][i]]) {
			if(flag){
				answer -= 1;
				flag = false;
			}
			break;
		}
		else {
			visited[map[curPos][i]] = true;
			dfs(curPos, map[curPos][i]);
		}
	}
}


int main(){
	int Case = 1;
	while (true) {
		int n, m;
		answer = 0;
		cin >> n >> m;
		if (n == 0) break;

		visited = new bool[n+1];
		map = new vector<int>[n+1];
		for (int i = 1; i <= n; i++) visited[i] = false;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]){
				flag = true;
				answer += 1;
				visited[i] = true;
				dfs(i, i);
			}
		}
		cout << "Case " << Case << ": ";
		if (answer == 1)
			cout << "There is one tree.\n";
		else if (answer == 0)
			cout << "No trees.\n";
		else
			cout << "A forest of " << answer << " trees.\n";
		
		Case += 1;
	}
	return 0;
}

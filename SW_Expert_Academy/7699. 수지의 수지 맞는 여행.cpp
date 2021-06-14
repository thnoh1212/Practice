#include<iostream>
#include <string>
#include <vector>

using namespace std;

//2 ^ 27  - 1= 134217727;

int moves[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int answer;
int R, C;
char map[20][20];

void dfs(int i, int j, int chk, int cnt) {
	answer = std::max(answer, cnt);
    if(answer == 26) return;
	for (int k = 0; k < 4; k++) {
		int next_i = i + moves[k][0];
		int next_j = j + moves[k][1];
		
		if (next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) continue;
		if (chk & (1 << (map[next_i][next_j] - 'A' + 1)))
			dfs(next_i, next_j, chk ^ (1 << (map[next_i][next_j] - 'A' + 1)), cnt + 1);
	}
}

int main(int argc, char** argv)
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = 0;
		cin >> R >> C;
		int chk = 134217727;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
			}
		}
		chk ^= 1 << (map[0][0] - 'A' + 1);
		dfs(0, 0, chk, 1);
		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}

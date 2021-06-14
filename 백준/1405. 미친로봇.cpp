#include <iostream>
#include <iomanip> 

using namespace std;

/*
* 백준 1405 미친로봇
* 
* 단순한 경로: 로봇이 N번 이동하며 같은 자리를 단 한번도 밟지 않는 경로
* 
* N번을 이동하는 모든 경우의 수를 확인하며 이동 도중에 중복지점을 밟은 경우 이동 종료
* N번을 모두 이동하고도 중복지점을 밟지 않은 경우. 즉 단순한 경로인 경우 해당 경로처럼 
  이동할 확률을 answer값에 더해줌
* 
* 확률은 100보다 작거나 같은 자연수로 주어지기에 /100하여 저장.
* 이동횟수인 N의 최대 크기는 14 이므로 배열의 크기를 29로 설정 후 정가운데를 기점으로 시작
* 오차범위가 10^-9이므로, 정확도 설정 필요
*/
int moves[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
bool visited[29][29] = { false };
int N;
double answer = 0;
double percent[4] = { 0 };

void dfs(int i, int j, int cnt, double p) {
	if (cnt == N) {
		answer += p;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int next_i = i + moves[k][0];
		int next_j = j + moves[k][1];
		if (!visited[next_i][next_j]) {
			visited[next_i][next_j] = true;
			dfs(next_i, next_j, cnt + 1, p * percent[k]);
			visited[next_i][next_j] = false;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> percent[i];
		percent[i] /= 100;
	}
	visited[14][14] = true;
	dfs(14, 14, 0, 1.0);
	
	cout << setprecision(10) <<  answer << "\n";
}

/*
  DFS문제
  배추의 갯수가 한개인 경우는 어느 위치에 심던 상관없이 한마리의 지렁이만 필요하므로 DFS를 진행할 필요가 없음
  하지만 값을 받는 과정까지 무시할 경우 다음 입력값에 영향을 주므로 값은 입력받되 DSFS과정은 진행하지 않음
  테스트 케이스의 수만큼 과정을 진행할 필요가 있으므로 True/False 가 아닌 T_c값으로 배추의 위치 밑 check 표시 후
  T_c값과 다른 모든 값은 false와 마찬가지로 진행
*/
#include <iostream>
#include <vector>
using namespace std;

int map[51][51];
int check[51][51];
int x, y, num;

void dfs(int cur_y, int cur_x, int T_c) {
	int move[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
	
	for (int i = 0; i < 4; i++) {
		int next_x = cur_x + move[i][0];
		int next_y = cur_y + move[i][1];
		if(next_x >= 0 && next_x < x && next_y >= 0 && next_y < y){
			if (map[next_y][next_x] == T_c && check[next_y][next_x] != T_c) {
				check[next_y][next_x] = T_c;
				dfs(next_y, next_x, T_c);
			}
		}
	}
}

int main()
{
	int T_c, count = 0;

	cin >> T_c;

	for (int i = 1; i <= T_c; i++) {
		
		cin >> x >> y >> num;

		for (int j = 1; j <= num; j++) {
			int temp_1, temp_2;
			cin >> temp_1 >> temp_2;
			map[temp_2][temp_1] = i;
		}
		if (num != 1) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < x; k++) {
					if (map[j][k] == i && check[j][k] != i) {
						dfs(j, k, i);
						count++;
					}
				}
			}
		}
		else if (num == 1)
			count = 1;

		cout << count << endl;
		count = 0;
		
	}
}

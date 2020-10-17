#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int moves[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int R, C, K;
	cin >> R >> C >> K;
	int curI = 0, curJ = 0;
	int temp = 2 * (R + C) - 4;
	if (K > R * C) {
		cout << "0";
		return 0;
	}
	while (K > temp) {
		K -= temp;
		R -= 2;
		C -= 2;
		curI++;
		curJ++;
		temp = 2 * (R + C) - 4;
		if (R < 2 || C < 2) {
			break;
		}
	}
	int idx = 0;
	int addI = 1, addJ = 1;
	K -= 1;
	while (K != 0) {
		addI += moves[idx][0];
		addJ += moves[idx][1];
		K--;
		if (addI <= 0 || addJ <= 0 || addI > C || addJ > R) {
			addI -= moves[idx][0];
			addJ -= moves[idx][1];
			idx += 1;
			K++;
		}
	}
	cout << curJ + addJ << " " << curI + addI;

	return 0;
}

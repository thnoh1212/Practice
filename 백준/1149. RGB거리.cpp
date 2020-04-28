#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int map[1001][3];
	int price_map[1001][3];
	int N, answer;


	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> map[i][0] >> map[i][1] >> map[i][2];
		if(i == 1){
			price_map[i][0] = map[i][0];
			price_map[i][1] = map[i][1];
			price_map[i][2] = map[i][2];
		}
		else{
			for (int j = 0; j < 3; j++) {
				if (j == 0) 
					price_map[i][j] = std::min(price_map[i - 1][1], price_map[i - 1][2]) + map[i][j];
				else if (j == 1) 
					price_map[i][j] = std::min(price_map[i - 1][0], price_map[i - 1][2]) + map[i][j];
				else 
					price_map[i][j] = std::min(price_map[i - 1][0], price_map[i - 1][1]) + map[i][j];
			}
		}
	}
	answer = std::min(std::min(price_map[N][0], price_map[N][1]), price_map[N][2]);
	cout << answer << endl;
}

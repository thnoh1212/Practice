#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t_c;
	cin >> t_c;

	for (int i = 0; i < t_c; i++) {
		int H, W, N;
		string answer = "";
		cin >> H >> W >> N;

		int floor = N % H;
		N = N / H + 1;
		if (floor == 0){
			floor = H;
			N -= 1;
		}
		if (N < 10) {
			answer = '0' + to_string(N);
			answer = to_string(floor) + answer;
		}
		else
			answer = to_string(floor) + to_string(N);

		cout << answer << endl;
	}
}

// 시간초과를 피하기 위해 미리 출력되는 횟수를 계산하여 저장한 후 입력받은 값에 맞춰 답 출력
#include <iostream>

using namespace std;

int main()
{
	int answer[41][2] = { 0, 0 };
	answer[0][0] = { 1 };
	answer[0][1] = { 0 };
	answer[1][0] = { 0 };
	answer[1][1] = { 1 };

	for (int i = 2; i <= 40; i++) {
		answer[i][0] = answer[i - 1][0] + answer[i - 2][0];
		answer[i][1] = answer[i - 1][1] + answer[i - 2][1];
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		cout << answer[temp][0] << " " << answer[temp][1] << endl;
	}

}

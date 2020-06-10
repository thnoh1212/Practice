#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int floors[301];
	int answer[301];

	for (int i = 1; i <= N; i++)
		cin >> floors[i];

	answer[0] = floors[0] = 0;
	answer[1] = floors[1];
	answer[2] = floors[2] + floors[1];

	for (int i = 3; i <= N; i++) {
		// 2층 전에서 한번에 2칸을 뛰는 경우
		int jump = floors[i] + answer[i - 2];
		// 3층 전에서 점프하여 1층 전까지 온 후 두 층을 연달아 밟는 경우
		int up = floors[i] + floors[i - 1] + answer[i - 3];
		answer[i] = std::max(jump, up);
	}

	cout << answer[N];


}

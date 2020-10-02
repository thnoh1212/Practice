#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long arr[31][31];
	arr[0][0] = 1;
	arr[1][0] = arr[1][1] = 1;

	for (int i = 2; i <= 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				arr[i][j] = arr[i - 1][j];
			else if (j == i)
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cout << arr[b][a] << '\n';
	}
}

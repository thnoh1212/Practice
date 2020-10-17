#include <iostream>

using namespace std;

int main()
{
	long long arr[101] = { 0 };
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;
	arr[6] = 3;
	for (int i = 7; i <= 100; i++)
		arr[i] = arr[i - 1] + arr[i - 5];
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << arr[N] << "\n";
	}
	return 0;
}

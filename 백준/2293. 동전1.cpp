#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int coin[100];
	int value[10001] = { 0 };
	value[0] = 1;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0)
				value[j] += value[j - coin[i]];
		}
	}
	cout << value[k];

	return 0;
}

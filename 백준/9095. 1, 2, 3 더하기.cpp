#include <iostream>

using namespace std;

int cnt = 0;

void dfs(int now, const int target) {

	if (now == target) {
		cnt++;
		return;
	}
	else if (now > target) return;

	else {
		dfs(now + 1, target);
		dfs(now + 2, target);
		dfs(now + 3, target);
	}

}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		dfs(0, temp);
		cout << cnt << endl;
		cnt = 0;
	}
}

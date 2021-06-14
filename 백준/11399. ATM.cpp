#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int answer = 0, N, temp;
	vector<int> res;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		answer += temp;
		res.push_back(temp);
	}

	sort(res.begin(), res.end());
	temp = 0;
	for (int i = 0; i < N - 1 ; i++) {
		answer += (N - i - 1) * res[i];
	}
	cout << answer;
}

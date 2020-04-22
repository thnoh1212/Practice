#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B;

	cin >> A >> B;

	if (A.length() == B.length()) {
		int count = 0;
		for (int i = 0; i < A.length(); i++)
			if (A[i] != B[i]) count++;

		cout << count;
		return 0;
	}

	else {
		priority_queue<int, vector<int>, greater<int> > answer;
		for (int i = 0; i <= B.length() - A.length(); i++) {
			int count = 0;
			for (int j = i; j < i + A.length(); j++)
				if (A[j - i] != B[j]) count++;

			answer.push(count);
		}
		cout << answer.top();
		return 0;
	}

}

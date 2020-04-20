#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	N += M;
	vector<string> input, answer;
	input.resize(N);

	for (int i = 0; i < N; i++)
		cin >> input[i];

	sort(input.begin(), input.end());

	for (int i = 0; i < N-1; i++) {
		if (input[i] == input[i + 1]) 
			answer.push_back(input[i++]);
		
	}

	cout << answer.size() << endl;
	for (auto a = answer.begin(); a != answer.end(); a++)
		cout << *a << endl;

}

// auto사용

#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string words;
	int count = 0, N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> words;
		stack<char> check;
		
		for (auto a = words.begin(); a != words.end(); a++) {
			if (check.empty())
				check.push(*a);

			else {
				if (*a == check.top()) {
					check.pop();
				}
				else
					check.push(*a);
			}
		}
		if (check.empty())
			count++;
		else {
			while (!check.empty())
				check.pop();
		}
	}

	cout << count;
}

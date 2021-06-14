#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string word;
	vector<string> answer;

	cin >> word;

	while (word.length() != 0) {
		answer.push_back(word);
		word.erase(0,1);
	}

	sort(answer.begin(), answer.end());
	for (auto a = answer.begin(); a != answer.end(); a++)
		cout << *a << endl;

}

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string temp;

	while (getline(cin, temp) && temp != ".") {
		stack<char> answer;
		bool flag = true;
		for (auto a = temp.begin(); a != temp.end(); a++) {
			if (*a == '(' || *a == ')' || *a == '[' || *a == ']') {
				if (*a == '(' || *a == '[')
					answer.push(*a);
				else {
					if (*a == ']') {
						if (!answer.empty()) {
							if (answer.top() == '[')
								answer.pop();
							else {
								while (!answer.empty())
									answer.pop();
								flag = false;
								break;
							}
						}
						else {
							flag = false;
							break;
						}
					}
					else {
						if (*a == ')') {
							if(!answer.empty()){
								if (answer.top() == '(')
									answer.pop();
								else {
									while (!answer.empty())
										answer.pop();
									flag = false;
									break;
								}
							}
							else {
								flag = false;
								break;
							}
							
						}
					}

				}
			}
		}
		if (flag && answer.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		while (!answer.empty())
			answer.pop();
	}
}

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	stack<int> tower;
	stack<int> index;
	int N;
	cin >> N;
	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		if (tower.empty()) {
			cout <<"0 ";
			tower.push(temp);
			index.push(i);
		}
		else {
			if (tower.top() >= temp) {
				cout << index.top() << " ";
				tower.push(temp);
				index.push(i);
			}
			else {
				while (!tower.empty()) {
					if (tower.top() < temp) {
						tower.pop();
						index.pop();
					}
					else
						break;
				}
				if (tower.empty()) {
					cout <<"0 ";
					tower.push(temp);
					index.push(i);
				}
				else {
					cout << index.top() << " ";
					tower.push(temp);
					index.push(i);
				}

			}
		}
	}
	
	return 0;
}

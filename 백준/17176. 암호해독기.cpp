#include <iostream>
#include <string>

using namespace std;

int main() {

	int N;
	cin >> N;
	int chk[53] = { 0 };
	bool flag = true;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		chk[temp]++;
	}
	cin.ignore();
	string temp;
	getline(cin, temp);

	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] >= 'a' && temp[i] <= 'z')
			chk[temp[i] - 'a' + 27]--;
		else if (temp[i] >= 'A' && temp[i] <= 'Z') 
			chk[temp[i] - 'A' + 1]--;
		else if(temp[i] == ' ')
			chk[0]--;
	}

	for (int i = 0; i < 53; i++) {
		if (chk[i] != 0) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << 'y';
	else
		cout << 'n';

	return 0;
}

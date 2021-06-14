#include <iostream>
#include <queue>

using namespace std;

int main()
{
	bool chk[100000] = { false };
	int A, B;
	cin >> A >> B;
	queue<pair<int, int>> temp;

	temp.push(make_pair(B, 0));
	
	while (!temp.empty()) {
		int position = temp.front().first;
		int count = temp.front().second;
		temp.pop();

		if(position == A){
			cout << count;
			break;

		}
		if (position % 2 == 0 && position > A) {
			if (position / 2 == A){
				cout << count + 1;
				break;
			}
			else if(!chk[position/2]){
				temp.push(make_pair(position / 2, count + 1));
				//cout << position/2 << " " << count + 1 << endl;
				chk[position / 2] = true;
			}
		}
		if (position - 1 == A || position + 1 == A){
			cout << count + 1;
			break;
		}
		
		if (!chk[position - 1] && position - 1 >= 0){
			//cout << position - 1 << " " << count + 1 << endl;
			temp.push(make_pair(position - 1, count + 1));
			chk[position - 1] = true;
		}
		if (!chk[position + 1] && position + 1 <= 100000){
			//cout << position + 1 << " " << count + 1 << endl;
			temp.push(make_pair(position + 1, count + 1));
			chk[position + 1] = true;
		}
	}

	return 0;
}

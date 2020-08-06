/*
  map자료구조는 값이 자동으로 정렬되어 들어감. 내림차순
  중복 key값을 허용하지 않음
  
  숫자가 중복되는 경우 한번 만들어진 숫자는 그 후 몇번을 더 교환해도 만들 수 있음
  숫자가 중복되지 않는 경우 2번의 추가적인 교환을 통해 원래 숫자로 돌아올 수 있음
  0
*/


#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct t_word {
	string word;
	int count;
};

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		string number, standard;
		int change;
		cin >> number >> change;
		standard = number;
		bool chk[10] = { false };
		bool flag = false;
		for (int i = 0; i < number.length(); i++){
			if (!chk[(number[i] - '0')])
				chk[(number[i] - '0')] = true;
			else{
				flag = true;
				break;
			}
		}
		sort(number.begin(), number.end());
		map<string, int> test;
		do {
			string word = "";
			for (int i = 0; i < number.size(); i++)
				word += number[i];
			test.insert(make_pair(word, 0));
		} while (next_permutation(number.begin(), number.end()));
		queue<t_word> check;
		check.push({ standard, 0 });
		while (!check.empty()) {
			string temp = check.front().word;
			int count = check.front().count;
			check.pop();
			if (count >= change) continue;
			for (int i = 0; i < number.length()-1; i++) {
				for (int j = i + 1; j < number.length(); j++) {
					string chk = temp;
					char swap = chk[i];
					chk[i] = chk[j];
					chk[j] = swap;
					auto it = test.find(chk);
					if (it->second == 0) {
						it->second = count + 1;
						check.push({ chk, count + 1 });
					}
				}
			}
		}
		for (auto it = test.rbegin(); it != test.rend(); it++) {
			if (flag) {
				if (it->second != 0) {
					cout << "#" << test_case << " " << it->first << "\n";
					break;
				}
			}
			else{
				if (it->second != 0 && (change - it->second) % 2 == 0) {
					cout << "#" << test_case << " " << it->first << "\n";
					break;
				}
			}
		}
	}
	return 0;
}

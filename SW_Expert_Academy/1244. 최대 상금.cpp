#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct t_word { // 현재 숫자 정보 및 해당 숫자를 만들기 위한 최소 swap횟수 저장.
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
		cin >> number >> change; // 후에 나올 next_permutation 함수를 사용하기 위해 값을 변경해야 하기 때문에 기준값을 저장할 standard 문자열 추가 선언.
		standard = number;
		bool chk[10] = { false }; // 중복숫자 확인용 bool배열
		bool flag = false;
		for (int i = 0; i < number.length(); i++){
			if (!chk[(number[i] - '0')])
				chk[(number[i] - '0')] = true;
			else{	// 해당 인덱스의 값이 true인경우 이미 그 숫자가 문자열에 포함되어 있으므로 flag = true 및 반복문 탈출
				flag = true;
				break;
			}
		}
		sort(number.begin(), number.end()); // next_permutation 함수는 숫자의 크기대로 순열을 만드므로 사전적으로 가장 작은 문자열로 정렬
		map<string, int> test;
		do { // 순열 생성. 이를 통해 입력받은 문자열을 swap을 통해 만들 수 있는 모든 문자 탐색
			string word = "";
			for (int i = 0; i < number.size(); i++)
				word += number[i];
			test.insert(make_pair(word, 0)); // 문자 정보를 map에 저장. 아직 입력받은 교환 횟수로 해당 문자열을 만들 수 있을지 알수 없기 때문에 cnt값은 0
		} while (next_permutation(number.begin(), number.end()));
		queue<t_word> check;	// 문자 교환작업을 위한 큐 선언
		check.push({ standard, 0 }); //기준값 삽입
		while (!check.empty()) {
			string temp = check.front().word;
			int count = check.front().count;
			check.pop();
			if (count >= change) continue;
			for (int i = 0; i < number.length()-1; i++) {
				for (int j = i + 1; j < number.length(); j++) { // swap작업
					string chk = temp;
					char swap = chk[i];
					chk[i] = chk[j];
					chk[j] = swap;
					auto it = test.find(chk);
					if (it->second == 0) { // swap작업을 통해 만들어진 문자열이 이미 만들어진 적 있는 문자열이 아닌 경우
						it->second = count + 1; // 변환횟수 저장
						check.push({ chk, count + 1 }); // 변환한 문자열 큐에 삽입
					}
				}
			}
		}
		for (auto it = test.rbegin(); it != test.rend(); it++) { // 저장된 문자열 탐색
			if (flag) { // 중복된 숫자가 있는 경우 최댓값을 만든 이후 중복된 숫자간의 교환으로 최댓값을 유지할 수 있기 때문에 만들수 있는 수 중 최대값 출력
				if (it->second != 0) { 
					cout << "#" << test_case << " " << it->first << "\n";
					break;
				}
			}
			else{ // 중복된 숫자가 없는 경우 2번의 교환을 통해 원래의 값으로 돌아올 수 있기 때문에 c - cnt의 값이 2로 나누어 떨어지는 값 중 최댓값 줓력
				if (it->second != 0 && (change - it->second) % 2 == 0) {
					cout << "#" << test_case << " " << it->first << "\n";
					break;
				}
			}
		}
	}
	return 0;
}

/*
 처음에는 erase를 사용하여 string에서 찾은 문자열을 삭제하는 방식으로 구현
 이 경우 같은 단어를 두번 지울수 없어 찾은경우에 i-- 삽입
 이 경우 사이에 문자열이 사라지며 새로운 알파벳이 생기는 경우가 발생
 이를 방지하기 위해 replace 함수 사용하여 삭제한 자리에 공백을 삽입하여 문제 해결
 string::size_type 처음 사용
 이 문제에서는 int형으로 사용해도 큰 문제가 없으나
 string의 크기가 int로 담을 수 있는 한계를 벗어난 경우 발생하는 에러를 방지하기 위해
 string::size_type 사용
*/


#include <iostream>
#include <string>

using namespace std;

const string check[8] = {
		"c=",
		"c-",
		"dz=",
		"d-",
		"lj",
		"nj",
		"s=",
		"z="
};

int main()
{
	string temp;
	int count = 0;
	string::size_type n;
	cin >> temp;
	int answer = temp.size();
	for (int i = 0; i < 8; i++) {
		n = temp.find(check[i]);

		if (n == string::npos)
			continue;
		else {
			temp.replace(n, check[i].size(), " ");
			count++;
			answer -= check[i].size();
			i--;
		}
	}
	count += answer;
	cout << count;
}

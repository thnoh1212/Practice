#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string A, B;
		cin >> A >> B;
		int answer = 0;
		while (A.find(B) != string::npos) {
			A.erase(A.find(B), B.length());
			answer++;
		}
		cout << "#" << test_case << " " << answer + A.length() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

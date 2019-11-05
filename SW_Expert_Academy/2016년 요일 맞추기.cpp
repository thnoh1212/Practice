#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int month[13] = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int m, d, answer = 4;
        cin >> m >> d;
        for(int i = 1; i < m; i++)
            answer += month[i];
        answer += d - 1;
        answer %= 7;
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

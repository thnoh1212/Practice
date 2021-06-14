/* 자료의 크기가 100자리 이상의 정수.
   정수형 자료형에 담을 수 없으므로 string형 사용. */
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		string temp;
        cin >> temp;
        if((temp[temp.size()-1] - '0') % 2 == 0)
            temp = "Even";
        else
            temp = "Odd";
        cout << "#" << test_case << " " << temp << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

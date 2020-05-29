#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin >> T;
	int test_case;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        double A, B;
		cin >> A >> B;
        double s1 = (1 - A) * B;
        double s2 = A * (1 - B) * B;
        
        if(s2 > s1)
            cout << "#" << test_case << " YES\n";
        else
            cout << "#" << test_case << " NO\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

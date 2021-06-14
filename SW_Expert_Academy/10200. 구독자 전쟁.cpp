#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a, b, c;
        cin >> a >> b >> c;
        
        int Max = min(b, c);
        int Min = ((b + c - a) < 0) ? 0 : (b + c) - a;
        
        cout << "#" << test_case << " " << Max << " " << Min << "\n";
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

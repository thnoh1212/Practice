#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int P_n, C_n;
        cin >> C_n >> P_n;
        
        if(C_n % P_n == 0)
            cout << "#" << test_case << " 0\n";
        else
            cout << "#" << test_case << " 1\n";     
	}
	return 0;
}

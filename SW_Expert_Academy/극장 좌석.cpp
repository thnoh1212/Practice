#include<iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        int sum = 0;
		cin >> N;
        int per[N];
        for(int i = 0; i < N; i++)
            cin >> per[i];
        
        sort(per, per+N);
        for(int i = 0; i < N-1; i++)
           	sum += per[i];
        
        sum += 2*per[N-1] + N;
        cout << "#" << test_case << " " << sum << " \n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

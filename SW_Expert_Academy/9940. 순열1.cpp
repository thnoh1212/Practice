#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        long long N;
        cin >> N;
        long long sum = 0;
        for(int i = 0; i < N; i++){
         	long long temp;
            cin  >> temp;
            sum += temp;
        }
        if(sum == (N * (N+1)) /2)
            cout << "#" << test_case << " " << "Yes\n";
        else
            cout << "#" << test_case << " " << "No\n";
            
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

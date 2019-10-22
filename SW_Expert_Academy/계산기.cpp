#include<iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, temp = 0, answer = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
        	cin >>temp;
            if(i == 0)
                answer = temp;
            else
                answer = max((answer + temp), (answer * temp));
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

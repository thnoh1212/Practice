#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int chk[12] = {0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 16, 4};
        int N, test_1 = 0, test_2 = 0;
        int sum = 0;
        cin >> N;
        for(int i = 0; i <N; i++){
            int temp;
            cin >> temp;
        	chk[temp]--;
            sum += temp;
        }
        sum = 22 - sum;
        if(sum > 11)
            cout << "#" << test_case << " GAZUA\n";
        else{
        	for(int i = sum; i < 12; i++)
         		test_1 += chk[i];
            for(int i = sum - 1; i >= 2; i--)
         		test_2 += chk[i];
            if(test_1 >= test_2)
                cout << "#" << test_case << " STOP\n";
            else
                cout << "#" << test_case << " GAZUA\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

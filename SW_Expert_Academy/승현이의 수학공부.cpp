#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio();
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int N;
        string temp;
        cin >> N >> temp;
        N -=1;
        int sum = 0;
        int i = 0;
        while(i != temp.size()){
        	sum += temp[i] - '0';
            i++;
        }
        sum %= N;
        cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

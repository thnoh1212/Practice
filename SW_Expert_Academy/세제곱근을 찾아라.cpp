#include<iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		double answer;
        int temp;
        long long number;
        cin >> number;
        answer = pow(number, 1.0 / 3.0);
        temp = floor(pow(number, 1.0 / 3.0) + 0.5);
       	answer -= temp;
        answer = abs(answer);
        if(answer > 0.000001)// double형과 int형을 비교하므로 오차값을 생각해야함
            temp = -1;
        
       cout << "#" << test_case << " " << temp << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

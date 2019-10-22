#include<iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int N;
        int  sum = 0;
        cin >> N;
        N = pow(2, N);
        int *temp = new int[N];
        for(int i = 0; i < N; i++)
            cin >> temp[i];
            
        while(N != 1){
            int count = 0;
        	for(int i = 0; i < N; i += 2){
            	sum += abs(temp[i] - temp[i+1]);
                temp[count] = max(temp[i], temp[i+1]);
                count++;
            }
            N /= 2;
        }
        cout <<"#" << test_case << " " << sum << "\n";
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

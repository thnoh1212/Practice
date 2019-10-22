#include<iostream>
#include<cmath>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
    int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case){
		unsigned long long N;
        cin >> N;
		cout << "#" << test_case << " " << (N*N - (N-1)*2) * 2 -1 << " " <<  N*N*2-1 << "\n"; 
         }
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		long long K;
        cin >> K;
        K -= 1;
        if(K % 2 == 0){
        	if(K % 4 == 0)
				K = 0;
            else
                K = 1;
        }
        else{
        	while(K % 2 != 0)
                K /= 2;
            if(K % 4 == 0)
				K = 0;
            else
                K = 1;
        }
        cout << "#" << test_case << " "  << K <<"\n";
	}
	return 0;
}

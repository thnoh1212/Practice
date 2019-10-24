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
		int N;
        double avg = 0, P;
        int x;
        cin >> N;
		for(int i = 0; i < N; i++){
	        cin >> P >> x;
			avg += P * x;
        }
        cout << fixed;
        cout.precision(6);
        cout << "#" << test_case << " " << avg << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

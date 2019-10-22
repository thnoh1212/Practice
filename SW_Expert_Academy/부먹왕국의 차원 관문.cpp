#include<iostream>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int N, D;
        cin >> N >> D;
        int temp, L = 0;
        int n_gate = 0;
        for(int i = 0; i < N; i++){
         	cin >> temp;
            if(temp == 0){
                L += 1;
            }
            else{
                    n_gate += L / D;
                	L = 0;
           }
        }
        n_gate += L / D;
		cout << "#" << test_case << " " << n_gate << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

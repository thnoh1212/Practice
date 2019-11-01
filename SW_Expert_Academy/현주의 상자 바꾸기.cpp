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
		int N, Q;
        cin >> N >> Q;
        int *temp = new int[N+1];
        
        for(int i = 1; i <= Q; i++){
        	int L, R;
            cin >> L >> R;
            for(int j = L; j <= R; j++){
            	temp[j] =i;
            }
        }
        cout << "#" << test_case;
        for(int i = 1; i <= N; i++)
            cout << " " << temp[i];
        cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

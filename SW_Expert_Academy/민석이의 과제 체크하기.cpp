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
		cout << "#" << test_case;
        int student[101] = {0};
        int N, K;
        cin >> N >> K;
        for(int i = 0; i < K; i++){
        	int temp;
            cin >> temp;
            student[temp] = 1;
        }
		for(int i = 1; i <= N; i++){
        	if(student[i] != 1)
                cout << " " << i;
        }
        cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

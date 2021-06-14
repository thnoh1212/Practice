#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, B, E;
        int answer = 0;
        cin >> N >> B >> E;
        int clock[N];
        for(int i = 0; i < N; i++)
            cin >> clock[i];
        
        for(int j = 0; j < N; j++){
            int k = B-E;
        	while(k <= B+E){
                if(k++ % clock[j] == 0){
                	answer++;
                    break;
                }
        	}
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

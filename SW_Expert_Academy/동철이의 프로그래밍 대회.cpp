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
		int N, M, count = 0, max = 0;
       	cin >> N >> M;
        for(int i = 0; i < N; i++){
            int sum = 0;
            int temp = 0;
            for(int j = 0; j < M; j++){
            	cin >> temp;
                sum += temp;
            }
            if(sum > max){
            	max = sum;
                count = 1;
            }
            else if(sum == max)
                count += 1;
        } 
        cout << "#" << test_case << " " << count << " " << max << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

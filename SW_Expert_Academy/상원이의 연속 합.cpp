#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio();
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int N;
        cin >> N;
		int count = 1;
        for(int i = 1; i <= N/2+1; i++){
            int sum = i;
        	for(int j = i+1; j <= N/2+1; j++){
            	sum += j;
                if(sum == N){
                    count += 1;
                    break;
                }
                else if(sum > N)
                    break;
            }
        }
		cout <<"#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

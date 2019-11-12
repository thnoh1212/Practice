#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int N, K, temp, sum = 0;
        cin >> N >> K;
        priority_queue<int> score;
    	for(int i = 0; i < N; i++){
        	cin >> temp;
            score.push(temp);
        }
        for(int j = 0; j < K; j++){
        	sum += score.top();
            score.pop();
        }
        cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

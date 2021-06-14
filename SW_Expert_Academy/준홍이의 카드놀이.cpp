#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int N, M, max = 0;
        cin >> N >> M;
        vector<int> answer;
        cout << "#" << test_case;
        int *temp = new int[N+M+1];
         for(int k = 0; k <= N+M; k++)
        	temp[k] = 0;
        
        for(int i = 1; i <= N; i++){
        	for(int j = 1; j <= M; j++)
            	temp[i + j] += 1;
        }
        for(int k = 2; k <= N+M; k++){
        	if(temp[k] > max){
            	answer.clear();
                max = temp[k];
                answer.push_back(k);
            }
            else if(temp[k] == max)
                answer.push_back(k);
        }
        
        for(int i = 0; i < answer.size(); i++)
            cout << " " << answer[i];
		cout << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

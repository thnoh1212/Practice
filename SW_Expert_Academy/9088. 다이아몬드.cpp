#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int N, K;
        cin >> N >> K;
        vector<int> Dia;
        vector<int> answer;
		for(int i = 0; i < N; i++){
        	int temp;
            cin >> temp;
            Dia.push_back(temp);
        }
        sort(Dia.begin(), Dia.end());
		
        for(int i = 0; i < N - 1; i++){
            int temp = 1;
        	for(int j = i + 1; j < N; j++){
            	if(Dia[j] - Dia[i] <= K)
                    temp++;
                else
                    break;
            }
            answer.push_back(temp);
        }
        sort(answer.begin(), answer.end());
        
        
        
        cout << "#" << test_case << " " << answer[answer.size()-1]  << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

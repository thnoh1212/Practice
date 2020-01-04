#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio();
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, Max, answer = -1;
        cin >> N >> Max;
        vector<int> W_snack;
        for(int i = 0; i < N; i++){
        	int temp;
            cin >> temp;
            W_snack.push_back(temp);
        }
        sort(W_snack.begin(), W_snack.end());
        int i = 0, j = W_snack.size() - 1;
        while(i != j){
        	int sum = W_snack[i] + W_snack[j];
            if(sum > Max)
                j--;
            else if(sum == Max){
            	answer = sum;
                break;
            }
            else{
                if(answer < sum)
            		answer = sum;
                i++;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

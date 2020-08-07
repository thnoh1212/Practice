#include<iostream>
#include<vector>
#include <cmath>

using namespace std;
vector<int> input;
vector<int> test[10];

void bin_search(int L, int R, int count){
	int mid = (L + R)/2;
	count += 1;
	if(L == R){
		test[count].push_back(input[L]);		
		return;
	}
	else{
		
		bin_search(L, mid-1, count);
		bin_search(mid+1, R, count);
	}
	test[count].push_back(input[mid]);
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int depth, count = -1;
        cin >> depth;
        int num = pow(2, depth) - 1;
        for(int i = 0; i < num; i++){
        	int temp;
            cin >> temp;
            input.push_back(temp);
        }
        bin_search(0, input.size()-1, count);
        cout << "#" << test_case << " ";
        for(int i = 0; i < depth; i++){
			for(int j = 0; j < test[i].size(); j++){
				cout << test[i][j] << " ";
			}
            test[i].clear();
			cout << "\n";
		}
       	input.clear();

    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

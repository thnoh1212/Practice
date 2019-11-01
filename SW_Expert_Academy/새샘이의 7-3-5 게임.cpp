#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){
    return a > b; 
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int temp[7];
        vector<int> check;
        for(int i = 0; i < 7; i++)
            cin >> temp[i];
    
        for(int i = 0; i <7; i++)
            for(int j = i+1; j < 7; j++)
                for(int k = j + 1; k < 7;  k++)
            		check.push_back(temp[i] + temp[j] + temp[k]);
            
        sort(check.begin(), check.end(), comp);
        int count = 0, test  = 0;
        for(int i = 0; i <check.size(); i++){
            if(test != check[i]){
                test = check[i];
                count++;
            }
            if(count == 5)
                break;
        }
        cout <<"#" << test_case << " " << test << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

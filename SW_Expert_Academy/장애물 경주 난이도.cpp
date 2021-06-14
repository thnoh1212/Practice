#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int N;
        cin >> N;
        int temp;
        vector<int> height;
        for(int i = 0; i < N; i++){
            cin >> temp;
            height.push_back(temp);
        }
        temp = height[0];
        int max = 0, min = 0;
        for(int i = 1; i < height.size(); i++){
        	temp -= height[i];
            if(max < temp)
            	max = temp;
            if(min > temp)
                   min = temp;
            temp = height[i];
        }
        cout << "#" << test_case << " " << abs(min) << " " << abs(max) << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		string words;
        int hi_num;
        cin >> words >> hi_num;
        int *location = new int[hi_num];
        for(int i = 0; i < hi_num; i++)
            cin >> location[i];
        
        sort(location, location+hi_num);
        
        for(int i = 0; i < hi_num; i++)
        	words.insert(location[i] + i, "-");
        
        cout << "#" << test_case << " " << words << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

// string.insert 사용법 확인

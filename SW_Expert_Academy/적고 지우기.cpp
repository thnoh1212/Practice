#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		bool answer[10] = {0};
        string temp;
        cin >> temp;
        int count = 0;
        for(int i = 0; i < temp.size(); i++)
        	answer[temp[i] - '0'] = !answer[temp[i] - '0'];
            
        for(int i = 0; i < 10; i++){
            if(answer[i])
                count += 1;
        }
        cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

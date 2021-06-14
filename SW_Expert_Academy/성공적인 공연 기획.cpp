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
		int count = 0, answer = 0;
		string temp;
        cin >> temp;
        for(int i = 0; i < temp.size(); i++){
        	if(count >= i)
            	count += temp[i] - '0';
            else{
                answer += i - count;
            	count += temp[i] - '0' + i - count; 
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

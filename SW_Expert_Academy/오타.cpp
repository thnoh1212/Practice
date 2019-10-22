#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        string temp;
        cin >> temp;
        unsigned long long answer = 1;
        for(int i = 0; i < temp.length(); i++){
            int check = 0;
        	if(i == 0){
                if(temp[i] != temp[i+1])
                	answer *= 2;
            }
            else if( (i+1) == temp.length()){
                if(temp[i] != temp[i-1])
                	answer *= 2;
            }
            else{
                check = (temp[i-1] == temp[i]) + (temp[i] == temp[i+1]) + (temp[i-1] == temp[i+1]);
                if(check > 1)
                    continue;
                else if(check == 1)
                    answer *= 2;
                else
                    answer *= 3;
            }
            answer %= 1000000007;
        }
        cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

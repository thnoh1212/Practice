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
        int temp[10] = {0};
        string number;
        cin >> number;
		int count = 0;
        
       	for(int i = 0; i < number.size(); i++){
         	int to_n = number[i] - '0';
            if(temp[to_n] != 0) continue;
            temp[to_n] = 1;
            count += 1;
            if(count == 9) break;
        }
        cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

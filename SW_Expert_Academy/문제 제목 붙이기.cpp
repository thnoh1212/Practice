#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
        int N, count = 0;
        cin >> N;
        string temp;
        int title[26] = {0};
        for(int i = 0; i < N; i++){	
        	cin >> temp;
            title[temp[0] - 'A'] += 1;
        }
        
        for(int j = 0; j < 26; j++){
        	if(title[j] != 0)
                count += 1;
            else
                break;
        }
        cout << "#" << test_case << " " << count << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

#include<iostream>
#include <string>

using namespace std;

int check(char A){
    switch(A){
        case 'B':
            return 2;
        case 'A':
        case 'D':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
            return 1; 
        default:
            return 0;
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio();
    cin.tie();
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		string temp_1, temp_2;
        string answer = "SAME";
        cin >> temp_1 >> temp_2;
        if(temp_1.size() != temp_2.size())
    		answer = "DIFF";
        else{
        	for(int i = 0; i < temp_1.size(); i++){
            	if(check(temp_1[i]) != check(temp_2[i])){
                	answer = "DIFF";
                    break;
                }
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


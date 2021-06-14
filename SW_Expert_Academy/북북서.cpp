#include<iostream>
#include <string>
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
		string direction;
        cin >> direction;
        int answer = 0, count = 0, div = 1;
        for(int i = direction.size()-1; i > 0; i--){
        	if(direction[i] == 't'){
                if(i == direction.size()-1)
                    answer = 90;
                else{
                    answer = answer * 2 + 90;
                    div *= 2;
            	}
            	i -= 3;
            }
            else{
                if(i == direction.size()-1)
                    answer = 0;
                else{
                    answer = answer * 2 - 90;
                    div *= 2;
            	}
            	i -= 4;
        	}
            count += 1;
        } int flag = 0;
        while(flag == 0){
        	if(answer % 2 == 0 && div >= 2){
            	answer /= 2;
                div /= 2;
            }
            else
                flag = 1;
        }
       if(div == 1)
           cout << "#" << test_case << " " << answer << "\n";
        else
            cout << "#" << test_case << " " <<answer << "/" << div << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

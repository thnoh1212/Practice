/*
  정수형의 자릿수를 비교할때 굳이 문자열로 바꾼 후 +1로 찾을 필요없이
  간단하게 %, /연산자를 사용하여 비교하자.
  시간초과 발생 위험 있음.
*/

#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> number;
		vector<int> answer;
        int N;
        cin >> N;
    	for(int i = 0; i < N; i++){
            int temp;
        	cin >> temp;
            number.push_back(temp);
        }
        for(int  i = 0; i < number.size() - 1; i++){
            for(int j = i + 1; j < number.size(); j++){
            	int temp = number[i] * number[j];
                int check = temp % 10;
                bool flag = true;
                temp = temp / 10;
                while (temp > 0) {
                    if (check - 1 == temp%10) 
                        check--;
                  	else {
                        flag = false;
                        break;
                    }
                    temp = temp / 10;
                }
				if(flag)
                    answer.push_back(number[i] * number[j]);
        	}
        }
        sort(answer.rbegin(), answer.rend());
         if(answer.size() != 0)
         	cout << "#" << test_case << " " << answer[0] << '\n';
         else
         	cout << "#" << test_case << " " <<"-1\n";
    }
	return 0;
}

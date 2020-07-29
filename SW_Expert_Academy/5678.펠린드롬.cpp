#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer = 1;
        string temp;
        cin >>  temp;
        for(int i = 0; i < temp.length() - 1; i++){
        	for(int j = temp.length() - 1; j > i; j--){
            	if(temp[i] == temp[j]){
                	string word = temp.substr(i, j-i + 1);
                    if(word.length() < answer) break;
                    string c_word  = temp.substr(i, j-i + 1);
                    reverse(c_word.begin(), c_word.end());
                    if(word == c_word)
                        answer = word.length(); 
                }
            }
        }
        cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

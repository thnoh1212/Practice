/*
 조합 사용, 알파벳 26자를 각각 자릿수에 맞춰 2진수로 변환(ex. a = 1, b = 2, c = 4, d = 8 .....)
 그 후 or연산자를 사용하여 알파벳 세트가 완성되는지 확인
*/


#include<iostream>
#include<string>

using namespace std;

int alphabet[26];
const int complete = 67108863;
int answer = 0;
int word[15] = {0};
int N;

 void combination(int start, int cur_set);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    alphabet[0] = 1;
    for(int i = 1; i < 26; i++)
    	alphabet[i] = alphabet[i-1] * 2;
    int test_case;
	int T;
	cin>>T;    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
        	string temp;
            cin >> temp;
            int var = 0;
            for(int j = 0; j < temp.size(); j++)
            	var |= alphabet[temp[j] - 'a'];
            
            word[i] = var;
        }
        combination(0, 0);
        cout << "#" << test_case << " " <<  answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void combination(int start, int cur_set)
{
	if(cur_set == complete)
        answer += 1;
    	
    for(int i =  start; i < N; i++)
        combination(i+1,  cur_set | word[i]);
}

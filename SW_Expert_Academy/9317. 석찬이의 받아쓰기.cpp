#include<iostream>
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
        int N;
        cin >> N;
        string script, dictation;
        cin >> script >> dictation;
        int answer = 0;
        for(int i = 0; i < N; i++){
        	if(script[i] == dictation[i])
                answer += 1;
        }
        cout << "#" << test_case << " " << answer << "\n";
            
	}
	return 0;
}

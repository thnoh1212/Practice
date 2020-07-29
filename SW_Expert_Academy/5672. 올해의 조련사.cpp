#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        string birds = "";
        string answer = "";
        for(int i = 0; i < N; i++){
        	string temp = "";
            cin >> temp;
            birds += temp;
        }
        int cur_i = 0;
        int cur_j = birds.length() - 1;
        while(answer.length() != birds.length()){
        	if(birds[cur_i] < birds[cur_j]) answer += birds[cur_i++];
            else if(birds[cur_i] > birds[cur_j]) answer += birds[cur_j--];
            else{
            	int next_i = cur_i;
                int next_j = cur_j;
                bool flag = true;
                while(next_j > next_i){
                	if(birds[next_i] < birds[next_j]) break;
                    else if (birds[next_i] > birds[next_j]){
                    	flag = false;
                        break;
                    }
                    else{
                    	next_i++;
                        next_j--;
                    }
                }
                if(flag)
                    answer += birds[cur_i++];
                else
                    answer += birds[cur_j--];
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

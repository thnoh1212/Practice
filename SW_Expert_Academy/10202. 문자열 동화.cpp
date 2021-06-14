#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
          int answer = 0;
          string words[3] = { };
          int N;
          cin >> N;
          for(int i = 0; i < 3; i++)
            cin >> words[i];

          for(int i = 0; i < words[0].length(); i++){
            if((words[0][i] == words[1][i] && words[0][i] != words[2][i]) ||
                (words[0][i] != words[1][i] && words[0][i] == words[2][i]) ||
                  (words[0][i] != words[1][i] && words[1][i] == words[2][i]) )
                  answer++;
              else if(words[0][i] != words[1][i] && words[0][i] != words[2][i] && words[1][i] != words[2][i])
                  answer += 2;

          }
          cout << "#" << test_case << " " << answer << "\n";
      }
	return 0;
}

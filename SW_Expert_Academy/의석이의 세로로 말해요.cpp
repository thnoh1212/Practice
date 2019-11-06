#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
  	ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
   	int T = 0;
   	cin>>T;
   	for(test_case = 1; test_case <= T; ++test_case){
      	char temp[5][15] = { 0, };
        for(int i = 0; i < 5; i++)
            cin >> temp[i];
        cout << "#" << test_case << " ";
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 5; j++){
               	if(temp[j][i])
                	cout << temp[j][i];
            }
        }
        cout << '\n';
   }
   return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

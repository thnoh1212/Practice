#include <iostream>
#include <stack>

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
        int temp, count;
        cin >> count;
        stack<int> n_list;
        for(int i = 0; i < count; i++){
            cin >> temp;
         	if(temp == 0)
                n_list.pop();
            else
                n_list.push(temp);
        }
        int answer = 0;
        while(!n_list.empty()){
            answer += n_list.top();
         	n_list.pop();
        }
        cout << "#" << test_case << " " << answer << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

#include<iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer;
        int i, j, target_i, target_j;
        cin >> i >> j >> target_i >> target_j;
        int i_length = abs(i - target_i);
        int j_length = abs(j - target_j);
        
        if(i_length == j_length)
            answer = i_length * 2;
        else {
        	if(abs(i_length - j_length) >= 2 && abs(i_length - j_length) % 2 == 0)
                answer = max(i_length, j_length) * 2;
            else{
            	 answer = max(i_length, j_length) * 2 - 1;
            }
        }
        
        cout << "#" << test_case << " " << answer << endl;
            
	}
	return 0;
}

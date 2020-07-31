#include<iostream>
#include <vector>

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
        int N, count = 1;
        cin >> N;
		int check[10001] = {0};
        check[0] = 1;
       	for(int i = 1; i <= N; i++){
        	int temp;
            cin >> temp;
            int t_count = count;
            int num_chk = 0;
            for(int j = 0; j < 10001; j++){
            	if(check[j] != 0 && (check[j] <= i )){
                	num_chk++;
	    			if(check[j+temp] == 0){
                    	check[j + temp] = i + 1;
    	                count++;
                    }
                }
                if(num_chk == t_count)
                    break;
            }
        }
        cout << "#" << test_case << " " << count << "\n";
	}
	return 0;
}

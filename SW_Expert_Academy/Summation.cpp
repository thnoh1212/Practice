#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int temp;
        int min = 1000000;
        int max = 0;
        
        for(int i = 0; i < 10; i++){
            cin >> temp;
            int sum = 0;
           	while(temp != 0){
            	sum += temp%10;
                temp /= 10;
            }
            
            if(sum > max)
                max = sum;
            if(sum < min)
                min = sum;
        }
        cout << "#" << test_case << " " << max << " " << min << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

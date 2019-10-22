#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int N, K;
        int max = 0, temp = 0;
        cin >> N >> K;
        temp = N*K;
        cout << "#" << test_case;
       	if(N % 2 == 0){
            max = (temp*(temp+1)/2)/K;
           	for(int i = 0; i < K; i++)
                cout <<" "<< max;
        }
        else{
            if(K % 2 == 0){
                max = (temp*(temp+1)/2)/K - K/2 + 1;
            	for(int i = 0; i < K; i++)
                	cout <<" " << max++;
            }
            else{
                max = (temp*(temp+1)/2)/K - K/2;
            	for(int i = 0; i < K; i++)
                	cout <<" " << max++;
            }
            
       	}
        cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

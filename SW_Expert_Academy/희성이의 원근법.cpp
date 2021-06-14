#include<iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; ++test_case){
		int N;
        scanf("%d", &N);
        if(N < 100)
            N = 0;
       	else if(N < 1000)
           	N = 1;
      	else if(N < 10000)
          	N = 2;
      	else if(N < 100000)
          	N = 3;
      	else if(N < 1000000)
          	N = 4;
      	else
          	N = 5;
        printf("#%d %d\n", test_case, N);
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

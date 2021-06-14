#include<iostream>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; ++test_case){
        double D, A, B, F;
        scanf("%lf %lf %lf %lf", &D, &A, &B, &F);
        F = F * (D/(A+B));
        printf("#%d %lf \n",test_case, F);
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

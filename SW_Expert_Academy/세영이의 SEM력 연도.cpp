#include<iostream>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int S, E, M;
        scanf("%d %d %d", &S, &E, &M);
        int year = S;
        int flag = 0;
        while(flag != 1){
            int Month = year % 24;
            int Date = year % 29;
            if(Month == 0) Month =24;
            if(Date == 0) Date =29;
            
        	if(Month == E && Date == M)
                flag = 1;
            else
                year += 365;
        }
        printf("#%d %d\n", test_case, year);
        flag = 0;
	}
	return 0;
}

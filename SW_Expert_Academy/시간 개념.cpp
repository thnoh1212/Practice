#include<iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int n_h, n_m, n_s;
        int a_h, a_m, a_s;
        scanf("%d:%d:%d", &n_h, &n_m, &n_s);
        scanf("%d:%d:%d", &a_h, &a_m, &a_s);
        
        int check = 0;
        a_m > n_m ? check = check+2 : check = check - 2;
       	a_s >= n_s ? check =check +1 : check =check-1;
        if(a_h > n_h || (a_h == n_h && check >= 0)){
            a_s = a_s >= n_s ? (a_s - n_s) : (60- n_s + a_s +a_m - a_m--);
            a_m = a_m >= n_m ? (a_m - n_m) : (60- n_m + a_m + a_h - a_h--);
            a_h -= n_h;
        }
        else{
            a_s = a_s + 60 - n_s >= 60 ? (a_s - n_s + a_m - a_m++) : (a_s + 60 - n_s);
            a_m = a_m + 59 - n_m >= 60 ? (a_m - n_m + a_h -1 - a_h++) : (a_m + 59 - n_m);
            a_h += 23 - n_h;
        }
        printf("#%d ", test_case);
        a_h >= 10 ? printf("%d:", a_h) : printf("0%d:", a_h);
        a_m >= 10 ? printf("%d:", a_m) : printf("0%d:", a_m);
		a_s >= 10 ? printf("%d", a_s) : printf("0%d", a_s);
		printf("\n");
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
} 

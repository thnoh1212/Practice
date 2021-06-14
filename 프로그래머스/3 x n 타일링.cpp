#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    long long answer[5000] = {0};
    if(n % 2 == 1)
        return 0;
    else{
        answer[0] = 1;
	    answer[2] = 3;
        for(int i = 4; i <= n; i += 2){
		    answer[i] = answer[i - 2] * 3;
		    answer[i] %= 1000000007;    
               for(int j = i - 4; j >= 0; j -= 2){
			        answer[i] += answer[j] * 2;
                    answer[i] %= 1000000007;
		    }
	    }
    }
    return int(answer[n]);
}

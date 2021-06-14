#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer = 0; // int 허용범위를 초과할 수 있으므로 double, long long 등의 자료형 사용
    int *check = new int[n+1];
    
    for(int i = 0; i <= n; i++)
        check[i] = i;
    
    for(int i = 2; i <= n; i++){
        if(!check[i]) continue; 
        else answer += check[i];
        
        for(int j = i + i; j <= n; j += i){
            check[j] = 0;
        }
    }
    
   
    return answer;
}

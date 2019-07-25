#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> check;
    check.assign(n+1, 0);
    
    for(int i = 2; i <= n; i++)
        check[i] = i;
    
    for(int i = 2; i <= n; i++){
        if(check[i] == 0) continue;
        //제거된 수 무시
        
        for(int j = i + i; j <= n; j += i){
            check[j] = 0;
        }//체크한 수의 배수들 전부 탐색에서 제거
    }
    
    for(int i = 0; i <= n; i++)
        if(check[i] != 0)
            answer++;
    
    return answer;
}
//에라토스테네스의 체(Sieve of Eratosthenes) 적용완료

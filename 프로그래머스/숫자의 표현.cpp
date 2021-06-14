#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    
    for(int i = 1; i <= n/2; i++){
        sum = i;
        for(int j = i+1; j <= n/2 + 1 && sum <= n; j++){
            sum += j;
            if(sum == n){
                answer += 1;
                break;
            }
        }
    }
    answer += 1;
    return answer;
}

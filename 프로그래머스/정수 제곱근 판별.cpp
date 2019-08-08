#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long n_integer = sqrt(n);
    
    if(powl(n_integer, 2) == n){
        n_integer++;
        answer = n_integer * n_integer;
    }
    else
        answer = -1;

    return answer;
}

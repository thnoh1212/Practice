#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(b > a)
        for(int i = a; i <= b; i++)
            answer += i;
    else
        for(int i = b; i <= a; i++)
            answer += i;
    
    return answer;
}

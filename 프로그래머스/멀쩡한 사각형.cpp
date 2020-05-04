#include <iostream>

using namespace std;

long long solution(int w,int h)
{
	long long answer = 1;
    long long w_ = w;
    long long h_ = h;
    int a = max(w, h), b = min(w, h);
    int mod = a % b;
    while(mod > 0)
    {
        a = b;
        b = mod;
        mod = a % b;
    }
    answer = w_ * h_ - (w + h - b);
	return answer;
}

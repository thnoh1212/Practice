#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int mod = 0;
    int temp_1 = 0, temp_2 = 0;
    if(n >= m){
        mod = n % m;
        temp_1 = n;
        temp_2 = m;
    }
    else{
        mod = m % n;
        temp_1 = m;
        temp_2 = n;
    }
    while(mod > 0){
        temp_1 = temp_2;
        temp_2 = mod;
        mod = temp_1 % temp_2;
    }
    answer.push_back(temp_2);
    temp_1 = n * m / temp_2;
    answer.push_back(temp_1);
    return answer;
}

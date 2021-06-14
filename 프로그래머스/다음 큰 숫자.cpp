#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int count = 0, count_2 = 0;
    int temp = n;
    vector<int> check;
    while(temp != 0){
        if(temp%2 == 1)
            count += 1;
        temp /= 2;
    }
    
    while(1){
        count_2 = 0;
        temp = ++n;
        while(temp != 0){
            if(temp%2 == 1)
                count_2 += 1;
            temp /= 2;
        }
        if(count == count_2)
            break;
    }
    answer = n;
    
    return answer;
}

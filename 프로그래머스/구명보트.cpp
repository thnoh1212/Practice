#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sum = 0, count = 0;
    int i = 0, j = people.size()-1;
    sort(people.begin(), people.end());
    while(i != j){
        if(i >= j)
            break;
        if(people[i] + people[j] > limit){
            answer += 1;
            j--;
        }
        else{
            i++;
            j--;
            answer += 1;
        }
    }
    if (i == 0)
        answer += 1;
    else if(i == j)
        answer += 1;
    
    return answer;
}

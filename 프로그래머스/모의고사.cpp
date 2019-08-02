#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int person_1[] = {1,2,3,4,5};
    int person_2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int person_3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int i = 0, j = 0, k = 0, test = 0, max_a = 0;
    int count[] = {0, 0, 0};
    
    while(test != answers.size()){
        i %= 5;
        j %= 8;
        k %= 10;
        
        if(person_1[i++] == answers[test])
            count[0]++;
        if(person_2[j++] == answers[test])
            count[1]++;
        if(person_3[k++] == answers[test++])
            count[2]++;
        }
    
    max_a = max(count[0], max(count[1], count[2]));
    
    if(count[0] == max_a) answer.push_back(1);
    if(count[1] == max_a) answer.push_back(2);
    if(count[2] == max_a) answer.push_back(3);

    return answer;
    
}

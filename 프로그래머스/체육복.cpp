#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int *students = new int[n+2];
    fill_n(students, n+1, 1);
    students[0] = -1;
    students[n+1] = -1;
    for(int i = 0; i < lost.size(); i++){
        students[lost[i]] -= 1;
    }
    
    for(int i = 0; i < reserve.size(); i++){
        students[reserve[i]] += 1;
    }
    
    for(int i = 1; i <= n; i++){
        if(students[i] == 2){
            if(students[i-1] == 0){
                students[i] -= 1;
                students[i-1] += 1;
            }
            else if(students[i+1] == 0){
                students[i] -= 1;
                students[i+1] += 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(students[i] >= 1)
            answer++;
    }
    return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    int num = strings.size();
    string temp;
    for(int i = 0; i < num; i++){
        for(int j = i; j < num; j++){
            if(strings[i][n] > strings[j][n]){
                temp = strings[i] ;
                strings[i] = strings[j];
                strings[j] = temp; 
            }
            if(strings[i][n] == strings[j][n]){
                if(strings[i] > strings[j]){
                    temp = strings[i] ;
                    strings[i] = strings[j];
                    strings[j] = temp; 
                }
            }
        }
    }
    answer.swap(strings);
    return answer;
}

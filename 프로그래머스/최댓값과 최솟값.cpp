#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

string solution(string s) {
    string answer = "";
    char* temp = new char[s.size()];
    vector<int> test;
    int count = -1;
    strcpy(temp, s.c_str());
    temp = strtok(temp, " ");
    while(temp != NULL){
        test.push_back(atoi(temp));
        temp = strtok(NULL," ");
        count += 1;
    }
    sort(test.begin(), test.end());
    
    answer += to_string(test[0]);
    answer += " ";
    answer += to_string(test[count]);
    return answer;
}

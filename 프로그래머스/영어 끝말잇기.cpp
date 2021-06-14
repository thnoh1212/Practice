#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> temp;
    int flag = 0;
    int count = 1;
    temp.push_back(words[0]);
    for(int i = 0; i < words.size()-1; i++){ 
        count++;
        if(words[i][words[i].size()-1] != words[i+1][0]){
            flag = 1;
            break;
        }
        for(int j = 0; j < temp.size(); j++){
            if(temp[j] == words[i+1]){
                flag = 2;
                break;
            }
        }
        if(flag != 0)
            break;
        temp.push_back(words[i+1]);
    }
    
    if(flag == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        if(count % n == 0)
            answer.push_back(n);
        else
            answer.push_back(count%n);
        answer.push_back((count-1)/n + 1);
    }
    return answer;
}

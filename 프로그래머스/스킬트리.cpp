#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int flag = 0;
    stack<char> temp;
    
    for(int i = 0; i < skill_trees.size(); i++){
        flag = 0;
        for(int j = 0; j < skill_trees[i].size(); j++){
            if(skill.find(skill_trees[i][j]) != string::npos){
                if(skill_trees[i][j] != skill[flag]){
                    flag = -1;
                    break;  
                }
                else
                    flag++;
            }
        }
        if(flag != -1)
            answer++;
    }
    return answer;
}

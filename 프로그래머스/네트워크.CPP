#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> network;
bool chk[200] = {false};

void dfs(int i){
    chk[i] = true;
    
    for(int j = 0; j < network[i].size(); j++){
        if(!chk[network[i][j]]){
            chk[network[i][j]] = true;
            dfs(network[i][j]);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    network = computers;
    for(int i = 0; i < n; i++){
        network[i].clear();
        for(int j = 0; j < n; j++){
            if(i != j){
                if(computers[i][j] == 1)
                    network[i].push_back(j);
            }
        }
        
    }
    for(int i = 0; i < network.size(); i++){
        if(!chk[i]){
            dfs(i);
            answer++;
        }
    }
    return answer;
}

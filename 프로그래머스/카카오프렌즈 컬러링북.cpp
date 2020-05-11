#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool chk[100][100];
int moves[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int Max = 0;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}


void dfs(int i, int j, int m, int n, vector<vector<int> > &picture){
    
    chk[i][j] = true;
    
    int cur_i = i;
    int cur_j = j;
    Max += 1;
    
    for(int k = 0; k < 4; k++){
        int next_i = cur_i + moves[k][0];
        int next_j = cur_j + moves[k][1];
        if(next_i >= 0 && next_i < m  && next_j >= 0 && next_j < n){
            if(picture[next_i][next_j] == picture[cur_i][cur_j] && !chk[next_i][next_j]){
                dfs(next_i, next_j, m,  n, picture);
            }
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    vector<pair<int, int> > temp;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            chk[i][j] = false;
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!chk[i][j] && picture[i][j]){
                Max = 0;
                cnt++;
                dfs(i, j, m,  n, picture);
                int flag = -1;
                for(int k = 0; k < temp.size(); k++){
                    if(temp[k].first == picture[i][j]){
                        flag = k;
                        break;
                    }
                }
                if(flag == -1)
                    temp.push_back(make_pair(picture[i][j], Max));
                else{
                    if(Max > temp[flag].second)
                        temp[flag].second = Max;
                }
            }
        }
    }
    sort(temp.begin(), temp.end(), cmp);
    answer[0] = cnt;
    answer[1] = temp[0].second;
    
    return answer;
}

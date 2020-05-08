#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct GRAPH {
    int from;
    int to;
    int val;
}graph;

bool chk;
int group[301][301];
int moves[4][2] ={{1,0},{0,1},{-1,0},{0,-1}};
int parent[90000];
vector<graph> edge;

bool comp(graph d1, graph d2)
{
    return d1.val < d2.val;
}

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    chk = false;
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    parent[u] = v;
    chk = true;
}

void dfs(int i, int j, vector<vector<int> > &land, int height, int temp){
    if(group[i][j]) return;
    group[i][j] = temp;
    
    int cur_i = i, cur_j = j; 
    for(int k = 0; k < 4; k++){
        int next_i = cur_i + moves[k][0];
        int next_j = cur_j + moves[k][1];
        if(next_i >= 0 && next_i < land.size() && next_j >= 0 && next_j < land.size()){
            int ladder = abs(land[next_i][next_j] - land[cur_i][cur_j]);
            if(!group[next_i][next_j] && ladder <= height)
                dfs(next_i, next_j, land, height, temp);
            
            if(ladder > height && group[next_i][next_j]){
                graph route;
                route.from = temp, route.to = group[next_i][next_j], route.val = ladder;
                edge.push_back(route);
                route.from = group[next_i][next_j], route.to = temp, route.val = ladder;
                edge.push_back(route);
            }
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int temp = 1;
    for(int i = 0; i < land.size(); i++){
        for(int j = 0; j < land.size(); j++){
            if(!group[i][j])
                dfs(i, j, land, height, temp++);
        }
    }
    for(int i = 0; i < temp; i++)
        parent[i] = i;

    
    sort(edge.begin(), edge.end(), comp);

    for (int i = 0; i < edge.size(); i++){
        merge(edge[i].from, edge[i].to);
        if(chk)
            answer += edge[i].val;
    }
    return answer;
}

#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 1;
    vector<pair<int, int>> map[n+1];
    priority_queue<pair<int, int> ,vector<pair<int, int> >,greater<pair<int, int> > > check;
    
    int dist[n+1];
    fill(dist, dist+n+1, 20000); 

    for(int i = 0; i < edge.size(); i++){
        map[edge[i][0]].push_back({edge[i][1],1});
        map[edge[i][1]].push_back({edge[i][0],1});
    }
    
    
       
    check.push({0, 1});
    dist[1] = 0;
    
    while(!check.empty()){
        int cost = check.top().first;  
        int loc = check.top().second;       
        check.pop();    
        for(int i=0; i < map[loc].size(); i++){
            int dest = map[loc][i].first;
            int nextcost = map[loc][i].second;
            
            if(dist[dest] > dist[loc] + nextcost){
                dist[dest] = dist[loc]+ nextcost;
                if(max < dist[dest])
                    max = dist[dest];
                check.push({dist[dest], dest});
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(dist[i] == max)
            answer++;
    }
    
    return answer;
}

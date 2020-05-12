#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    for(int i = 0; i < land.size()-1; i++){
        vector<int> floor = land[i];
        sort(floor.rbegin(), floor.rend());
        for(int j = 0; j < land[i].size(); j++){
            if(floor[0] == land[i][j])
                land[i+1][j] += floor[1];
            else
                land[i+1][j] += floor[0];
        }
    }
    
    sort(land[land.size()-1].rbegin(), land[land.size()-1].rend());
    return land[land.size()-1][0];
}

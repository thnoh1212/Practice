#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {

    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            if(j == 0)
                triangle[i][0] = triangle[i][0] + triangle[i-1][0];
            else if(j == triangle[i].size()-1)
                triangle[i][j] = triangle[i][j] + triangle[i-1][j];
            else
                triangle[i][j] = std::max(triangle[i][j] + triangle[i-1][j-1],
                                        triangle[i][j] + triangle[i-1][j]);
        }
    }
    sort(triangle[triangle.size()-1].rbegin(), triangle[triangle.size()-1].rend());
    int answer = triangle[triangle.size()-1][0];
    return answer;
}

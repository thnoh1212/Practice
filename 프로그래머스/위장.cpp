#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int flag = -1, temp = 0;
    vector<pair<string, int>> count;
    for(int i = 0; i < clothes.size(); i++){
        flag = -1;
        for(int j = 0; j < count.size(); j++){
            if(clothes[i][1] == count[j].first)
                flag = j;
        }
        if(flag == -1)
             count.push_back(make_pair(clothes[i][1], 1));
        else
            count[flag].second += 1;                
    }
    
    for(int i = 0; i < count.size(); i++)
        answer *= (count[i].second + 1);

    answer -= 1;
    return answer;
}

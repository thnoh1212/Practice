#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair <string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int> > temp;
    int flag = 0, index = 0, max = 0, count = 0;
    temp.push_back(make_pair(genres[0], plays[0]));
    for(int i = 1; i < genres.size(); i++){
        for(int j = 0; j < temp.size(); j++){
            if(genres[i] == temp[j].first){
                flag = 1;
                index = j;
                break;
            }
        }
        if(flag == 1)
            temp[index].second += plays[i];
        else
            temp.push_back(make_pair(genres[i], plays[i]));
        flag = 0;
    }
    sort(temp.begin(), temp.end(), comp);
    for(int i = 0; i < temp.size(); i++){
        while(count != 2){
            for(int j = 0; j < genres.size(); j++){
                if(genres[j] != temp[i].first) continue;
            
                if(plays[j] > max){
                    max = plays[j];
                    index = j;
                    flag = 1;
                }
            }
            if(flag != 1){
                flag = 0;
                break;
            }
            answer.push_back(index);
            plays[index] = 0;
            genres[index] = " ";
            count++;
            max = 0;
            flag = 0;
        }
        count = 0;
            
    }
    
    return answer;
}

//map 사용. 일렬 방식으로 저장되어있는 벡터나 리스트보다 탐색이 빠름

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> info;
    
    for(int i = 0; i < record.size(); i++){
        if(record[i][0] == 'L') continue;
        string u_id = "";
        string name = "";
        int j = 0;
        if(record[i][0] == 'E'){
            for(j = 6; record[i][j] != ' '; j++) continue;
            u_id = record[i].substr(6, j - 6);
            j++;
            name = record[i].substr(j, record[i].size()-j);
        }
        else{
            for(j = 7; record[i][j] != ' '; j++) continue;
            u_id = record[i].substr(7, j - 7);
            j++;
            name = record[i].substr(j, record[i].size()-j);
        }
        auto a = info.find(u_id);
        
        if(a == info.end())
            info.insert(make_pair(u_id, name));
        else
            a->second = name;
    }
    for(auto a : record){
        if(a[0] == 'C') continue;
        string u_id = "";
        string name = "";
        int j = 0;
        for(j = 6; a[j] != ' '; j++) continue;
        u_id = a.substr(6, j - 6);
        
        auto b = info.find(u_id);  
        if(a[0] == 'E'){
            string t_answer = b->second + "님이 들어왔습니다.";
            answer.push_back(t_answer);
        }
        else{
            string t_answer = b->second + "님이 나갔습니다.";
            answer.push_back(t_answer);
        }

    }
        
    return answer;
}

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    
    for(int i = 0; i < 26;  i++){
        string temp = "A";
        temp[0] = temp[0] + i;
        dict.insert(make_pair(temp,i + 1));
    }
    for(int i = 0; i < msg.size(); i++){
        string temp = "";
        temp += msg[i];
        int index = i + 1;
        while(dict.find(temp) != dict.end() && index < msg.size()){
            temp += msg[index++];
        }
        if(dict.find(temp) == dict.end()){
            dict.insert(make_pair(temp,dict.size() + 1));
            cout << temp << endl;
            temp = temp.substr(0, temp.size() - 1);
        }
        answer.push_back(dict.find(temp)->second);
        i = i + temp.size() - 1;
    }
    return answer;
}#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    
    for(int i = 0; i < 26;  i++){
        string temp = "A";
        temp[0] = temp[0] + i;
        dict.insert(make_pair(temp,i + 1));
    }
    for(int i = 0; i < msg.size(); i++){
        string temp = "";
        temp += msg[i];
        int index = i + 1;
        while(dict.find(temp) != dict.end() && index < msg.size()){
            temp += msg[index++];
        }
        if(dict.find(temp) == dict.end()){
            dict.insert(make_pair(temp,dict.size() + 1));
            cout << temp << endl;
            temp = temp.substr(0, temp.size() - 1);
        }
        answer.push_back(dict.find(temp)->second);
        i = i + temp.size() - 1;
    }
    return answer;
}

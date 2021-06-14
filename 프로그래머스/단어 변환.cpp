#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int> > temp;
    int count = 0;
    string now;
    temp.push(make_pair(begin, answer));
    while(!temp.empty()){
        now = temp.front().first;
        answer = temp.front().second;
        temp.pop();
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                if(now[j] != words[i][j])
                    count++;
                if(count >= 2){
                    count = 0;
                    break;
                }
            }
            if(count == 1){
                if(words[i] == target){
                    return answer+1;
                }
                else{
                    temp.push(make_pair(words[i], answer +1));
                    words[i] = " ";
                }
                count = 0;
            }
        }
    }
    answer = 0;
    return answer;
}

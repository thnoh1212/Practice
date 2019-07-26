#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    int n = 1;
    int j = 0;
    int count = 0;
    int temp = 0;
    for(int i = 0; i  < progresses.size();){
        count++;
        progresses[i] = progresses[i] + speeds[i];
        if(progresses[i] >= 100){
            day.push_back(count);
            cout << count << endl;
            count = 0;
            i++;
        }
    }
    temp = day[0];
    for(int i = 0; i < progresses.size(); i++){
        if(temp >= day[i] || i == 0)
            count++;
        else{
            answer.push_back(count);
            count = 1;
            temp = day[i];
        }
    }
    answer.push_back(count);
    
    return answer;
}

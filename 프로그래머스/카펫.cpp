#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    vector<int> horizontal;
    vector<int> Vertical;
    int total = red + brown;
    for(int i = 1; i * i <= total; i++){
        if(total % i == 0){
            horizontal.push_back(i);
            Vertical.push_back(total/i);    
        }
    }
    for(int i = 0; i < horizontal.size(); i++){
        if(((horizontal[i] * 2) + (Vertical[i] *2) - 4 ) == brown){
            answer.push_back(Vertical[i]);
            answer.push_back(horizontal[i]);
        }
    }
    return answer;
}

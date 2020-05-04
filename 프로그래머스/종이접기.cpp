#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    for(int i = 1; i < n; i++){
        vector<int> temp = answer;
        temp.push_back(0);
        for(auto a = answer.rbegin(); a != answer.rend(); a++)
            temp.push_back(1 - *a);
        
        answer = temp;
    }
    return answer;
}

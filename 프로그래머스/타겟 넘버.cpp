#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int now = 0, count = 0;
    queue<pair<int, int> > temp;
    temp.push(make_pair(numbers[0], 0));
    temp.push(make_pair(-1 * numbers[0], 0));
    
    while(!temp.empty()){
        now = temp.front().first;
        count = temp.front().second;
        temp.pop();
        if(count == numbers.size() - 1){
            if(now == target)
                answer++;
            continue;
        }
        
        else if(++count < numbers.size()){
            temp.push(make_pair(now + numbers[count], count));
            temp.push(make_pair(now - numbers[count], count));
        }
    }
    return answer;
}

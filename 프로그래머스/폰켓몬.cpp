#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<int> nums)
{
    stack<int> temp;
	int answer = 0;
    int max = nums.size()/2;
    int count = 1;
    sort(nums.begin(), nums.end());
    temp.push(nums[0]);
    for(int i = 1; i < nums.size(); i++){
       if(max == count)
            break;
        if(temp.top() == nums[i])
            continue;
        else{
            temp.push(nums[i]);
            count++;
            cout << nums[i] << endl;
        }
        
    }
    answer = count;
	return answer;
}

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0, index = nums.size()-1;
    int flag = 0, min = 0;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2; i++){
        for(int j = i+1; j < nums.size()-1; j++){
            for(int k = j+1; k < nums.size(); k++)
                temp.push_back(nums[i]+nums[j]+nums[k]);
        }
    }
    for(int i = 0; i < temp.size(); i++){
        flag = 0;
        for(int j = 2; j < temp[i]/2; j++){
            if(temp[i] % j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            answer++;
    }
    return answer;
}

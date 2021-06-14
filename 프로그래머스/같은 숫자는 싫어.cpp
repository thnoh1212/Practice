#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int num = arr.size();
    vector<int> temp;
    int temp_2 = arr[0];
    temp.push_back(arr[0]);
    for(int i = 1; i < num; i++){
       if(temp_2 != arr[i]){
           temp_2 = arr[i];
           temp.push_back(temp_2);
       }
    }
    answer.swap(temp);
    return answer;
}

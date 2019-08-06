#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    vector<int> temp;
    cout << temp.size() << endl;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % divisor == 0)
            temp.push_back(arr[i]);
    }
    if(temp.size() != 0){
        sort(temp.begin(), temp.end());
        answer.swap(temp);
    }
    else
        answer.push_back(-1);
    
    return answer;
}

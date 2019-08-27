#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool standard(string a, string b){
    if (b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(int i = 0; i < numbers.size(); i++)
        temp.push_back(to_string(numbers[i]));

    sort(temp.begin(), temp.end(), standard);
    for(int i = 0; i < numbers.size(); i++)
      answer += temp[i];
    
    if(answer[0] == '0')
        answer = "0";
    return answer;
}

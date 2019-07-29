#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    string temp = "";
    string check = "";
    string max = "";
    while(k != 0){
        temp = number;
        max = temp.erase(0, 1);
        for(int i = 1; i < number.size(); i++){
            temp = number;
            check = temp.erase(i, 1);
            
            if(max < check)
                max = check;
        }
        number = max;
        k--;
    }
    answer = number;
    return answer;
}

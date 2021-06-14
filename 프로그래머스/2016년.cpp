#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}; 
    int dates = 0;
    int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    for(int i = 0; i < a - 1; i++){
        dates += month[i];
    }
    dates += b - 1;
    cout << dates << endl;
    answer = day[(5 + dates) % 7];
    return answer;
}

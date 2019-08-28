#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(char a, char b){
    return a>b;
}

vector<int> decimal(const int max){
    vector<int> check;
    vector<int> temp;
    check.assign(max+1, 0);
    for(int i = 2; i <= max; i++)
        check[i] = i;
    
    for(int i = 2; i <= max; i++){
        if(check[i] == 0) continue;
        
        for(int j = i + i; j <= max; j += i){
            check[j] = 0;
        }
    }
    
    for(int i = 0; i <= max; i++)
        if(check[i] != 0)
            temp.push_back(check[i]);
    return temp;
    
}
int solution(string numbers) {
    int answer = 0, count = 0, flag = -1;
    sort(numbers.begin(), numbers.end(),comp);
    int temp = stoi(numbers);
    string t_numbers;
    vector<int> deci;
    deci = decimal(temp);
    for(int i = 0; i < deci.size(); i++){
        string check = to_string(deci[i]);
        t_numbers = numbers;
        flag = -1;
        for(int j = 0; j < check.size(); j++){
            if((flag = t_numbers.find(check[j])) != string::npos)
                t_numbers[flag] = ' ';  
            else{
                flag = -1;
                break;    
            }
        }
        if(flag != -1)
            count++;
    }
    answer = count;
    return answer;
}

/* comp = 내림차순으로 문자열 정렬 */
/* decimal = 소수 탐색 */
/* main에서 문자열에 포함된 수인지 탐색 */

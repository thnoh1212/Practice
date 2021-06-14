#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct NAME{
    string head;
    int number;
    int index;
    string f_name;
}name;

int chk_alpha(string a){
   int index = 0;
    for(; a[index] < '0' || a[index] > '9'; index++) continue;
    return index;
}

int chk_number(string a, int index){
    for(; a[index] >= '0' && a[index] <= '9'; index++) continue;
    return index;
}

bool cmp(name A, name B){
    if(A.head != B.head)
        return A.head < B.head;
    else if(A.number != B.number)
        return A.number < B.number;
    else
        return A.index < B.index;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<name> t_answer;
    for(int i = 0; i < files.size(); i++){
        name temp;
        int index = chk_alpha(files[i]);
        int index_2 = chk_number(files[i], index);
        temp.head = files[i].substr(0, index);
        transform(temp.head.begin(), temp.head.end(), temp.head.begin(), ::tolower);
        temp.number = stoi(files[i].substr(index, index_2 - index));
        temp.f_name = files[i];
        temp.index = i;
        t_answer.push_back(temp);
    }
    sort(t_answer.begin(), t_answer.end(), cmp);
    
    for(int i = 0; i < t_answer.size(); i++)
        answer.push_back(t_answer[i].f_name);
    return answer;
}

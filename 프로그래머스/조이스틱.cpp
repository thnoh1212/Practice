#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.length();
    int cursor = 0;
    int count = 0;
    int temp = 0;
    vector<char> name_t;
    vector<int> index;
    vector<pair<int, int>> check;
    for(int i = 0; i < size; i++){
        name_t.push_back(name[i]);
        if(name[i] == 'A')
            check.push_back(make_pair(1, 0));
        else{
            temp = (abs(name[i] - 65) >= abs(name[i] - 91) ? abs(name[i] - 91) : abs(name[i] - 65));
            check.push_back(make_pair(0, temp));
        }
    }
    //A의 위치에 따라 커서 이동방향 선택
    while(1){
        if(count == size)
            break;
        count++;
        int min[2] = {size, 0};
        for(int i = 0; i < size; i++){
            if(check[i].first != 1){
                temp = (abs(i - cursor) > cursor + (size - i)) ? cursor + (size - i) : (abs(i - cursor));
                if(temp < min[0]){
                    min[0] = temp;
                    min[1] = i;
                }
            }
        }
        if(count != 1 && min[1] == 0)
            continue;
        index.push_back(min[1]);
        check[min[1]].first = 1;
        cursor = min[1];
    }
        
    for(int i = 0; i < size; i++){
        answer += check[i].second;
    }
    cursor = index[0];
    answer += index[0];
    for(int i = 0; i < index.size(); i++)
        printf("%d", index[i]);
    for(int i = 1; i < index.size(); i++){
        
        temp = (abs(index[i] - cursor) > abs(cursor + (size - index[i])) ) ? abs(cursor + (size - index[i])) : abs(index[i] - cursor);
        
        answer += temp;
        cursor = index[i];
    }
    //A = 65;
    //Z = 90
    return answer;
}

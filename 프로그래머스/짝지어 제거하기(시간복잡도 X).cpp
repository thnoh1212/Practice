#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int i = 0, check = 1;
    vector<int> index;
    index.clear();
    while(check != 0){
        check = 0;
        for(int i = 0; i < s.size(); i++)
            cout << s[i];
        cout << endl;
        for(int i = 0; i < s.size()-1; i++){
            if(i+1 >= s.size())
                break;
            if(s[i] == s[i+1]){
                index.push_back(i);
                check = 1;
                i += 1;
                continue;
            }
        }
        for(int i = index.size()-1 ; i >= 0; i--){
            s.erase(index[i], 2);
        }
        index.clear();
        
    }
    if(s.size() == 0)
        answer = 1;
    else
        answer = 0;
    return answer;
}

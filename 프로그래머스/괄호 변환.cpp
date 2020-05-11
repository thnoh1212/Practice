#include <string>
#include <vector>

using namespace std;

string test(string p){
    if(p == "")
        return "";
    
    string u = "";
    string v = "";
    int flag = 1, cnt = 0;
    for(auto a : p){
        if(cnt == 0)
            flag--;
        if(flag == 0){
            if(a == '(')
                cnt++; 
            else
                cnt--;
            
            u = u + a;
        }
        else
            v = v + a;
    }
    if(u[0] == '('){
        v = test(v);
        return u + v;
    }
    else{
        string temp = "(";
        v = test(v);
        temp = temp + v + ")";
        for(int i = 1; i < u.length() - 1; i++){
            if(u[i] == '(')
                temp = temp + ')';
            else
                temp = temp + '(';    
        }
        return temp;
    }
    
}

string solution(string p) {
    string answer = "";
    
    answer = test(p);
    
    return answer;
}

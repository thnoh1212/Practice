// set_union, set_interaction 함수 처음 사용. 쓰기 전 반드시 정렬.

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> A, B;
    string temp = "";
    for(int i = 0; i < str1.length(); i++){
        if((str1[i] >= 'a' && str1[i] <= 'z' ) || (str1[i] >= 'A' && str1[i] <= 'Z'))
            temp = temp + str1[i];
        else
            temp = "";
        
        if(temp.length() == 2){
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            A.push_back(temp);
            temp = str1[i];    
        }
    }
    temp = "";
    for(int i = 0; i < str2.length(); i++){
        if((str2[i] >= 'a' && str2[i] <= 'z' ) || (str2[i] >= 'A' && str2[i] <= 'Z'))
            temp = temp + str2[i];
        else
            temp = "";
        
        if(temp.length() == 2){
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            B.push_back(temp);
            temp = str2[i];    
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
        
    vector<string> hap;
    set_union(A.begin(),A.end(),B.begin(),B.end(),back_inserter(hap));
    vector<string> cha;
    set_intersection(A.begin(),A.end(),B.begin(),B.end(),back_inserter(cha));
    int a = hap.size() , b = cha.size() * 65536;
    
    if(a != 0 && b != 0)
        answer =  b / a ;
    else if(a == 0)
        return 65536;
    else
        return 0;
    return answer;
}

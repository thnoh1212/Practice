#include <string>
#include <vector>
#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        int i=0;
        int cnt=0;
        cout<<"#"<<test_case;
        while(i!=N){
            int check = 1;
            string str;
            cin >> str;
            if(isupper(str[0])){
                for(int j=1;j<str.size();j++){
                    if(islower(str[j]))
                        continue;
                    if(j == str.size()-1 && (str[j]=='.' || str[j]=='!' || str[j]=='?'))
                        continue;
                    check = 0;
                    break;
                }
                if(check == 1) cnt++;
            }
            if(str[str.size()-1]=='.' || str[str.size()-1]=='!' || str[str.size()-1]=='?'){
                cout<<" "<<cnt;
                cnt = 0;
                i++;
            }
             
        }
        cout<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

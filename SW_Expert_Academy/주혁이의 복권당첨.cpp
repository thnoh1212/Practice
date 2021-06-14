#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
bool compare(const pair<string, int>& a, const pair<string, int>& b){
    return a.second > b.second;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int N, M;
        cin >> N >> M;
        vector<pair<string, int> > temp;
        int prize;
        string num_loto;
        vector<string> my_num;
        for(int i = 0; i < N; i++){
        	cin >> num_loto >> prize;
            temp.push_back(make_pair(num_loto, prize));
        }
        sort(temp.begin(), temp.end(), compare);
        for(int i = 0; i < M; i++){
        	cin >> num_loto;
            my_num.push_back(num_loto);
        }
        int flag = 0;
        int sum = 0;
        int reward = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                reward = temp[j].second; 
            	for(int k = 0; k < my_num[i].size(); k++){
                	if(temp[j].first[k] == '*') 
                        continue;
                    else if(temp[j].first[k] == my_num[i][k])
                        flag = 1;
                    else{
                        flag = 2;
                        break;
                    }
                }
                if(flag == 2) 
                    flag = 0;
                else{
                	sum += reward;
                    flag = 0;
                    break;
                }
            }
        }
        cout << "#" << test_case << " " <<  sum << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

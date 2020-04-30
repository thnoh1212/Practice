#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > temp;
    
    int time = 0, cnt = 0, flag = 0, work = 0, complete = 0;
    
    sort(jobs.begin(), jobs.end());
    
    while(complete != jobs.size()){
        // flag == 1, time == work인 경우 작업 종료
        if(flag == 1 && time == work){
            flag = 0;
            complete += 1;
            if(!temp.empty()){
                pair <int, int> a = temp.top();
                temp.pop();
                work = time + a.first;
                answer = answer + work - a.second;
                flag = 1;
            }
        }
        
        // 시간 확인해서 jobs에서 flag가 1인경우 temp, 0인경우 작업 시작
        if(cnt < jobs.size()){
            if(time >= jobs[cnt][0]){ // 같은 시간에 작업이 한개만 요청된다는 제한이 없음
                if(flag == 1)
                    temp.push(make_pair(jobs[cnt][1], jobs[cnt][0]));
                else{
                    work = time + jobs[cnt][1];
                    flag = 1;
                    if(time == jobs[cnt][0])
                        answer = answer + jobs[cnt][1];
                    else
                        answer = answer + work - jobs[cnt][0];
                }
                cnt++;
            }
        }
        time++;
    }
    answer /= complete;
    return answer;
}

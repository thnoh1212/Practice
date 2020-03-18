/*
메모리 오류 방지를 위해 두 변수를 전역변수로 선언
전체적인 코드 가독성을 높이고 문제와 맞추기 위해 배열의 [0] 공간을 사용하지 않고 [1] 부터 사용
차량이 들어오는 경우 공간이 있는 경우와 없는 경우 구분
차량이 나가는 경우 대기차량이 있는 경우와 없는 경우 구분

처음 실수 : 음수 - 양수를 구분하여 실행하기 위해 string으로 받음
           단순히 int형으로 음수를 받아 구분해도 당연히 실행 가능


*/

#include<iostream>
#include<queue>
#include <string>

using namespace std;

int rate[101];
int weight[2001];

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m, answer = 0;
        priority_queue<int, vector<int>, greater<int> > space;
        queue<int> wait;
        cin >> n >> m;
        
        int *parking_lot = new int[n+1];
        for(int i = 1; i <= n; i++)
            cin >> rate[i];
        for(int i = 1; i <= m; i++)
            cin >> weight[i];
        
        for(int i = 1; i <=n; i++)
            space.push(i);
        
        for(int i = 1; i <= 2*m; i++){
            int temp;
            cin >> temp;
            
            if(temp < 0)
            {// 차량이 나가는 경우
                temp *= -1;
                if(wait.empty())
                {// 대기하는 차량이 없는경우
                    int park_num = 0;
                    for(int j = 1; j <= n; j++)
                    {   
                    	if(parking_lot[j] == temp){
                        	park_num = j;
                            break;
                        }                    }
                    space.push(park_num);
                }
                else
                {// 대기 차량이 있는경우
                    int car_num = wait.front();
                    wait.pop();
                    int park_num = 0;
                    for(int j = 1; j <= n; j++)
                    {   
                    	if(parking_lot[j] == temp){
                        	park_num = j;
                            break;
                        }
                    }
                    if(space.empty())
                    { // 여유공간이 없는 경우 나온 차량의 자리에 대기중인 차량 주차
                    	parking_lot[park_num] = car_num;
                    	answer += rate[park_num] * weight[car_num];
                    }
                    else
                    { // 여유공간이 있는 경우 두 자리의 번호를 비교하여 더 작은 자리에 차량 주차
                        if(space.top() > park_num)
                        {
                            parking_lot[park_num] = car_num;
                    		answer += rate[park_num] * weight[car_num];
                        }
                        else
                        {
                            space.push(park_num);
                            park_num = space.top();
                            space.pop();
                            parking_lot[park_num] = car_num;
                    		answer += rate[park_num] * weight[car_num];
                        }
                    }
                }
            }
            else
            {// 차가 들어오는 경우
                if(space.empty())
                {//공간이 없는 경우. 즉 대기열이 꽉 찬 경우
                    wait.push(temp);
                    continue;
                }
                else
                {// 자리가 남아있는 경우
                    int park_num = space.top();
                    int car_num = temp;
                    space.pop();
                    parking_lot[park_num] = car_num;
                    answer += rate[park_num] * weight[car_num];
                }
            }
        }
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}

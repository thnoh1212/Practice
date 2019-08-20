#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int count = 0, time = 0, sum = 0;
    queue<int> truck;
    for(int i = 0; i < bridge_length; i++)
        truck.push(0);
    
    while(count != truck_weights.size()){
        time += 1;
        if(truck.front() != 0){
            sum -= truck.front();
            truck.pop();
        }
        else
            truck.pop();
            
        if(sum + truck_weights[count] <= weight){
            sum += truck_weights[count];
            truck.push(truck_weights[count++]);
        }
        else
            truck.push(0);
    }

    answer += time + bridge_length;
    return answer;
}

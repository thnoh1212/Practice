#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int j = 0;
    int max = 0;
    vector<int> check;
    int index = 0;
    for(int i = 0; i < k; i++){
        if(i == dates[j]){
            check.push_back(supplies[j++]);
        }
        if(stock == 0){
            for(int a = 0; a < check.size(); a++){
                if(max < check[a]){
                    index = a;
                    max = check[a];   
                }
            }
            stock = max + stock;
            check[index] = 0; // erase 사용해보기
            index = 0;
            max = 0;
            answer++;
        }
        stock--;

    }
    return answer;
}

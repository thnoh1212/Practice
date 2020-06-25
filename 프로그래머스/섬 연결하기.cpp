#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getParent(int arr[], int a){
    if(arr[a] == a) return a;
    return arr[a] = getParent(arr, arr[a]);
}

void unionParent(int arr[], int a, int b){
    a = getParent(arr, a);
    b = getParent(arr, b);
    
    if(a > b) arr[a] = b;
    else arr[b] = a;
}

bool find(int arr[], int a, int b){
    a = getParent(arr, a);
    b = getParent(arr, b);
    if(a == b) return true;
    return false;
}

struct graph{
    int start;
    int target;
    int cost;
    void operator()(int a, int b, int c){
        start = a;
        target = b;
        cost = c;
    }
};

bool cmp(graph a, graph b){
    return a.cost < b.cost;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<graph> bridge;
    int *chk = new int[n];
    for(int i = 0; i < n; i++)
        chk[i] = i;
    
    for(int i = 0; i < costs.size(); i++){
        graph temp;
        temp(costs[i][0], costs[i][1], costs[i][2]);
        bridge.push_back(temp);
    }
    sort(bridge.begin(), bridge.end(), cmp);

    for(int i = 0; i < bridge.size(); i++){
        if(!find(chk, bridge[i].start, bridge[i].target)){
            answer += bridge[i].cost;
            unionParent(chk, bridge[i].start, bridge[i].target);
        }
    }
    
    delete[] chk;
    return answer;
}

// "동빈 나"님의 안경잡이 개발자 블로그 참조.

/*
너비 우선 탐색(Breath First Search, BFS)는 탐색을 할 때 너비를 우선으로 하여
탐색을 수행하는 탐색 알고리즘. 특히 '맹목적인 탐색'을 하고자 할 때 사용할 수 있
는 탐색 기법. 최단 경로를 보장해준다는 점에서 최단길이 탐색에 자주 사용.
큐(queue)를 사용하여 구현 
작동방식
 1. 큐에서 하나의 노드를 꺼냄
 2. 해당 노드에 연결된 노드 중 방문하지 않은 노드를 방문하고 차례대로 큐에 삽입
 3. 위의 과정 반복 
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int number = 7;
int check[7];
vector<int> a[8];

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(int i = 0; i < a[x].size(); i++){
			int y = a[x][i];
			if(!check[y]){
				q.push(y);
				check[y] = true;
			}
		}
	}
}

int main()
{
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	
	return 0;
	
	
} 

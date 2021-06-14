/*
  접근할 수 있는 정점이 여러개인 경우 작은 정점부터 탐색.
  이를 위해 sort함수 사용
  dfs와 bfs를 둘다 사용하기 위해 check함수에 true값이 아닌
  1과 2값 사용
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
int check[1001];

void dfs(int start){
	if(check[start] == 1) return;
	check[start] = 1;
	
	cout << start << ' ';
	for(int i = 0; i < graph[start].size(); i++)
		dfs(graph[start][i]);
	
}

void bfs(int start){
	queue<int> temp;
	temp.push(start);
	
	while(!temp.empty()){
		int point = temp.front();
		temp.pop();
		if(check[point] != 2)
		{
			cout << point << ' ';
			check[point] = 2;
		}
		for(int i = 0; i < graph[point].size(); i++)
		{
			if(check[graph[point][i]] != 2)
				temp.push(graph[point][i]);
		}
	}	
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	
	for(int i = 1; i <= M; i++){
		int temp1, temp2;
		cin >> temp1 >> temp2;
		
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
	for(int i = 1; i <= N; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	cout << endl;
	bfs(V);
}

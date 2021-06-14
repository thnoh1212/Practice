/*
합집합 찾기(Union-Find)
대표적인 그래프 알고리즘. 서로소 집합(Disjoint-Set)이라고도 부름
여러 개의 노드가 존재할 때 두 개의 노드를 선택해서 현재 이 두개의 노드가
서로 같은 그래프에 속하는 지 판별하는 알고리즘
부모를 합칠 때에는 일반적으로 더 작은 값을 기준으로 합침. 이것을 합침(Union)이라고 함
부모 노드만 보고는 노드가 합쳐진것인지 확인이 불가능하기 때문에 재귀함수 사용
*/

#include <iostream>

using namespace std;

// 부모 노드를 찾는 함수 
int getParent(int parent[], int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수 
int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
} 

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;
	return 0;
} 

int main()
{
	int parent[11];
	for(int i = 1; i <= 10; i++){
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	cout << "1과 5는 연결되어 있나요 ? " << findParent(parent, 1, 5);
	unionParent(parent, 4, 5);
	cout << "1과 5는 연결되어 있나요 ? " << findParent(parent, 1, 5);
	
	return 0;
}

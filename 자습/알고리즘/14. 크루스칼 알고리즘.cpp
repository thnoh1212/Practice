/*
크루스칼 알고리즘(Kruskal Algorithm)
가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘, 즉
최소 비용 신장 트리를 만들기 위한 대표적인 알고리즘 
노드 = 정점, 간선 = 거리 = 비용
모든 노드를 연결하기 위한 최소 간선의 갯수는 노드 - 1
모든간선을 거리를 기준으로 오름차순으로 정렬 후, 사이클 테이블을
발생하여 사이클이 형성되지 않는 경우에 그래프에 포함시킴
이를 통해 사이클이 없는 최소 비용 신장 트리 생성
사이클이 발생하는 여부는 Union-Find 알고리즘 사용
 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선 클래스 선언
class Edge{
	public:
		int node[2];
		int distance;
		Edge(int a, int b, int distance){
			this->node[0] = a;
			this->node[1] = b;
			this->distance = distance;
		}
		bool operator <(Edge &edge){
			return this->distance < edge.distance;
		}
}; 

int getParent(int parent[], int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
} 

int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;
	return 0;
}

int main()
{
	int n = 7;
	int m = 1;
	
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	// 간선의 비용을 기준으로 오름차순 정렬 
	sort(v.begin(), v.end());
	
	// 각 정점이 포함된 그래프가 어디인지 저장
	int parent[n];
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	
	int sum = 0;
	
	for(int i = 0; i < v.size(); i++){
		// 사이클이 발생하지 않는 경우 그래프에 포함
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)){
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		} 
	}
	cout << sum << endl;
	
}

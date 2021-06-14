/*
������ ã��(Union-Find)
��ǥ���� �׷��� �˰���. ���μ� ����(Disjoint-Set)�̶�� �θ�
���� ���� ��尡 ������ �� �� ���� ��带 �����ؼ� ���� �� �ΰ��� ��尡
���� ���� �׷����� ���ϴ� �� �Ǻ��ϴ� �˰���
�θ� ��ĥ ������ �Ϲ������� �� ���� ���� �������� ��ħ. �̰��� ��ħ(Union)�̶�� ��
�θ� ��常 ����� ��尡 ������������ Ȯ���� �Ұ����ϱ� ������ ����Լ� ���
*/

#include <iostream>

using namespace std;

// �θ� ��带 ã�� �Լ� 
int getParent(int parent[], int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ� 
int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
} 

// ���� �θ� �������� Ȯ��
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
	cout << "1�� 5�� ����Ǿ� �ֳ��� ? " << findParent(parent, 1, 5);
	unionParent(parent, 4, 5);
	cout << "1�� 5�� ����Ǿ� �ֳ��� ? " << findParent(parent, 1, 5);
	
	return 0;
}

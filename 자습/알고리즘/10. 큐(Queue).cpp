/*
Queue ���� ��ǥ���� �ڷᱸ���� �������� ���� ���� ���� ���� ������
(First in First Out, FIFO)����, ��ǥ���� ���÷� ����â���� ���ø� ��
����. �߰��� ��ġ��� �Ұ����� ���� �⺻���� ť�� ����.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();
	while(!q.empty()){
		cout << q.front() << ' ';
	}
	return 0;
} 

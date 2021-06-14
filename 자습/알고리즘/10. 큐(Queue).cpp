/*
Queue 역시 대표적인 자료구조의 일종으로 먼저 들어온 것이 먼저 나가는
(First in First Out, FIFO)구조, 대표적인 예시로 은행창구를 떠올릴 수
있음. 중간에 새치기는 불가능한 것이 기본적인 큐의 구조.
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

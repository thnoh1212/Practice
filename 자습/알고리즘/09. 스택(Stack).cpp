 /*
 Stack은 컴퓨터 공학에서 가장 기본이 되는 자료구조, 말 그대로 자료를
 표현하고 처리하는 방법에 관한 것. 이해하기 쉬운 예시를 들자면 스택은
 택배 상하차를 예로 들 수 있음. 먼저 넣은 변수일수록 깊이 있어 마지막에
 나오는 구조 (First in Last out)
 */
 
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
} 
 

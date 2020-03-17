#include <iostream>

using namespace std;

int main() 
{
	/*
	동적 할당 : 메모리 생성을 원하는 시점에 할 수 있는 기능이다.
	메모리 영역 중 힙역역에 공간이 할당된다. 힙의 특성상 메모리를 해제하기 전 까지는
	계속 남아있다.
	동적할당을 하고 메모리를 해제하지 않으면 사용하지는 않지만 공간은 계속 잡혀있게 된다.
	해당 공간은 다른곳에서 사용이 불가능하다.
	이런 현상을 메모리 릭이라고 한다.(메모리 누수)

	동적할당은 new 키워드를 이용하여 할 수 있다.
	C언어에서는 malloc() 함수를 이용해서 할 수 있다.
	
	new 할당할타입; 으로 처리한다.

	new나 malloc 둘 다 마찬가지로 힙영역에 메모리 공간을 할당하고 해당 메모리 주소를
	반환해준다.
	*/

	// 아래처럼 할당해주면 new 뒤에 들어오는 타입인 int의 크기만큼 공간을 할당한다.
	// 즉 4바이트 공간을 할당하는 것이다. 그 뒤에 할당한 공간의 메모리 주소를 pNumber에
	// 넣어주었다.


	int* pNumber = new int;
	return 0;
}
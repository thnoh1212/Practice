#include <iostream>

using namespace std;

struct _tagStudent {
	int iKor;
	int iEng;
	int iMath;
	float fAvg;
};

int main() {

	/* 
	포인터 :  가리키다. 일반 변수는 일반적인 값을 저장하게 되지만 포인터
	변수는 메모리 주소를 저장하게 된다. 모든 변수 타입은 포인터 타입을
	선언할 수 있다. int변수의 주소는 int 포인터 변수에 저장을 해야 한다.
	포인터는 메모리 주소를 담아놓는 변수이기 때문에 x86으로 개발할때는
	무조건 4byte가 나온다. x64일때는 8byte가 나온다.
	
	포인터는 자기 스스로 아무런 일도 할 수 없다. 반드시 다른 변수의 메모리
	주소를 가지고 있어야 일을 할 수 있는데 가지고 있는 그 메모리 주소에
	접근해서 값을 제어할 수 있다.

	포인터 사용 이유 : 다른 변수의 메모리 주소를 바탕으로 값을 제어하기 위해서

	형태 : 변수타입 *변수명; 의 형태로 선언한다.
	*/ 
	
	int iNumber = 100;
	// 변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.

	int* pNum = &iNumber;

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum을 이용해서 iNumber의 값을 제어해보자.
	// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
	// 역참조는 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	/*
	포인터와 배열의 관계 :  배열명은 포인터다. 배열명 자체가 해당 배열의
	메모리에서의 시작점 주소를 의미한다. 
	*/

	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray[0] << endl;

	int* pArray = iArray;
	
	cout << pArray[2] << endl;

	/*
	포인터 연산 :  +, - 연산을 제공한다. ++, -- 도 가능한데 1을 증가하게되면
	단순히 메모리주소의 값이 1이 증가하는 것이 아니다. int 포인터의 걍우
	int 타입의 메모리 주소를 갖게 되는데 메모리 주소에 1을 더해주면
	1증가가 아닌 가리키는 해당 포인터타입의 변수타입 크기만큼 증가하게 된다.
	int형 포인터이므로 int의 크기인 4만큼 값이 증가하게 된다.
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;


	// char *pText = "테스트 문자열"의 경우 정상적으로 선언되지 않음. cosnt형식으로 선언할
	// 필요가 있음
	const char *pText = "테스트 문자열";

	cout << pText << endl;
	cout << (int*)pText << endl;

	// 포인터형 변수이므로 가리키는 값 변경 가능. 출력을 통해 확인해보면 값 및 주소값이
	// 전부 바뀌는것을 확인할 수 있음.
	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// 같은 값으로 변경시에는 주소값이 변경되지 않음
	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// 한 글자라도 달라지는 경우 주소 값 변경
	pText = "abcdefh";
	cout << pText << endl;
	cout << (int*)pText << endl;

	char str[8] = "abcdefg";

	// 같은 값을 가진 다른 배열의 경우 값이 다름. 이 배열은 값을 변경할 경우에도
	// 주소의 변경이 일어나지 않음
	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;
	str[0] = 'b';
	str[1] = 'c';
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl << endl;


	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	// 연산자 우선순위 때문에 .을 *보다 먼저 인식하게 된다.
	// 즉 메모리주소. 은 잘못된 문법이며, *pStudent를 괄호로 감싼 후
	// .을 이용하여 가리키는 대상의 멤버변수에 접근해야 한다.

	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;

	// 메모리주소 -> 을 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
	pStudent->iKor = 80;
	cout << tStudent.iKor << endl;

	// void : 타입이 없다. void의 포인터타입을 활용할 수 있다.
	// void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든
	// 모두 저장이 가능하다. 단 역참조가 불가능하고 메모리 주소만 저장이
	// 가능하다. 메모리 주소를 저장하기 위한 버퍼로 사용된다.
	void* pVoid = &iNumber;
	cout << "iNumber Address : " << pVoid << endl;
	// *pVoid = 10; 같은 역참조는 불가능하다. 이를 실행하기 위해서는
	// 형변환이 필요하다.
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	cout << iNumber << endl;
	*((int*)pVoid) = 99999;
	cout << iNumber << endl;


	pVoid = &tStudent;
	cout << "tStudent Address : " << pVoid << endl;

	
	// 이중 포인터 : *을 2개 붙인다. 일반 포인터 변수가 일반 변수의 메모리
	// 주소를 저장하는 변수라면 이중포인터는 포인터의 포인터이다. 즉, 이중
	// 포인터는 포인텨 변수의 메모리 주소를 저장하는 포인터이다.

	int iNumber1 = 1111;
	iNumber = 2222;

	pNum = &iNumber;
	int** ppNum = &pNum;

	*pNum = 3333;

	cout << "iNumber : " << iNumber << endl;
	cout << "iNumber Addr : " << &iNumber << endl;
	cout << "*pNum : " << *pNum << endl;	
	cout << "pNum  Value : " << pNum << endl;
	cout << "pNum Addr : " << &pNum << endl;
	cout << "*ppNum : " << *ppNum << endl;
	cout << "**ppNum : " << **ppNum << endl;
	cout << "ppNum Value : " << ppNum << endl;
	cout << "ppNum Addr : " << &ppNum << endl;

	return 0;
}
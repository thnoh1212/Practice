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
	������ :  ����Ű��. �Ϲ� ������ �Ϲ����� ���� �����ϰ� ������ ������
	������ �޸� �ּҸ� �����ϰ� �ȴ�. ��� ���� Ÿ���� ������ Ÿ����
	������ �� �ִ�. int������ �ּҴ� int ������ ������ ������ �ؾ� �Ѵ�.
	�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ x86���� �����Ҷ���
	������ 4byte�� ���´�. x64�϶��� 8byte�� ���´�.
	
	�����ʹ� �ڱ� ������ �ƹ��� �ϵ� �� �� ����. �ݵ�� �ٸ� ������ �޸�
	�ּҸ� ������ �־�� ���� �� �� �ִµ� ������ �ִ� �� �޸� �ּҿ�
	�����ؼ� ���� ������ �� �ִ�.

	������ ��� ���� : �ٸ� ������ �޸� �ּҸ� �������� ���� �����ϱ� ���ؼ�

	���� : ����Ÿ�� *������; �� ���·� �����Ѵ�.
	*/ 
	
	int iNumber = 100;
	// ���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ ����ȴ�.

	int* pNum = &iNumber;

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum�� �̿��ؼ� iNumber�� ���� �����غ���.
	// �������� �̿��ؼ� ���� �����ų� ������ �� �ִ�.
	// �������� ������ ���� �տ� *�� ���̰� �Ǹ� �������� �ȴ�.
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	/*
	�����Ϳ� �迭�� ���� :  �迭���� �����ʹ�. �迭�� ��ü�� �ش� �迭��
	�޸𸮿����� ������ �ּҸ� �ǹ��Ѵ�. 
	*/

	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray[0] << endl;

	int* pArray = iArray;
	
	cout << pArray[2] << endl;

	/*
	������ ���� :  +, - ������ �����Ѵ�. ++, -- �� �����ѵ� 1�� �����ϰԵǸ�
	�ܼ��� �޸��ּ��� ���� 1�� �����ϴ� ���� �ƴϴ�. int �������� ����
	int Ÿ���� �޸� �ּҸ� ���� �Ǵµ� �޸� �ּҿ� 1�� �����ָ�
	1������ �ƴ� ����Ű�� �ش� ������Ÿ���� ����Ÿ�� ũ�⸸ŭ �����ϰ� �ȴ�.
	int�� �������̹Ƿ� int�� ũ���� 4��ŭ ���� �����ϰ� �ȴ�.
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;


	// char *pText = "�׽�Ʈ ���ڿ�"�� ��� ���������� ������� ����. cosnt�������� ������
	// �ʿ䰡 ����
	const char *pText = "�׽�Ʈ ���ڿ�";

	cout << pText << endl;
	cout << (int*)pText << endl;

	// �������� �����̹Ƿ� ����Ű�� �� ���� ����. ����� ���� Ȯ���غ��� �� �� �ּҰ���
	// ���� �ٲ�°��� Ȯ���� �� ����.
	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// ���� ������ ����ÿ��� �ּҰ��� ������� ����
	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// �� ���ڶ� �޶����� ��� �ּ� �� ����
	pText = "abcdefh";
	cout << pText << endl;
	cout << (int*)pText << endl;

	char str[8] = "abcdefg";

	// ���� ���� ���� �ٸ� �迭�� ��� ���� �ٸ�. �� �迭�� ���� ������ ��쿡��
	// �ּ��� ������ �Ͼ�� ����
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

	// ������ �켱���� ������ .�� *���� ���� �ν��ϰ� �ȴ�.
	// �� �޸��ּ�. �� �߸��� �����̸�, *pStudent�� ��ȣ�� ���� ��
	// .�� �̿��Ͽ� ����Ű�� ����� ��������� �����ؾ� �Ѵ�.

	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;

	// �޸��ּ� -> �� �̿��ؼ� ����Ű�� ����� ����� ������ �� �ִ�.
	pStudent->iKor = 80;
	cout << tStudent.iKor << endl;

	// void : Ÿ���� ����. void�� ������Ÿ���� Ȱ���� �� �ִ�.
	// void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ�
	// ��� ������ �����ϴ�. �� �������� �Ұ����ϰ� �޸� �ּҸ� ������
	// �����ϴ�. �޸� �ּҸ� �����ϱ� ���� ���۷� ���ȴ�.
	void* pVoid = &iNumber;
	cout << "iNumber Address : " << pVoid << endl;
	// *pVoid = 10; ���� �������� �Ұ����ϴ�. �̸� �����ϱ� ���ؼ���
	// ����ȯ�� �ʿ��ϴ�.
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	cout << iNumber << endl;
	*((int*)pVoid) = 99999;
	cout << iNumber << endl;


	pVoid = &tStudent;
	cout << "tStudent Address : " << pVoid << endl;

	
	// ���� ������ : *�� 2�� ���δ�. �Ϲ� ������ ������ �Ϲ� ������ �޸�
	// �ּҸ� �����ϴ� ������� ���������ʹ� �������� �������̴�. ��, ����
	// �����ʹ� ������ ������ �޸� �ּҸ� �����ϴ� �������̴�.

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
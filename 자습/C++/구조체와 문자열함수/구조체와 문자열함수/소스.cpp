#include <iostream>

using namespace std;

#define NAME_SIZE 32
/*
����ü : �����ִ� ������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�.
��������� ���� Ÿ���̴�.
���� : struct ����ü��{}; �� ���·� �����ȴ�.
�迭�� ����ü�� ������ : 
	1. ������ �����̴�.
	2. ���ӵ� �޸� ���� �Ҵ�ȴ�. ����ü ������� ���ӵ� �޸� ������ ������ �ȴ�.
*/

struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main() 
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// ����ü ����� �����Ҷ��� . �� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;

	//tStudent.strName = "sgnasldgnlsdkng";
	// ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
	// strcpy_s ��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
	// �� �Լ��� �����ʿ� �ִ� ���ڿ��� �������� �������ش�.
	strcpy_s(tStudent.strName, "�̸��̸� name");
	// ���ڿ��� ���� �׻� 0(NULL)�� ������ �Ѵ�. �׷��� �����Ⱚ�� ���ִ�
	// ���¿��� �Ʒ�ó�� �� �迭 ��ҿ� ���� �־��ְ� �Ǹ� �� ���� ��µǰ�
	// �־����� ���� �κ��� �����Ⱚ���� �״�� ��µȴ�. �ֳ��ϸ� ����� ��
	// ���ڿ��� ���� �ν��� �� ���� �����̴�. 0�� ���̰ž� �ϴµ� �����Ⱚ��
	// ���ֱ� �����̴�.
	//tStudent.strName[0] = 'a';
	//tStudent.strName[1] = 'b';z
	//tStudent.strName[2] = 0;
	
	strcat_s(tStudent.strName, "���ڿ����̱�");
	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	// �����ʿ� �ִ� ���ڿ��� ���ʿ��� �ٿ��ش�. strName���� ������
	// �̹� ���ڿ��� ������ �ξ��� ������ �� �ڿ� �߰��� ���ڿ��� ���Ͽ�
	// ���ڿ��� �����Ѵ�.

	
	strcpy_s(tStudent.strName, "ȫ�浿");
	// strcpy_s �Լ��� ���ڿ��� �����ϴ� ����̴�.
	// ���ʿ� ����� ���ڿ��� �����ʿ� �ִ� ���ڿ��� �������ִ� ����� �Ѵ�.

	cout << "���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
		cout << "�л��� ã�ҽ��ϴ�." << endl;
	else
		cout << "ã�� �л��� �����ϴ�." << endl;
	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ� �ٸ� ���
	// 0�� �ƴ� ���� ��ȯ�Ѵ�.

	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;
	
	return 0;
}
#include "List.h"


int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	iSize -= 1;
	cin.getline(pString, iSize);
}



void InitList(PLIST pList)
{

	pList->iSize = 0;

	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	// ���۳���� ���� ���� ������ ����̴�.
	pList->pBegin->pNext = pList->pEnd;
	// ����������� ���� ���� ���۳���̴�.
	pList->pEnd->pPrev = pList->pBegin;

	// ������ ����� ���� ���� �����Ƿ� NULL�� ���ش�.
	pList->pEnd->pNext = NULL;
	// ���۳���� ���� ���� �����Ƿ� NULL�� ���ش�.
	pList->pBegin->pPrev = NULL;

}

void DestoryList(PLIST pList)
{

	PNODE pNode = pList->pBegin;
	
	while (pNode != NULL) {
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

void Push_Back(PLIST pList)
{
	system("cls");
	cout << "============================== �л��߰� ==============================\n";
	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "���� : ";
	tStudent.iKor = InputInt();

	cout << "���� : ";
	tStudent.iEng = InputInt();

	cout << "���� : ";
	tStudent.iMath = InputInt();

	tStudent.iNumber = pList->iSize;
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;

	// ���� �߰��Ǵ� ���� End ����� ���� ���� End ��� ���̿� �߰��ؾ� �Ѵ�.
	// �׷��� End�� prev��带 ���س��´�.
	PNODE pPrev = pList->pEnd->pPrev;

	// pEnd ��� ���� ����� �������� �߰��� ��带 �����Ѵ�.
	pPrev->pNext = pNode;
	// �߰��� ����� ���� ���� End�� ���� ��带 �����Ѵ�.
	pNode->pPrev = pPrev;

	// ���� �߰��� ����� ���� ��带 pEnd�� �����Ѵ�.
	pNode->pNext = pList->pEnd;

	// pEnd ����� ���� ���� ���� �߰��� ��带 �����Ѵ�.
	pList->pEnd->pPrev = pNode;

	++pList->iSize;

}

void Push_Front(PLIST pList)
{
}

void OutputStudent(const PSTUDENT pStudent) {
	cout << "�̸� : " << pStudent->strName << "\t�й� : " << pStudent->iNumber << "\n";
	cout << "���� : " << pStudent->iKor << "\t���� : " << pStudent->iEng << "\n";
	cout << "���� : " << pStudent->iMath << "\n";
	cout << "���� : " << pStudent->iTotal << "\t��� : " << pStudent->fAvg << endl;
}

void Output(PLIST pList)
{
	OUTPUT_TYPE oMenu;
	while(true)
	{
		system("cls");
		cout << "============================== �л���� ==============================\n";
		cout << "1. ������ ���\n";
		cout << "2. ������ ���\n";
		cout << "�޴��� �����ϼ��� : ";
		oMenu = OUTPUT_TYPE(InputInt());  
	
		if (oMenu > OUTPUT_TYPE::NONE&& oMenu <= OUTPUT_TYPE::INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (oMenu)
	{
	case OUTPUT_TYPE::OUTPUT:
		// �߰��Ǵ� ������ begin�� end ���̿� ��ġ�ȴ�. �׷��Ƿ� begin�� ���� ��带
		// ���´�.
		pNode = pList->pBegin->pNext;
		// ��尡 End���� �������� �� �̻� ����� ��尡 �����Ƿ� �ݺ��� �����Ѵ�.
		while(pNode != pList->pEnd)
		{
			OutputStudent(&pNode->tStudent);
			cout << '\n';
			pNode = pNode->pNext;
		}
		break;
	case OUTPUT_TYPE::INVERSE:
		// ���������� ����� �� ���� end�� ���� ��带 ������ ��� ���� ���� �����Ѵ�.
		// begin�� ������ ��� �ݺ��� �����Ѵ�.
		pNode = pList->pEnd->pPrev;

		// ���������� ���� ������ ��尡 begin�� �������� ���̻� ����� ��尡 �����Ƿ� 
		// �ݺ��� �����Ѵ�.
		while (pNode != pList->pBegin) {
			OutputStudent(&pNode->tStudent);
			cout << '\n';
			pNode = pNode->pPrev;
		}
		pNode = pList->pEnd->pPrev;
		break;
	}
	cout << "�л� �� : " << pList->iSize << "\n";
	system("pause");
}

void Search(PLIST pList)
{
	system("cls");
	cout << "============================== �л���� ==============================\n";

	cout << "Ž���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		
		pNode = pNode->pNext;
	}

	cout << "�Է¹��� �л��� ������ �������� �ʽ��ϴ�.\n";
	system("pause");
}

void Delete(PLIST pList)
{
	system("cls");
	cout << "============================== �л����� ==============================\n";

	cout << "������ �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			// ���� ���� ����� ��������� ������ ���� ���� ���� �Ǿ��ִ�.
			// �׷��� ���� ���� �������� �ϱ� ������ ��������� ���� ��带
			// ���� ����� ���� ���� �ش�.
			// ���� ����� ������ ���� ����ε� �̸� ���� ���� �ش�.
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << " �л��� ������ �����Ͽ����ϴ�.\n";
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "������ ����� ã�� �� �����ϴ�.\n";
	system("pause");
}

void Sort(PLIST pList)
{

	while (true) {
		system("cls");
		cout << "============================== �л����� ==============================\n";
		cout << "1. �й�����\n";
		cout << "2. ��ձ���\n";
		cout << "�޴��� �����ϼ��� : ";
		SORT_TYPE sType = SORT_TYPE(InputInt());

		if (sType <= SORT_TYPE::NONE || sType > SORT_TYPE::AVG)
		{
			cout << "�߸� �����Ͽ����ϴ�.\n";
			system("pause");
			return;
		}

		PNODE pFirst = pList->pBegin->pNext;
		PNODE pSecond = pFirst->pNext;

		// pFirst�� End�� ���� ���� �������� �Ǹ� ���̻� ���� ��尡 �����Ƿ�
		// �����Ѵ�.
		while (pFirst != pList->pEnd->pPrev)
		{
			// pSecond�� ������ pFirst ���� ������ �˻縦 �����Ѵ�.
			pSecond = pFirst->pNext;
			
			// Second�� End �������� �ݺ��ؾ� �ϹǷ� End�� �ƴҵ��� �ݺ��Ѵ�.
			while (pSecond != pList->pEnd)
			{
				bool bSwap = false;

				
				switch (sType)
				{
				case SORT_TYPE::NUMBER:
					if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber)
						bSwap = true;
					break;
				case SORT_TYPE::AVG:
					if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg)
						bSwap = true;
					break;
				}

				// bool ���� bSwap�� true�� ��� �� ��带 �ٲ�� �Ѵٴ� ���̴�.
				if(bSwap)
				{
					// First����� ������ ���� ��带 �����Ѵ�.
					PNODE pFirstPrev = pFirst->pPrev;
					PNODE pFirstNext = pFirst->pNext;
					// Second����� ������ ������带 �����Ѵ�.
					PNODE pSecondPrev = pSecond->pPrev;
					PNODE pSecondNext = pSecond->pNext;

					pFirstPrev->pNext = pSecond;
					pSecond->pPrev = pFirstPrev;

					// �ٲٷ��� �� ��尡 ������ �ִ� ���
					if (pSecond != pFirstNext)
					{
						pFirstNext->pPrev = pSecond;
						pSecond->pNext = pFirstNext;

						pSecondPrev->pNext = pSecond;
						pSecond->pPrev = pSecondPrev;
					}
					else
					{
						pSecond->pNext = pFirst;
						pFirst->pPrev = pSecond;
					}

					pSecondNext->pPrev ��= pFirst;
					pFirst->pNext = pSecondNext;

					PNODE pTemp = pFirst;
					pFirst = pSecond;
					pSecond = pTemp;
				}
				pSecond = pSecond->pNext;
			}
			pFirst = pFirst->pNext;
		}
		cout << "������ �Ϸ�Ǿ����ϴ�.\n";
		system("pause");
		return;
	}
	
}




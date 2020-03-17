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

	// 시작노드의 다음 노드는 마지막 노드이다.
	pList->pBegin->pNext = pList->pEnd;
	// 마지막노드의 이전 노드는 시작노드이다.
	pList->pEnd->pPrev = pList->pBegin;

	// 마지막 노드의 다음 노드는 없으므로 NULL로 해준다.
	pList->pEnd->pNext = NULL;
	// 시작노드의 이전 노드는 없으므로 NULL로 해준다.
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
	cout << "============================== 학생추가 ==============================\n";
	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "국어 : ";
	tStudent.iKor = InputInt();

	cout << "영어 : ";
	tStudent.iEng = InputInt();

	cout << "수학 : ";
	tStudent.iMath = InputInt();

	tStudent.iNumber = pList->iSize;
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;

	// 새로 추가되는 노드는 End 노드의 이전 노드와 End 노드 사이에 추가해야 한다.
	// 그래서 End의 prev노드를 구해놓는다.
	PNODE pPrev = pList->pEnd->pPrev;

	// pEnd 노드 이전 노드의 다음으로 추가할 노드를 지정한다.
	pPrev->pNext = pNode;
	// 추가할 노드의 이전 노드로 End의 이전 노드를 지정한다.
	pNode->pPrev = pPrev;

	// 새로 추가할 노드의 다음 노드를 pEnd에 연결한다.
	pNode->pNext = pList->pEnd;

	// pEnd 노드의 이전 노드로 새로 추가할 노드를 지정한다.
	pList->pEnd->pPrev = pNode;

	++pList->iSize;

}

void Push_Front(PLIST pList)
{
}

void OutputStudent(const PSTUDENT pStudent) {
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << "\n";
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << "\n";
	cout << "수학 : " << pStudent->iMath << "\n";
	cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl;
}

void Output(PLIST pList)
{
	OUTPUT_TYPE oMenu;
	while(true)
	{
		system("cls");
		cout << "============================== 학생출력 ==============================\n";
		cout << "1. 정방향 출력\n";
		cout << "2. 역방향 출력\n";
		cout << "메뉴를 선택하세요 : ";
		oMenu = OUTPUT_TYPE(InputInt());  
	
		if (oMenu > OUTPUT_TYPE::NONE&& oMenu <= OUTPUT_TYPE::INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (oMenu)
	{
	case OUTPUT_TYPE::OUTPUT:
		// 추가되는 노드들은 begin과 end 사이에 배치된다. 그러므로 begin의 다음 노드를
		// 얻어온다.
		pNode = pList->pBegin->pNext;
		// 노드가 End노드와 같아지면 더 이상 출력할 노드가 없으므로 반복을 종료한다.
		while(pNode != pList->pEnd)
		{
			OutputStudent(&pNode->tStudent);
			cout << '\n';
			pNode = pNode->pNext;
		}
		break;
	case OUTPUT_TYPE::INVERSE:
		// 역방향으로 출력을 할 때는 end의 이전 노드를 얻어오고 계속 이전 노드로 진행한다.
		// begin과 같아질 경우 반복을 종료한다.
		pNode = pList->pEnd->pPrev;

		// 역방향으로 들어가기 때문에 노드가 begin과 같아지면 더이상 출력할 노드가 없으므로 
		// 반복을 종료한다.
		while (pNode != pList->pBegin) {
			OutputStudent(&pNode->tStudent);
			cout << '\n';
			pNode = pNode->pPrev;
		}
		pNode = pList->pEnd->pPrev;
		break;
	}
	cout << "학생 수 : " << pList->iSize << "\n";
	system("pause");
}

void Search(PLIST pList)
{
	system("cls");
	cout << "============================== 학생출력 ==============================\n";

	cout << "탐색할 이름을 입력하세요 : ";
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

	cout << "입력받은 학생의 정보가 존재하지 않습니다.\n";
	system("pause");
}

void Delete(PLIST pList)
{
	system("cls");
	cout << "============================== 학생삭제 ==============================\n";

	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			// 현재 지울 노드의 이전노드의 다음은 현재 지울 노드로 되어있다.
			// 그런데 지울 노드는 지워져야 하기 때문에 이전노드의 다음 노드를
			// 지울 노드의 다음 노드로 준다.
			// 다음 노드의 이전은 현재 노드인데 이를 이전 노드로 준다.
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << " 학생의 정보를 삭제하였습니다.\n";
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "삭제할 대상을 찾을 수 없습니다.\n";
	system("pause");
}

void Sort(PLIST pList)
{

	while (true) {
		system("cls");
		cout << "============================== 학생정렬 ==============================\n";
		cout << "1. 학번기준\n";
		cout << "2. 평균기준\n";
		cout << "메뉴를 선택하세요 : ";
		SORT_TYPE sType = SORT_TYPE(InputInt());

		if (sType <= SORT_TYPE::NONE || sType > SORT_TYPE::AVG)
		{
			cout << "잘못 선택하였습니다.\n";
			system("pause");
			return;
		}

		PNODE pFirst = pList->pBegin->pNext;
		PNODE pSecond = pFirst->pNext;

		// pFirst는 End의 이전 노드와 같아지게 되면 더이상 비교할 노드가 없으므로
		// 종료한다.
		while (pFirst != pList->pEnd->pPrev)
		{
			// pSecond는 무조건 pFirst 다음 노드부터 검사를 시작한다.
			pSecond = pFirst->pNext;
			
			// Second는 End 이전까지 반복해야 하므로 End가 아닐동안 반복한다.
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

				// bool 변수 bSwap가 true일 경우 두 노드를 바꿔야 한다는 것이다.
				if(bSwap)
				{
					// First노드의 이전과 다음 노드를 저장한다.
					PNODE pFirstPrev = pFirst->pPrev;
					PNODE pFirstNext = pFirst->pNext;
					// Second노드의 이전과 다음노드를 저장한다.
					PNODE pSecondPrev = pSecond->pPrev;
					PNODE pSecondNext = pSecond->pNext;

					pFirstPrev->pNext = pSecond;
					pSecond->pPrev = pFirstPrev;

					// 바꾸려는 두 노드가 떨어져 있는 경우
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

					pSecondNext->pPrev ㅜ= pFirst;
					pFirst->pNext = pSecondNext;

					PNODE pTemp = pFirst;
					pFirst = pSecond;
					pSecond = pTemp;
				}
				pSecond = pSecond->pNext;
			}
			pFirst = pFirst->pNext;
		}
		cout << "정렬이 완료되었습니다.\n";
		system("pause");
		return;
	}
	
}




#include <iostream>

using namespace std;

#define NAME_SIZE 20

typedef struct _tagStudent {
    char strName[NAME_SIZE];
    int iNumber;
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
}STUDENT, * PSTUDENT;

enum class MAIN_MENU {
    NONE,
    INSERT,
    DELETE,
    SEARCH,
    OUTPUT,
    EXIT
};

/*
링크드리스트 : 자료구조의 한 종류이다. 자료구조란 데이터를 관리하는 방법을 말한다.
링크드리스트는 데이터 목록을 연결시켜서 접근할 수 있는 구조를 제공한다.
링크드리스트는 데이터를 저장하기 위한 노드라는 것이 존재한다. 각 노드의 특징은
다음 노드를 알 수 있게 된다.(다음 노드의 메모리 주소를 저장하고 있다.)
리스트는 선형 구조로 되어 있다. 그렇기 때문에 배열처럼 특정 요소에 바로 접근이 불가능하다.
노드를 새로 추가할때는 노드 추가 후 마지막 노드에 연결만 하면 되기때문에 메모무조건 앞에서부터 차례대로 타고 들어가야 한다.
리가 허용하는 한
개수의 제한이 없다.
*/

// 리스트 노드를 만든다.
typedef struct _tagNode {
    STUDENT tStudent;
    _tagNode* pNext;
}NODE, * PNODE;

//리스트 구조체를 만들어준다.
typedef struct _tagList {
    PNODE pBegin;
    PNODE pEnd;
    int iSize;
}LIST, * PLIST;

void InitList(PLIST pList) {
    // 포인터는 가급적 초기화할 때 NULL(0)으로 초기화해두고 쓰는 것이 좋다.
    // 왜나하면 0은 false 0이 아닌 모든 수는 true이기 때문이다.
    // 초기화를 하지 않을 경우 쓰레기값이 저장되는데 이 쓰레기값도 true로 판단된다.
    pList->pBegin = NULL;
    pList->pEnd = NULL;
    pList->iSize = 0;
}

int InputInt() {
    int iInput;
    cin >> iInput;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1024, '\n');
        return INT_MAX;
    }
    return iInput;
}

MAIN_MENU OutputMenu() {
    system("cls");
    cout << "1. 학생추가\n";
    cout << "2. 학생삭제\n";
    cout << "3. 학생탐색\n";
    cout << "4. 학생출력\n";
    cout << "5. 종료\n";
    cout << "메뉴를 선택하세요 : ";
    MAIN_MENU mInput = MAIN_MENU(InputInt());

    if (mInput <= MAIN_MENU::NONE || mInput > MAIN_MENU::EXIT)
        return MAIN_MENU::NONE;

    return mInput;
}

void InputString(char* pString, int iSize) {
    cin.clear();
    cin.ignore(1024, '\n');
    cin.getline(pString, iSize - 1);
}

void Insert(PLIST pList) {
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

    // 추가할 리스트 노드를 생성한다.
    PNODE pNode = new NODE;

    // 현재 추가하는 노드는 가장 마지막에 추가될 것이기 때문에 다음 노드가 존재하지 않는다.
    // 그래서 다음 노드는 NULL로 초기화하고 정보는 위에서 입력받은 학생 정보를
    // 주도록 한다.
    pNode->pNext = NULL;
    pNode->tStudent = tStudent;

    if (pList->pBegin == NULL)
        pList->pBegin = pNode;
    else
        pList->pEnd->pNext = pNode;

    pList->pEnd = pNode;
    pList->iSize++;
}

void ClearList(PLIST pList) {
    PNODE pNode = pList->pBegin;
    
    while (pNode != NULL) {
        PNODE pNext = pNode->pNext;
        delete pNode;
        pNode = pNext;
    }

    pList->pBegin = NULL;
    pList->pEnd = NULL;
    pList->iSize = 0;
}

// 출력만 하는 용도로 사용하는 함수이므로 const로 선언하여 값 변경 방지
void OutputStudent(const PSTUDENT pStudent) {
    cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << "\n";
    cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << "\n";
    cout << "수학 : " << pStudent->iMath << "\n";
    cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl;
}

void Output(PLIST pList) {
    system("cls");
    cout << "============================== 학생출력 ==============================\n";
    
    PNODE pNode = pList->pBegin;

    while (pNode != NULL) {
        OutputStudent(&pNode->tStudent);
        pNode = pNode->pNext;
    }

    cout << "학생수 : " << pList->iSize << "\n";
    system("pause");
}

void Search(PLIST pList) {
    system("cls");
    cout << "============================== 학생출력 ==============================\n";

    cout << "탐색할 이름을 입력하세요 : ";
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);

    PNODE pNode = pList->pBegin;

    while (pNode != NULL) {
        if (strcmp(pNode->tStudent.strName, strName) == 0) {
            OutputStudent(&pNode->tStudent);
            system("pause");
            return;
        }
        pNode = pNode->pNext;
    }
    cout << "찾는 학생이 없습니다.\n";
    system("pause");
}

void Delete(PLIST pList) {
    system("cls");
    cout << "============================== 학생삭제 ==============================\n";

    cout << "삭제할 이름을 입력하세요 : ";
    char strName[NAME_SIZE] = {};
    InputString(strName, NAME_SIZE);

    PNODE pNode = pList->pBegin;
    PNODE pPrev = NULL;
    while (pNode != NULL) {
        if (strcmp(pNode->tStudent.strName, strName) == 0) {
                
            PNODE pNext = pNode->pNext;
            if (pPrev == NULL) {
                delete pNode;
                pList->pBegin = pNext;
                if (pNext == NULL)
                    pList->pEnd = NULL;
            }
            else {
                pPrev->pNext = pNext;
                delete pNode;
                if (pNext == NULL)
                    pList->pEnd = pPrev;
            }
            cout << strName << "학생 삭제 완료!!\n";
            pList->iSize--;
            system("pause");
            return;
        }
        pPrev = pNode;
        pNode = pNode->pNext;
    }
    cout << "삭제하려는 학생을 찾을 수 없습니다.\n";
    system("pause");
}
int main()
{
    LIST tList;
    InitList(&tList);

    while (true)
    {
        MAIN_MENU Menu = OutputMenu();

        if (Menu == MAIN_MENU::EXIT)
            break;

        switch (Menu) {
        case MAIN_MENU::INSERT:
            Insert(&tList);
            break;
        case MAIN_MENU::DELETE:
            Delete(&tList);
            break;
        case MAIN_MENU::SEARCH:
            Search(&tList);
            break;
        case MAIN_MENU::OUTPUT:
            Output(&tList);
            break;


        }
    }
    ClearList(&tList);
}
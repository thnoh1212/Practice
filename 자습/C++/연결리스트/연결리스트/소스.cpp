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
��ũ�帮��Ʈ : �ڷᱸ���� �� �����̴�. �ڷᱸ���� �����͸� �����ϴ� ����� ���Ѵ�.
��ũ�帮��Ʈ�� ������ ����� ������Ѽ� ������ �� �ִ� ������ �����Ѵ�.
��ũ�帮��Ʈ�� �����͸� �����ϱ� ���� ����� ���� �����Ѵ�. �� ����� Ư¡��
���� ��带 �� �� �ְ� �ȴ�.(���� ����� �޸� �ּҸ� �����ϰ� �ִ�.)
����Ʈ�� ���� ������ �Ǿ� �ִ�. �׷��� ������ �迭ó�� Ư�� ��ҿ� �ٷ� ������ �Ұ����ϴ�.
��带 ���� �߰��Ҷ��� ��� �߰� �� ������ ��忡 ���Ḹ �ϸ� �Ǳ⶧���� �޸����� �տ������� ���ʴ�� Ÿ�� ���� �Ѵ�.
���� ����ϴ� ��
������ ������ ����.
*/

// ����Ʈ ��带 �����.
typedef struct _tagNode {
    STUDENT tStudent;
    _tagNode* pNext;
}NODE, * PNODE;

//����Ʈ ����ü�� ������ش�.
typedef struct _tagList {
    PNODE pBegin;
    PNODE pEnd;
    int iSize;
}LIST, * PLIST;

void InitList(PLIST pList) {
    // �����ʹ� ������ �ʱ�ȭ�� �� NULL(0)���� �ʱ�ȭ�صΰ� ���� ���� ����.
    // �ֳ��ϸ� 0�� false 0�� �ƴ� ��� ���� true�̱� �����̴�.
    // �ʱ�ȭ�� ���� ���� ��� �����Ⱚ�� ����Ǵµ� �� �����Ⱚ�� true�� �Ǵܵȴ�.
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
    cout << "1. �л��߰�\n";
    cout << "2. �л�����\n";
    cout << "3. �л�Ž��\n";
    cout << "4. �л����\n";
    cout << "5. ����\n";
    cout << "�޴��� �����ϼ��� : ";
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

    // �߰��� ����Ʈ ��带 �����Ѵ�.
    PNODE pNode = new NODE;

    // ���� �߰��ϴ� ���� ���� �������� �߰��� ���̱� ������ ���� ��尡 �������� �ʴ´�.
    // �׷��� ���� ���� NULL�� �ʱ�ȭ�ϰ� ������ ������ �Է¹��� �л� ������
    // �ֵ��� �Ѵ�.
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

// ��¸� �ϴ� �뵵�� ����ϴ� �Լ��̹Ƿ� const�� �����Ͽ� �� ���� ����
void OutputStudent(const PSTUDENT pStudent) {
    cout << "�̸� : " << pStudent->strName << "\t�й� : " << pStudent->iNumber << "\n";
    cout << "���� : " << pStudent->iKor << "\t���� : " << pStudent->iEng << "\n";
    cout << "���� : " << pStudent->iMath << "\n";
    cout << "���� : " << pStudent->iTotal << "\t��� : " << pStudent->fAvg << endl;
}

void Output(PLIST pList) {
    system("cls");
    cout << "============================== �л���� ==============================\n";
    
    PNODE pNode = pList->pBegin;

    while (pNode != NULL) {
        OutputStudent(&pNode->tStudent);
        pNode = pNode->pNext;
    }

    cout << "�л��� : " << pList->iSize << "\n";
    system("pause");
}

void Search(PLIST pList) {
    system("cls");
    cout << "============================== �л���� ==============================\n";

    cout << "Ž���� �̸��� �Է��ϼ��� : ";
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
    cout << "ã�� �л��� �����ϴ�.\n";
    system("pause");
}

void Delete(PLIST pList) {
    system("cls");
    cout << "============================== �л����� ==============================\n";

    cout << "������ �̸��� �Է��ϼ��� : ";
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
            cout << strName << "�л� ���� �Ϸ�!!\n";
            pList->iSize--;
            system("pause");
            return;
        }
        pPrev = pNode;
        pNode = pNode->pNext;
    }
    cout << "�����Ϸ��� �л��� ã�� �� �����ϴ�.\n";
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
#include <iostream>
#include <algorithm>
// ����ڰ� ���� ��������� ���Խ�ų���� "" �ȿ� �����ش�.
#include "List.h"
using namespace std;


enum class MAIN_MENU
{
	NONE,
	INSERT,
	DELETE,
	SEARCH,
	OUTPUT,
	SORT,
	EXIT
};

MAIN_MENU OutputMenu() 
{
	system("cls");
	cout << "1. �л��߰�\n";
	cout << "2. �л�����\n";
	cout << "3. �л�Ž��\n";
	cout << "4. �л����\n";
	cout << "5. �л�����\n";
	cout << "6. ����\n";
	cout << "�޴��� �����ϼ��� : ";
	MAIN_MENU mInput = MAIN_MENU(InputInt());

	if (mInput <= MAIN_MENU::NONE || mInput > MAIN_MENU::EXIT)
		return MAIN_MENU::NONE;

	return mInput;
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
			Push_Back(&tList);
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
		case MAIN_MENU::SORT:
			Sort(&tList);
			break;
		}
	}
	DestoryList(&tList);
	return 0;
}
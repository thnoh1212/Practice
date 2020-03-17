#include <iostream>
#include <algorithm>
// 사용자가 만든 헤더파일을 포함시킬때는 "" 안에 적어준다.
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
	cout << "1. 학생추가\n";
	cout << "2. 학생삭제\n";
	cout << "3. 학생탐색\n";
	cout << "4. 학생출력\n";
	cout << "5. 학생정렬\n";
	cout << "6. 종료\n";
	cout << "메뉴를 선택하세요 : ";
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
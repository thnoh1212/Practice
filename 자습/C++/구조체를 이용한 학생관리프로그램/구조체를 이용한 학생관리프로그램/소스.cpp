#include <iostream>

using namespace std;

#define NAME_MAX	32
#define STUDENT_MAX	10
#define ADDRESS_MAX	128
#define PHONE_MAX	14

struct _tagStudent {
	char	strName[NAME_MAX];
	char	strAddress[ADDRESS_MAX];
	char	strPhoneNumber[PHONE_MAX];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{	
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	int iStudentCount = 0;
	int iStudentNumber = 1;
	char	strSearchName[NAME_MAX] = {};

	while (true) {
		system("cls");

		//메뉴를 출력한다.
		cout << "1. 학생 등록\n";
		cout << "2. 학생 삭제\n";
		cout << "3. 학생 탐색\n";
		cout << "4. 학생 출력\n";
		cout << "5. 종료\n";
		cout << "메뉴를 선택하세요 : ";
		
		int iMenu; 
		cin >> iMenu;

		if (iMenu == MENU_EXIT)		break;

		// cin은 만약 오른쪽에 int형 변수가 온다면 정수를 입력받아야 한다. 오른쪽에
		// 위치한 변수형에 맞춰 값을 입력해야 하는데 다른 형태의 자료를 입력할 경우
		// 에러가 발생한다. 그렇기 때문에 예외처리로 에러가 발생하는 경우
		// 에러가 발생한 경우 cin 내부의 에러버퍼를 비워준 후
		// 입력버퍼에 남아있는 \n값을 지워주어야 한다

		if (cin.fail()) {
			cin.clear();
			// 에러버퍼를 청소한다

			cin.ignore(1024, '\n');
			// 입력버퍼를 순회하며 입력받은 값을 지워준다.
			// 위의 경우에는 1024크기만큼 순회하며 입력되어있는 \n값을 모두 지워준다.

			continue;
		}
		// cin.fail()함수는 cin함수에 오류가 발생한 경우에는 true값을 반환한다

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			// 학생을 추가하는 기능 구현. 이름 및 주소, 전화번호,
			// 국어, 영어, 수학 값을 입력받은 후 학번 및 총점, 평균은
			// 내부 계산을 통해 값을 저장한다.
			
			// 등록 가능한 학생 수를 초과한 경우 입력과정을 취소한다
			if (iStudentCount == STUDENT_MAX) {
				cout << "학생 정원 초과\n";
				break;
			}

			// 입력받을 시 주의사항
			// 1. 단순한 cin을 통해 입력값을 받는 경우에는 공백문자를 포함한
			//	  문자열을 받을 수 없으므로 주소지를 받을때는 사용할 수 없음
			//	  이를 해결하기 위해 cin.getline()함수 사용
			// 2. cin.getline()함수를 사용하며 연속적인 입력을 받아야 할 경우
			//    저번 입력시에 입력된 \n문자가 다음 입력에 영향을 미치므로
			//	  추가적인 입력을 받기 전 cin.ignore()함수를 사용한 입력버퍼
			//    초기화가 필요
			cout << "==================== 학 생 추 가 ====================\n\n";
			cout << "이    름 : ";
			cin >> tStudentArr[iStudentCount].strName;
			cin.ignore(1024, '\n');

			cout << "주    소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_MAX);

			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_MAX);

			cout << "국    어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영    어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수    학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal = tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng + tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3;

			tStudentArr[iStudentCount].iNumber = iStudentNumber;
			
			iStudentCount++;
			iStudentNumber++;

			cout << "학생 추가 완료\n";
			break;
		case MENU_DELETE:

			system("cls");
			cout << "==================== 학 생 삭 제 ====================\n\n";
			// 학생의 이름을 기반한 삭제방식으로 구현

			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strSearchName, NAME_MAX);

			// 등록된 학생 수 만큼 반복
			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strSearchName) == 0) {
					for(int j = i; j < iStudentCount-1; j++){
						tStudentArr[j] = tStudentArr[j + 1];
					}
					cout << "성공적으로 학생 데이터를 삭제했습니다.";
					break;
				}
				else if (i == iStudentCount - 1) {
					cout << "삭제할 학생정보가 등록되어 있지 않습니다.\n";
				}
			}
			iStudentCount--;

			break;
		case MENU_SEARCH:

			system("cls");
			cout << "==================== 학 생 탐 색 ====================\n\n";
			// 학생의 이름을 기반한 탐색방식으로 구현
			
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strSearchName, NAME_MAX);
				
			// 등록된 학생 수 만큼 반복
			for (int i = 0; i < iStudentCount; i++) {
				if(strcmp(tStudentArr[i].strName, strSearchName) == 0) {
					cout << " 이    름 : " << tStudentArr[i].strName << '\n';
					cout << " 주    소 : " << tStudentArr[i].strAddress << '\n';
					cout << " 전화번호 : " << tStudentArr[i].strPhoneNumber << '\n';
					cout << " 학    번 : " << tStudentArr[i].iNumber << '\n';
					cout << " 국    어 : " << tStudentArr[i].iKor << '\n';
					cout << " 영    어 : " << tStudentArr[i].iEng << '\n';
					cout << " 수    학 : " << tStudentArr[i].iMath << '\n';
					cout << " 총    점 : " << tStudentArr[i].iTotal << '\n';
					cout << " 평    균 : " << tStudentArr[i].fAvg << "\n\n";
					break;
				}
				else if (i == iStudentCount - 1) {
					cout << "찾는 학생이 등록되어 있지 않습니다.\n";
				}
			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "==================== 학 생 추 가 ====================\n\n";

			//등록된 학생 수 만큼 반복
			for (int i = 0; i < iStudentCount; i++) {
				cout << " 이    름 : " << tStudentArr[i].strName << '\n';
				cout << " 주    소 : " << tStudentArr[i].strAddress << '\n';
				cout << " 전화번호 : " << tStudentArr[i].strPhoneNumber << '\n';
				cout << " 학    번 : " << tStudentArr[i].iNumber << '\n';
				cout << " 국    어 : " << tStudentArr[i].iKor << '\n';
				cout << " 영    어 : " << tStudentArr[i].iEng << '\n';
				cout << " 수    학 : " << tStudentArr[i].iMath << '\n';
				cout << " 총    점 : " << tStudentArr[i].iTotal << '\n';
				cout << " 평    균 : " << tStudentArr[i].fAvg << "\n\n";
			}
			break;
		default:
			cout << "메뉴를 잘못 선택했습니다.\n";
			break;
		}
		system("pause");

	}
	return 0;
}
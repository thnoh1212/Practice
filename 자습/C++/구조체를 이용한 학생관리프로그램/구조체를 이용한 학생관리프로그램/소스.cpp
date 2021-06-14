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

		//�޴��� ����Ѵ�.
		cout << "1. �л� ���\n";
		cout << "2. �л� ����\n";
		cout << "3. �л� Ž��\n";
		cout << "4. �л� ���\n";
		cout << "5. ����\n";
		cout << "�޴��� �����ϼ��� : ";
		
		int iMenu; 
		cin >> iMenu;

		if (iMenu == MENU_EXIT)		break;

		// cin�� ���� �����ʿ� int�� ������ �´ٸ� ������ �Է¹޾ƾ� �Ѵ�. �����ʿ�
		// ��ġ�� �������� ���� ���� �Է��ؾ� �ϴµ� �ٸ� ������ �ڷḦ �Է��� ���
		// ������ �߻��Ѵ�. �׷��� ������ ����ó���� ������ �߻��ϴ� ���
		// ������ �߻��� ��� cin ������ �������۸� ����� ��
		// �Է¹��ۿ� �����ִ� \n���� �����־�� �Ѵ�

		if (cin.fail()) {
			cin.clear();
			// �������۸� û���Ѵ�

			cin.ignore(1024, '\n');
			// �Է¹��۸� ��ȸ�ϸ� �Է¹��� ���� �����ش�.
			// ���� ��쿡�� 1024ũ�⸸ŭ ��ȸ�ϸ� �ԷµǾ��ִ� \n���� ��� �����ش�.

			continue;
		}
		// cin.fail()�Լ��� cin�Լ��� ������ �߻��� ��쿡�� true���� ��ȯ�Ѵ�

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			// �л��� �߰��ϴ� ��� ����. �̸� �� �ּ�, ��ȭ��ȣ,
			// ����, ����, ���� ���� �Է¹��� �� �й� �� ����, �����
			// ���� ����� ���� ���� �����Ѵ�.
			
			// ��� ������ �л� ���� �ʰ��� ��� �Է°����� ����Ѵ�
			if (iStudentCount == STUDENT_MAX) {
				cout << "�л� ���� �ʰ�\n";
				break;
			}

			// �Է¹��� �� ���ǻ���
			// 1. �ܼ��� cin�� ���� �Է°��� �޴� ��쿡�� ���鹮�ڸ� ������
			//	  ���ڿ��� ���� �� �����Ƿ� �ּ����� �������� ����� �� ����
			//	  �̸� �ذ��ϱ� ���� cin.getline()�Լ� ���
			// 2. cin.getline()�Լ��� ����ϸ� �������� �Է��� �޾ƾ� �� ���
			//    ���� �Է½ÿ� �Էµ� \n���ڰ� ���� �Է¿� ������ ��ġ�Ƿ�
			//	  �߰����� �Է��� �ޱ� �� cin.ignore()�Լ��� ����� �Է¹���
			//    �ʱ�ȭ�� �ʿ�
			cout << "==================== �� �� �� �� ====================\n\n";
			cout << "��    �� : ";
			cin >> tStudentArr[iStudentCount].strName;
			cin.ignore(1024, '\n');

			cout << "��    �� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_MAX);

			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_MAX);

			cout << "��    �� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "��    �� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "��    �� : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal = tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng + tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3;

			tStudentArr[iStudentCount].iNumber = iStudentNumber;
			
			iStudentCount++;
			iStudentNumber++;

			cout << "�л� �߰� �Ϸ�\n";
			break;
		case MENU_DELETE:

			system("cls");
			cout << "==================== �� �� �� �� ====================\n\n";
			// �л��� �̸��� ����� ����������� ����

			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� : ";
			cin.getline(strSearchName, NAME_MAX);

			// ��ϵ� �л� �� ��ŭ �ݺ�
			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strSearchName) == 0) {
					for(int j = i; j < iStudentCount-1; j++){
						tStudentArr[j] = tStudentArr[j + 1];
					}
					cout << "���������� �л� �����͸� �����߽��ϴ�.";
					break;
				}
				else if (i == iStudentCount - 1) {
					cout << "������ �л������� ��ϵǾ� ���� �ʽ��ϴ�.\n";
				}
			}
			iStudentCount--;

			break;
		case MENU_SEARCH:

			system("cls");
			cout << "==================== �� �� Ž �� ====================\n\n";
			// �л��� �̸��� ����� Ž��������� ����
			
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� : ";
			cin.getline(strSearchName, NAME_MAX);
				
			// ��ϵ� �л� �� ��ŭ �ݺ�
			for (int i = 0; i < iStudentCount; i++) {
				if(strcmp(tStudentArr[i].strName, strSearchName) == 0) {
					cout << " ��    �� : " << tStudentArr[i].strName << '\n';
					cout << " ��    �� : " << tStudentArr[i].strAddress << '\n';
					cout << " ��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << '\n';
					cout << " ��    �� : " << tStudentArr[i].iNumber << '\n';
					cout << " ��    �� : " << tStudentArr[i].iKor << '\n';
					cout << " ��    �� : " << tStudentArr[i].iEng << '\n';
					cout << " ��    �� : " << tStudentArr[i].iMath << '\n';
					cout << " ��    �� : " << tStudentArr[i].iTotal << '\n';
					cout << " ��    �� : " << tStudentArr[i].fAvg << "\n\n";
					break;
				}
				else if (i == iStudentCount - 1) {
					cout << "ã�� �л��� ��ϵǾ� ���� �ʽ��ϴ�.\n";
				}
			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "==================== �� �� �� �� ====================\n\n";

			//��ϵ� �л� �� ��ŭ �ݺ�
			for (int i = 0; i < iStudentCount; i++) {
				cout << " ��    �� : " << tStudentArr[i].strName << '\n';
				cout << " ��    �� : " << tStudentArr[i].strAddress << '\n';
				cout << " ��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << '\n';
				cout << " ��    �� : " << tStudentArr[i].iNumber << '\n';
				cout << " ��    �� : " << tStudentArr[i].iKor << '\n';
				cout << " ��    �� : " << tStudentArr[i].iEng << '\n';
				cout << " ��    �� : " << tStudentArr[i].iMath << '\n';
				cout << " ��    �� : " << tStudentArr[i].iTotal << '\n';
				cout << " ��    �� : " << tStudentArr[i].fAvg << "\n\n";
			}
			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ�.\n";
			break;
		}
		system("pause");

	}
	return 0;
}
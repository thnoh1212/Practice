#include <iostream>
#include <time.h>

#include <conio.h>
// console input ouput ��������̴�. �ܼ�â���� ������ϴ� ��ɵ���
// �������ִ� ��������̴�.
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; i++) {
		iNumber[i] = i + 1;
	}

	//���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ����
	//����Ұǵ� INT_MAX��� ���� ����� ���̴�. INT_MAX�� �̹� ���ǵǾ��ִ� ������
	//int�� ǥ���� �� �ִ� �ִ밪�̴�.
	iNumber[24] = INT_MAX;
	int iStarIndex = 24;

	// ������ ������ �����ϰ� 1 ~ 24 ������ ���ڸ� �����ش�. �� �ε����� 0 ~ 23��
	// �ε��� ������ �����ش�.
	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	int count = 0;
	while(true){
		
		system("cls");
		cout << "������ Ƚ�� : " << count << "\n";
		for (int i = 0; i < 5; i++) {// i �� ������ �ǹ�.
			for (int j = 0; j < 5; j++) {// j �� ������ �ǹ�
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		bool bWin = true;

		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
		}
		
		if (bWin == true) {
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}
		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ����: ";
		char cInput = _getch();
		// _getch() �Լ��� ���� 1���� �Է¹޴� �Լ��̴�. �� �Լ��� Enter�� ġ��
		// �ʴ��� ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� �����Ѵ�.
		
		if (cInput == 'q' || cInput == 'Q')
			break;
		
		switch (cInput) {
		case 'w':
		case 'W':
			if(iStarIndex > 4){
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// ���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex - 5] = INT_MAX;
				// ���� ��ĭ ���� �ö����Ƿ� ��ĭ ���� �ε����� ������ش�.
				iStarIndex -= 5;
				count++;
			}
			break;
		case 's':
		case 'S':
			if (iStarIndex < 20) {
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				// ���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex + 5] = INT_MAX;
				// ���� ��ĭ ���� �ö����Ƿ� ��ĭ ���� �ε����� ������ش�.
				iStarIndex += 5;
				count++;
			}
			break;

		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0) {
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				// ���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex - 1] = INT_MAX;
				// ���� ��ĭ ���� �ö����Ƿ� ��ĭ ���� �ε����� ������ش�.
				iStarIndex -= 1;
				count++;
			}
			break;

		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4) {
				// ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				// ���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�.
				iNumber[iStarIndex + 1] = INT_MAX;
				// ���� ��ĭ ���� �ö����Ƿ� ��ĭ ���� �ε����� ������ش�.
				iStarIndex += 1;
				count++;
			}
			break;
		}
	}
	
	cout <<"\n������ �����մϴ�." << endl;
	return 0;

}
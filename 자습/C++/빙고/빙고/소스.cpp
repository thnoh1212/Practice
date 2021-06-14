#include <iostream>
#include <time.h>
using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER {
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

int main()
{
	int iNumber[25] = {};
	int iAINumber[25] = {};

	srand((unsigned int)time(0));

	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0, iAIMode;

	//AI ���̵��� �����Ѵ�.
	while(true){
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << " AI ��带 �����ϼ��� : ";
		cin >> iAIMode;
		
		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
			break;
	}


	// ���þȵ� ��� �迭�� ������ش�.
	int iNoneSelect[25] = {};
	// ���þȵ� ���� ������ ����.
	int iNoneSelectCount = 0;

	while (true) {
		system("cls");

		cout << "===================== Player ====================\n";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << "\n";
		}
		cout << "Bingo Line : " << iBingo << "\n";

		cout << "=====================  A I  ====================\n";

		switch (iAIMode) {
		case AM_EASY:
			cout << "AI MODE : Easy\n";
			break;
		case AM_HARD:
			cout << "AI MODE : HARD\n";
			break;
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
			cout << "\n";
		}

		cout << "AI Bingo Line : " << iAIBingo << "\n";


		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			return 0;
		else if (iInput > 25 || iInput < 1)
			continue;
		
		bool bAcc = true;
		// �ߺ��Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٰ�
		// �ϱ����� true�� ����־���.

		// ��� ���ڸ� ���ʴ�� �˻��Ͽ� �Է��� ���ڿ� ���� ���ڰ�
		// �ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; i++) {
			if (iInput == iNumber[i]) {
				// ���ڸ� ã�Ƴ� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				// bAcc ������ false�� ������ش�.
				bAcc = false;
				iNumber[i] = INT_MAX;
				
				// ���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
				// for���� ����������.
				break;
			}
		}
		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�.
		if (bAcc)
			continue;

		for (int i = 0; i < 25; i++) {
			if (iInput == iAINumber[i]) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}
		// AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI��忡 ���� �޶�����.
		switch (iAIMode) {
			/*
			AI Easy ���� ���� AI�� ���ڸ�� �� *�� �ٲ��� ���� ���� ����� ����
			�� ��� �� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�)
			*/
		case AM_EASY:
			// ���þȵ� ���ڸ���� ������ش�.
			// ���þȵ� ���� ������ ����� ���鶧 ī�������ش�.
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; i++) {
				// ���� ���ڰ� *�� �ƴ� ���
				if (iAINumber[i] != INT_MAX) {
					// *�� �ƴ� ������ ��� iNoneSelectCounrt�� �ε����� Ȱ��
					// �Ѵ�. ���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� ����
					// ���Ѽ� �� ���þȵ� ������ �����ش�.
					// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1��
					// �߰��Ǿ��ٰ� ���ش�.
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					++iNoneSelectCount;
				}
			}

			// for���� ���������� �Ǹ� ���þȵ� ����� ���������
			// ���þȵ� ����� ������ ��������� �ȴ�.
			// ���þȵ� ����� ���� �� ������ �ϳ��� ���ڸ� ���� ����
			// �ε����� �����ϰ� �����ش�.
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;

		case AM_HARD:
			// �ϵ���� ���� ���� �� ������ �ϼ� ���ɼ��� ���� ���� ����
			// ã�Ƽ� �� �ٿ� �ִ� ���� �� �ϳ��� *�� ������ش�.
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			// ���� ���� ���� �� ���� *�� ���� ������ ã�Ƴ���.
			for (int i = 0; i < 5; i++) {
				iStarCount = 0;
				for (int j = 0; j < 5; j++) {
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
					
					// ���� 5�� �̸��̾�� �ϼ����� ���� ���̰� ������ ���帹��
					// ������ ���� ������ ���ƾ� ���� ���� ���� �����̹Ƿ� ������
					// ��ü���ְ� ����� ���� ������ ��ü�Ѵ�
				}
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// ���� enum�� ���� ���ζ����� 0 ~ 4 �� �ǹ̸� �ο��ߴ�.
					iLine = i;
					iSaveCount = iStarCount;
				}
			}
			// ���� ������ ���� ���� ���� ������ ���� ��
			// �ش� �������� ������ ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
			
			for (int i = 0; i < 5; i++) {
				iStarCount = 0;
				for (int j = 0; j < 5; j++) {
					if (iAINumber[j * 5 + i] == INT_MAX)
						++iStarCount;
				}

				if (iStarCount < 5 && iSaveCount < iStarCount) {
					// ���� enum�� ���� ���ζ����� 5 ~ 9 �� �ǹ̸� �ο��ߴ�.
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			// ���� -> ������ �밢�� üũ
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6) {
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			// ������ -> ���� �밢�� üũ
			iStarCount = 0;
			for (int i = 0; i <= 20; i += 4) {
				if (iAINumber[i] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			// ��� ������ ���������Ƿ� iLine�������� ���� ���ɼ��� ���� �� ��ȣ��
			// ����Ǿ��ִ�. �� �ٿ� �ִ� *�� �ƴ� ���� �� �ϳ���
			// �����ϰ� �Ѵ�.

			if (iLine <= LN_H5){
				// �������� ��� iLine�� 0 ~ 4 ������ ���̴�.
				for (int i = 0; i < 5; i++) {
					if (iAINumber[iLine * 5 + i] != INT_MAX) {
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5) {
				// �������� ��� iLine�� ���� 5 ~ 9 ������ ���̴�.
				for (int i = 0; i < 5; i++) {
					if (iAINumber[i * 5 + iLine - 5] != INT_MAX) {
						iInput = iAINumber[i * 5 + iLine - 5];
						break;
					}
				}
			}
			else if (iLine == LN_LT) {
				for (int i = 0; i < 25; i += 6) {
					if (iAINumber[i] != INT_MAX) {
						iInput = iAINumber[i];
						break;
					}
				}
			}
			else if (iLine == LN_RT) {
				for (int i = 0; i <= 20; i += 4) {
					if (iAINumber[i] != INT_MAX) {
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		}
		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		int count = 0;
		for (int i = 0; i < 25; i++) {
			if (iInput == iNumber[i]) {
				iNumber[i] = INT_MAX;
				count++;
			}
			if (iInput == iAINumber[i]) {
				iAINumber[i] = INT_MAX;
				count++;
			}
			if (count == 2) {
				count = 0;
				break;
			}
		}


		// ���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� �� ���� ó������
		// ���� ī��Ʈ�� �� ���̴�. �׷��Ƿ� iBingo ������ 0���� �Ź� 
		// �ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = 0;
		iAIBingo = 0;
		// ����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; i++) {
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; j++) {
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				// ���� �� ������ �����ش�.
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

				if (iAINumber[i * 5 + j] == INT_MAX)
					++iAIStar1;
				if (iAINumber[j * 5 + i] == INT_MAX)
					++iAIStar2;
			}
			// j for���� ���������� ���� ���� ���� ���� �� ������ �����
			// iStar1 ������ ���� �ȴ�. iStar1�� ���� 5�̸� ������
			// ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
			if (iStar1 == 5)
				iBingo++;
			if (iStar2 == 5)
				iBingo++;

			if (iAIStar1 == 5)
				iAIBingo++;
			if (iAIStar2 == 5)
				iAIBingo++;
		}
		// ���� ��� -> ������ �ϴ� �밢�� üũ
		iStar1 = 0, iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			iBingo++;

		for (int i = 0; i < 25; i += 6) {
			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iAIStar1 == 5)
			iAIBingo++;
		
		// ������ ��� -> ���� �ϴ� �밢�� üũ
		iStar1 = 0, iAIStar1 = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			iBingo++;

		for (int i = 4; i <= 20; i += 4) {
			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iAIStar1 == 5)
			iAIBingo++;

		if (iBingo == 5) {
			system("cls");
			cout << "Player Win!\n";
			break;
		}
		else if(iAIBingo == 5) {
			system("cls");
			cout << "AI Win!\n";
			break;
		}
	}
	

	cout << "===================== Player ====================\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (iNumber[i * 5 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << iNumber[i * 5 + j] << "\t";
		}
		cout << "\n";
	}
	cout << "Bingo Line : " << iBingo << "\n";

	cout << "=====================  A I  ====================\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (iAINumber[i * 5 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << iAINumber[i * 5 + j] << "\t";
		}
		cout << "\n";
	}
	cout << "AI Bingo Line : " << iAIBingo << "\n";
	return 0;

}
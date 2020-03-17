#include <iostream>
#include <time.h>

using namespace std;

enum AI_MODE {
	AM_NONE,
	AM_EASY,
	AM_HARD,
	AM_END
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

// 함수는 선언과 정의 부분으로 나눌 수 있다.
void SetNumber(int* pArray);
void Shuffle(int* pArray);
AI_MODE SelectAIMode();
void OutputNumber(int* pArray, int iBingo);
bool ChangeNumber(int* pArray, int iInput);
int SelectAINumber(int* pArray, AI_MODE eAIMode);
int BingoCounting(int* pArray);
int BingoCountingH(int* pArray);
int BingoCountingV(int* pArray);
int BingoCountingLTD(int* pArray);
int BingoCountingRTD(int* pArray);

int main()
{
	int iNumber[25] = {};
	int iAINumber[25] = {};

	srand((unsigned int)time(0));

	// 빙고판을 제작한다.
	SetNumber(iNumber);
	SetNumber(iAINumber);

	// 숫자를 섞어준다.
	Shuffle(iNumber);
	Shuffle(iAINumber);


	int iBingo = 0, iAIBingo = 0;
	
	//AI 난이도를 선택한다.
	AI_MODE eAIMode = SelectAIMode();




	while (true) {
		system("cls");

		cout << "===================== Player ====================\n";
		OutputNumber(iNumber, iBingo);
		cout << "=====================  A I  ====================\n";
		OutputNumber(iAINumber, iAIBingo);

		switch (eAIMode) {
		case AM_EASY:
			cout << "AI MODE : Easy\n";
			break;
		case AM_HARD:
			cout << "AI MODE : HARD\n";
			break;
		}

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			return 0;
		else if (iInput > 25 || iInput < 1)
			continue;

		bool bAcc = ChangeNumber(iNumber, iInput);
	
		if (bAcc)
			continue;

		ChangeNumber(iAINumber, iInput);


		iInput = SelectAINumber(iAINumber, eAIMode);
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAINumber, iInput);

		iBingo = BingoCounting(iNumber);
		iAIBingo = BingoCounting(iAINumber);

		if (iBingo >= 5) {
			system("cls");
			cout << "Player Win!\n";
			break;
		}
		else if (iAIBingo >= 5) {
			system("cls");
			cout << "AI Win!\n";
			break;
		}
	}


	cout << "===================== Player ====================\n";
	OutputNumber(iNumber, iBingo);

	cout << "=====================  A I  ====================\n";
	OutputNumber(iAINumber, iAIBingo);
	return 0;

}

void SetNumber(int* pArray) {
	for (int i = 0; i < 25; i++) {
		pArray[i] = i + 1;
	}
}

void Shuffle(int* pArray) {

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;

		idx1 = rand() % 25;
		idx2 = rand() % 25;

	}
}

AI_MODE SelectAIMode() {
	int eAIMode;

	while (true) {
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << " AI 모드를 선택하세요 : ";
		cin >> eAIMode;

		if (eAIMode >= AM_EASY && eAIMode <= AM_HARD)
			break;
	}

	return (AI_MODE)eAIMode;
}

void OutputNumber(int* pArray, int iBingo) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pArray[i * 5 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << pArray[i * 5 + j] << "\t";
		}
		cout << "\n";
	}
	cout << "Bingo Line : " << iBingo << "\n";
}

bool ChangeNumber(int* pArray, int iInput) {
	for (int i = 0; i < 25; i++) {
		if (iInput == pArray[i]) {
			pArray[i] = INT_MAX;
			return false;
		}
	}
	return true;
}

int SelectAINumber(int* pArray, AI_MODE eAIMode) {

	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	switch (eAIMode) {
	case AM_EASY:
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; i++) {
			if (pArray[i] != INT_MAX) {
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}
		return iNoneSelect[rand() % iNoneSelectCount];
		

	case AM_HARD:
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		for (int i = 0; i < 5; i++) {
			iStarCount = 0;
			for (int j = 0; j < 5; j++) {
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
	}
			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = i;
				iSaveCount = iStarCount;
			}
		}
		for (int i = 0; i < 5; i++) {
			iStarCount = 0;
			for (int j = 0; j < 5; j++) {
				if (pArray[j * 5 + i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount) {
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		iStarCount = 0;
		for (int i = 0; i < 25; i += 6) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}
		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		iStarCount = 0;
		for (int i = 0; i <= 20; i += 4) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}
		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}
		if (iLine <= LN_H5) {
			for (int i = 0; i < 5; i++) {
				if (pArray[iLine * 5 + i] != INT_MAX)
					return pArray[iLine * 5 + i];
				
			}
		}
		else if (iLine <= LN_V5) {
			for (int i = 0; i < 5; i++) {
				if (pArray[i * 5 + iLine - 5] != INT_MAX) 
					return pArray[i * 5 + iLine - 5];
				
			}
		}
		else if (iLine == LN_LT) {
			for (int i = 0; i < 25; i += 6) {
				if (pArray[i] != INT_MAX) 
					return pArray[i];
			}
		}
		else if (iLine == LN_RT) {
			for (int i = 0; i <= 20; i += 4) {
				if (pArray[i] != INT_MAX)
					return pArray[i];
			}
		}
		break;
	}
	return -1;
}

int BingoCounting(int* pArray) {
	int iBingo = 0;
	iBingo = BingoCountingH(pArray) + BingoCountingV(pArray) + BingoCountingLTD(pArray) + BingoCountingRTD(pArray);
	return iBingo;
}
int BingoCountingH(int* pArray) {
	int iStar = 0, iBingo = 0;
	for (int i = 0; i < 5; i++) {
		iStar = 0;
		for (int j = 0; j < 5; j++) {
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar;
		}
		if (iStar == 5)
			iBingo++;
	}
	return iBingo;

}
int BingoCountingV(int* pArray) {
	int iStar = 0, iBingo = 0;
	for (int i = 0; i < 5; i++) {
		iStar = 0;
		for (int j = 0; j < 5; j++) {
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar;
		}
		if (iStar == 5)
			iBingo++;
	}
	return iBingo;
}
int BingoCountingLTD(int* pArray) {
	int iStar = 0;
	for (int i = 0; i < 25; i += 6) {
		if (pArray[i] == INT_MAX)
			++iStar;
	}
	if (iStar == 5)
		return 1;
	return 0;
}
int BingoCountingRTD(int* pArray) {
	int iStar = 0;
	for (int i = 4; i <= 20; i += 4) {
		if (pArray[i] == INT_MAX)
			++iStar;
	}
	if (iStar == 5)
		return 1;
	return 0;
}
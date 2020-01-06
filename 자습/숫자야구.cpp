#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = {};

	// 1 ~ 9 까지 숫자를 설정한다.
	for (int i = 0; i < 9; i++) {
		iNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	
	cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];

	while (true) {
		cout << "1 ~ 9 사이의 숫자 중 숫자 3개를 입력하세요(0: 종료)0 :" ;
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9) {
			cout << "잘못된 숫자를 입력하였습니다." << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] || iInput[1] == iInput[2]) {
			cout << "중복됫 숫자를 입력하였습니다." << endl;
			continue;
		}

		iStrike = iBall = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
						++iStrike;
					else
						++iBall;
					break;
				}
			}
		}
		

		if (iStrike == 3) {
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0)
			cout << "Out" << endl;
		else
			cout << iStrike << " Strike\t" << iBall << " Ball" << endl;
	}
}

#include <iostream>
#include <time.h>

#include <conio.h>
// console input ouput 헤더파일이다. 콘솔창에서 입출력하는 기능들을
// 제공해주는 헤더파일이다.
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; i++) {
		iNumber[i] = i + 1;
	}

	//가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을
	//사용할건데 INT_MAX라는 값을 사용할 것이다. INT_MAX는 이미 정의되어있는 값으로
	//int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX;
	int iStarIndex = 24;

	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다. 즉 인덱스는 0 ~ 23번
	// 인덱스 까지만 섞어준다.
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
		cout << "움직인 횟수 : " << count << "\n";
		for (int i = 0; i < 5; i++) {// i 는 세로줄 의미.
			for (int j = 0; j < 5; j++) {// j 는 가로줄 의미
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
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}
		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료: ";
		char cInput = _getch();
		// _getch() 함수는 문자 1개를 입력받는 함수이다. 이 함수는 Enter을 치지
		// 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
		
		if (cInput == 'q' || cInput == 'Q')
			break;
		
		switch (cInput) {
		case 'w':
		case 'W':
			if(iStarIndex > 4){
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex - 5] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸 위의 인덱스로 만들어준다.
				iStarIndex -= 5;
				count++;
			}
			break;
		case 's':
		case 'S':
			if (iStarIndex < 20) {
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex + 5] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸 위의 인덱스로 만들어준다.
				iStarIndex += 5;
				count++;
			}
			break;

		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0) {
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex - 1] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸 위의 인덱스로 만들어준다.
				iStarIndex -= 1;
				count++;
			}
			break;

		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4) {
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				// 위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다.
				iNumber[iStarIndex + 1] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸 위의 인덱스로 만들어준다.
				iStarIndex += 1;
				count++;
			}
			break;
		}
	}
	
	cout <<"\n게임을 종료합니다." << endl;
	return 0;

}
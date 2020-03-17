#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 파워 아이템
6 : 벽밀기 아이템
7 : 투명 아이템
8 : 웜홀
*/

struct _tagPoint {
	int x;
	int y;
};

//typedef : 타입을 제정의하는 기능이다
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer {
	_tagPoint tPos;
	bool bWallPush;
	bool bPushOnoFF;
	bool bTransparency;
	int iBombPower;
}PLAYER, *PPLAYER;

void SetMaze(char Maze[22][21], PPLAYER pPlayer, PPOINT pStartPos,
	PPOINT pEndPos) {
	
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;
	
	pPlayer->tPos = *pStartPos;

	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111111100000000");
	strcpy_s(Maze[2],  "00100010000111111100");
	strcpy_s(Maze[3],  "01100010000000000100");
	strcpy_s(Maze[4],  "01000011110001111100");
	strcpy_s(Maze[5],  "01000000001111000000");
	strcpy_s(Maze[6],  "01100000001000000000");
	strcpy_s(Maze[7],  "00100000001111111000");
	strcpy_s(Maze[8],  "00001110000000001000");
	strcpy_s(Maze[9],  "01111011111111111000");
	strcpy_s(Maze[10], "01000000000000000000");
	strcpy_s(Maze[11], "01111100111111000000");
	strcpy_s(Maze[12], "00000111100001111110");
	strcpy_s(Maze[13], "01111100000000000010");
	strcpy_s(Maze[14], "01000000001111111110");
	strcpy_s(Maze[15], "01111110011000000000");
	strcpy_s(Maze[16], "00000010010000000000");
	strcpy_s(Maze[17], "01111110011111000000");
	strcpy_s(Maze[18], "01000000000001100000");
	strcpy_s(Maze[19], "11000000000000111113");
	strcpy_s(Maze[20], "00000000000000000000");

}

void Output(char Maze[22][21], PPLAYER pPlayer) {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 21; j++) {

			if (Maze[i][j] == '4')
				cout << "♨";
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "☆";

			else if (Maze[i][j] == '0')
				cout << "■";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "★";
			else if (Maze[i][j] == '3')
				cout << "◎";
			else if (Maze[i][j] == '5')
				cout << "㈜";
			else if (Maze[i][j] == '6')
				cout << "※";
			else if (Maze[i][j] == '7')
				cout << "▷";
		}
		cout << "\n";
	}
	cout << "㈜ = 폭탄 파워 업  ※ = 벽밀기  ▷ = 벽통과\n";
	cout << "폭탄파워 : " << pPlayer->iBombPower << "\n";
	cout << "벽통과 : ";
	if (pPlayer->bTransparency)
		cout << "ON\t";
	else
		cout << "OFF\t";
	cout << "벽밀기 : ";
	if (pPlayer->bWallPush){
		cout << "가능 / ";
		if (pPlayer->bPushOnoFF)
			cout << "ON\n";
		else
			cout << "OFF\n";
	}
	else
		cout << "불가능 / OFF\n";
}

bool AddItem(char cItemType, PPLAYER pPlayer) {

	if (cItemType == '5') {
		if(pPlayer->iBombPower < 5)
			++pPlayer->iBombPower;
		return true;
	}
	else if (cItemType == '6') {
		pPlayer->bWallPush = true;
		pPlayer->bPushOnoFF = true;
		return true;
	}
	else if (cItemType == '7') {
		pPlayer->bTransparency = true;
		return true;
	}
	return false;
}

void MoveUP(char Maze[22][21], PPLAYER pPlayer) {

	if (pPlayer->tPos.y - 1 >= 0) {
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
			--pPlayer->tPos.y;
		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0') {
			// 벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnoFF) {
				// 위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if(pPlayer->tPos.y - 2 >= 0){
					// 위의 위칸이 길이 아닌 경우(벽일 경우)
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0') {
						if (pPlayer->bTransparency) {
							--pPlayer->tPos.y;
						}
					}
					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '1') {
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						// 위칸을 벽에서 길로 바꿔준 후
						Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] = '1';
						// 플레이어를 이동시킨다.
						--pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency) {
					--pPlayer->tPos.y;
				}
			}
			// 벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency) {
				--pPlayer->tPos.y;
			}
		}
		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
		}
	}
}

void MoveDown(char Maze[22][21], PPLAYER pPlayer) {

	if (pPlayer->tPos.y + 1 < 20) {
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0'
			&& Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
			++pPlayer->tPos.y;
		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0') {
			// 벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnoFF) {
				// 위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.y + 2 < 20) {
					// 위의 위칸이 길이 아닌 경우(벽일 경우)
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0') {
						if (pPlayer->bTransparency) {
							++pPlayer->tPos.y;
						}
					}
					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '1') {
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						// 위칸을 벽에서 길로 바꿔준 후
						Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] = '1';
						// 플레이어를 이동시킨다.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency) {
					++pPlayer->tPos.y;
				}
			}
			// 벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency) {
				++pPlayer->tPos.y;
			}
		}
		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;
	}
	if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
		Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveLeft(char Maze[22][21], PPLAYER pPlayer) {

	if (pPlayer->tPos.x - 1 >= 0) {
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0'
			&& Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
			--pPlayer->tPos.x;
		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '0') {
			// 벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnoFF) {
				// 위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x - 2 >= 0) {
					// 위의 위칸이 길이 아닌 경우(벽일 경우)
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0') {
						if (pPlayer->bTransparency) {
							--pPlayer->tPos.x;
						}
					}
					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '1') {
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						// 위칸을 벽에서 길로 바꿔준 후
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '1';
						// 플레이어를 이동시킨다.
						--pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency) {
					--pPlayer->tPos.x;
				}
			}
			// 벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency) {
				--pPlayer->tPos.x;
			}
		}
		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;
	}
	if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
		Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveRight(char Maze[22][21], PPLAYER pPlayer) {

	if (pPlayer->tPos.x + 1 < 20) {
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0'
			&& Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
			++pPlayer->tPos.x;
		// 벽 밀기가 가능하고 바로 윗칸이 벽일 경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0') {
			// 벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnoFF) {
				// 위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x + 2 < 20) {
					// 위의 위칸이 길이 아닌 경우(벽일 경우)
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0') {
						if (pPlayer->bTransparency) {
							++pPlayer->tPos.x;
						}
					}
					// 길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '1') {
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0';
						// 위칸을 벽에서 길로 바꿔준 후
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] = '1';
						// 플레이어를 이동시킨다.
						++pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency) {
					++pPlayer->tPos.x;
				}
			}
			// 벽 밀기가 OFF 상태일 경우
			else if (pPlayer->bTransparency) {
				++pPlayer->tPos.x;
			}
		}
		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;
	}
	if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer)) {
		Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MovePlayer(char Maze[22][21], PPLAYER pPlayer, char cInput) {

	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUP(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;

	default:
		break;
	}
}

// 포인터 변수를 const로 생성사면 가리키는 대상의 값을 변경할 수 없다.
void CreatBomb(char Maze[22][21], const PPLAYER pPlayer,
	PPOINT pBombArr, int *pBombCount) {

	if (*pBombCount == 5)
		return;

	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	for (int i = 0; i < *pBombCount; i++) {
		if (pPlayer->tPos.x == pBombArr[i].x &&
			pPlayer->tPos.y == pBombArr[i].y)
			return;
	}
	pBombArr[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void Fire(char Maze[22][21], PPLAYER pPlayer, PPOINT pBombArr,
	int *pBombCount) {

	for (int i = 0; i < *pBombCount; i++) {
		
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		// 플레이어가 폭탄에 맞은 경우 시작점으로 돌아간다.
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y) {
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}
		for (int j = 1; j <= pPlayer->iBombPower; j++) {
			if (pBombArr[i].y - j >= 0) {
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0'){
					if (rand() % 100 < 20) {

						int iPercent = rand() % 100;

						if(iPercent < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';
						else if (iPercent < 80) 
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';

					}
					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].y + j < 20) {
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0'){
					if (rand() % 100 < 20) {

						int iPercent = rand() % 100;

						if (iPercent < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}
					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x - j >= 0) {
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0'){
					if (rand() % 100 < 20) {

						int iPercent = rand() % 100;

						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';
						else
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
					}
					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x + j < 20) {
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0') {
					if (rand() % 100 < 20) {

						int iPercent = rand() % 100;

						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';
						else
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}
	}

	*pBombCount = 0;
}


int main()
{

	srand((unsigned int)time(0)); 

	// 20 x 20 미로를 만들어준다.
	char strMaze[22][21];
	
	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;

	POINT tBombPos[5];

	// 미로를 설정한다.
	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);
	
	while(true){
		system("cls");
		// 미로를 출력한다.
		Output(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y) {
			cout << "도착했습니다.\n";
			system("pause");
			return 0;
		}
		cout << " t : 폭탄설치 u :  폭탄 터트리기 i : 벽밀기 ON/OFF\n";
		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 :";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 't' || cInput == 'T') {
			CreatBomb(strMaze, &tPlayer, tBombPos, &iBombCount);
		}

		else if (cInput == 'u' || cInput == 'U') {
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);
		}
		else if (cInput == 'i' || cInput == 'I') {
			if (tPlayer.bWallPush)
				tPlayer.bPushOnoFF = !tPlayer.bPushOnoFF;
		}

		MovePlayer(strMaze, &tPlayer, cInput);
	}
	return 0;
}
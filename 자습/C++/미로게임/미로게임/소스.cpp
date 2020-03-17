#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

/*
0 : ��
1 : ��
2 : ������
3 : ������
4 : ��ź
5 : �Ŀ� ������
6 : ���б� ������
7 : ���� ������
8 : ��Ȧ
*/

struct _tagPoint {
	int x;
	int y;
};

//typedef : Ÿ���� �������ϴ� ����̴�
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
				cout << "��";
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "��";

			else if (Maze[i][j] == '0')
				cout << "��";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "��";
			else if (Maze[i][j] == '3')
				cout << "��";
			else if (Maze[i][j] == '5')
				cout << "��";
			else if (Maze[i][j] == '6')
				cout << "��";
			else if (Maze[i][j] == '7')
				cout << "��";
		}
		cout << "\n";
	}
	cout << "�� = ��ź �Ŀ� ��  �� = ���б�  �� = �����\n";
	cout << "��ź�Ŀ� : " << pPlayer->iBombPower << "\n";
	cout << "����� : ";
	if (pPlayer->bTransparency)
		cout << "ON\t";
	else
		cout << "OFF\t";
	cout << "���б� : ";
	if (pPlayer->bWallPush){
		cout << "���� / ";
		if (pPlayer->bPushOnoFF)
			cout << "ON\n";
		else
			cout << "OFF\n";
	}
	else
		cout << "�Ұ��� / OFF\n";
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
		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0') {
			// ���бⰡ ON ������ ���
			if (pPlayer->bPushOnoFF) {
				// ���� ��ĭ�� 0���� ũ�ų� ���� ���� �ε����� �ִٴ� �ǹ�
				if(pPlayer->tPos.y - 2 >= 0){
					// ���� ��ĭ�� ���� �ƴ� ���(���� ���)
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0') {
						if (pPlayer->bTransparency) {
							--pPlayer->tPos.y;
						}
					}
					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '1') {
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						// ��ĭ�� ������ ��� �ٲ��� ��
						Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] = '1';
						// �÷��̾ �̵���Ų��.
						--pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency) {
					--pPlayer->tPos.y;
				}
			}
			// �� �бⰡ OFF ������ ���
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
		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0') {
			// ���бⰡ ON ������ ���
			if (pPlayer->bPushOnoFF) {
				// ���� ��ĭ�� 0���� ũ�ų� ���� ���� �ε����� �ִٴ� �ǹ�
				if (pPlayer->tPos.y + 2 < 20) {
					// ���� ��ĭ�� ���� �ƴ� ���(���� ���)
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0') {
						if (pPlayer->bTransparency) {
							++pPlayer->tPos.y;
						}
					}
					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '1') {
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						// ��ĭ�� ������ ��� �ٲ��� ��
						Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] = '1';
						// �÷��̾ �̵���Ų��.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency) {
					++pPlayer->tPos.y;
				}
			}
			// �� �бⰡ OFF ������ ���
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
		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '0') {
			// ���бⰡ ON ������ ���
			if (pPlayer->bPushOnoFF) {
				// ���� ��ĭ�� 0���� ũ�ų� ���� ���� �ε����� �ִٴ� �ǹ�
				if (pPlayer->tPos.x - 2 >= 0) {
					// ���� ��ĭ�� ���� �ƴ� ���(���� ���)
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0') {
						if (pPlayer->bTransparency) {
							--pPlayer->tPos.x;
						}
					}
					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '1') {
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						// ��ĭ�� ������ ��� �ٲ��� ��
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '1';
						// �÷��̾ �̵���Ų��.
						--pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency) {
					--pPlayer->tPos.x;
				}
			}
			// �� �бⰡ OFF ������ ���
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
		// �� �бⰡ �����ϰ� �ٷ� ��ĭ�� ���� ���
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0') {
			// ���бⰡ ON ������ ���
			if (pPlayer->bPushOnoFF) {
				// ���� ��ĭ�� 0���� ũ�ų� ���� ���� �ε����� �ִٴ� �ǹ�
				if (pPlayer->tPos.x + 2 < 20) {
					// ���� ��ĭ�� ���� �ƴ� ���(���� ���)
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0') {
						if (pPlayer->bTransparency) {
							++pPlayer->tPos.x;
						}
					}
					// ���� ��� ���� �о��.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '1') {
						// ���� ��ĭ�� ������ �ϰ�
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0';
						// ��ĭ�� ������ ��� �ٲ��� ��
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] = '1';
						// �÷��̾ �̵���Ų��.
						++pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency) {
					++pPlayer->tPos.x;
				}
			}
			// �� �бⰡ OFF ������ ���
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

// ������ ������ const�� ������� ����Ű�� ����� ���� ������ �� ����.
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

		// �÷��̾ ��ź�� ���� ��� ���������� ���ư���.
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

	// 20 x 20 �̷θ� ������ش�.
	char strMaze[22][21];
	
	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;

	POINT tBombPos[5];

	// �̷θ� �����Ѵ�.
	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);
	
	while(true){
		system("cls");
		// �̷θ� ����Ѵ�.
		Output(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y) {
			cout << "�����߽��ϴ�.\n";
			system("pause");
			return 0;
		}
		cout << " t : ��ź��ġ u :  ��ź ��Ʈ���� i : ���б� ON/OFF\n";
		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ���� :";
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
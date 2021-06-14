
#include <iostream>
#include <time.h>

using namespace std;

#define	NAME_SIZE	32
#define	ITEM_DESC_LENGTH	512
#define	INVENTORY_MAX		20
#define	STORE_WEAPON_MAX	3
#define	STORE_ARMOR_MAX		3
#define	LEVEL_MAX			10


enum class MAIN_MENU
{
	NONE,
	MAP,
	STORE,
	INVENTORY,
	EXIT
};

enum class MAP_TYPE
{
	NONE,
	EASY,
	NORMAL,
	HARD,
	BACK
};

enum class JOB
{
	NONE,
	KNIGHT,
	ARCHER,
	WIZARD,
	END
};

enum class BATTLE
{
	NONE,
	ATTACK,
	BACK
};

enum class ITEM_TYPE
{
	NONE,
	WEAPON,
	ARMOR,
	BACK
};

enum class STORE_MENU
{
	NONE,
	WEAPON,
	ARMOR,
	BACK
};

enum class EQUIP
{
	WEAPON,
	ARMOR,
	MAX
};


struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE	eType;
	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem	tItem[INVENTORY_MAX];
	int			iItemCount;
	int			iGold;
};

struct _tagPlayer
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
	_tagItem	tEquip[int(EQUIP::MAX)];
	bool		bEquip[int(EQUIP::MAX)];
	_tagInventory	tInventory;
};

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

struct _tagLevelUpStatus
{
	int	iAttackMin;
	int	iAttackMax;
	int	iArmorMin;
	int	iArmorMax;
	int	iHPMin;
	int	iHPMax;
	int	iMPMin;
	int	iMPMax;
};

const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };
_tagLevelUpStatus g_tLvUpTable[int(JOB::END) - 1] = {};



// 숫자를 입력받는 함수. 오류가 발생한 경우 INT_MAX 리턴
int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		// 오류가 발생한 경우 INT_MAX 리턴
		return INT_MAX;

	}
	return iInput;
}

// 메인메뉴를 화면에 출력한 후 입력받은 메뉴를 반환한다.
// 입력 오류 또는 잘못된 번호를 받은 경우 MM_NONE를 반환한다.
MAIN_MENU OutputMainMenu() {
	system("cls");
	cout << "*************************** 로비 ***************************\n";
	cout << "1. 맵\n";
	cout << "2. 상점\n";
	cout << "3. 가방\n";
	cout << "4. 종료\n";
	cout << "메뉴를 선택하세요 : ";
	MAIN_MENU iMenu = MAIN_MENU(InputInt());

	if (int(iMenu) == INT_MAX || iMenu <= MAIN_MENU::NONE || iMenu > MAIN_MENU::EXIT)
		return MAIN_MENU::NONE;

	return iMenu;
}

MAP_TYPE OutputMapMenu() {
	system("cls");
	cout << "*************************** 맵 ***************************\n";
	cout << "1. 쉬움\n";
	cout << "2. 보통\n";
	cout << "3. 어려움\n";
	cout << "4. 뒤로가기\n";
	cout << "맵을 선택하세요 : ";
	MAP_TYPE iMenu = MAP_TYPE(InputInt());

	if (int(iMenu) == INT_MAX || iMenu <= MAP_TYPE::NONE || iMenu > MAP_TYPE::BACK)
		return MAP_TYPE::NONE;

	return iMenu;
}

void OutputBattleTag(MAP_TYPE iMenu) {
	switch (iMenu)
	{
	case MAP_TYPE::EASY:
		cout << "*************************** 쉬움 ***************************\n" ;
		break;
	case MAP_TYPE::NORMAL:
		cout << "*************************** 보통 ***************************\n";
		break;
	case MAP_TYPE::HARD:
		cout << "*************************** 어려움 ***************************\n";
		break;
	}
}

void OutputPlayer(_tagPlayer* pPlayer) {
	cout << "================== Player ==================\n";
	cout << "이름 : " << pPlayer->strName << "\t직업 : " <<
		pPlayer->strJobName << '\n';
	cout << "레벨 : " << pPlayer->iLevel << "\t경험치 : " <<
		pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << '\n';

	// 무기를 장착하고 있을 경우 공격력에 무기공격력을 추가하여 출력한다.
	if (pPlayer->bEquip[int(EQUIP::WEAPON)] == true)
	{
		cout << "공격력 : " << pPlayer->iAttackMin << " + " <<
			pPlayer->tEquip[int(EQUIP::WEAPON)].iMin << " - " <<
			pPlayer->iAttackMax << " + " << pPlayer->tEquip[int(EQUIP::WEAPON)].iMax;
	}

	else
	{
		cout << "공격력 : " << pPlayer->iAttackMin << " - " <<
			pPlayer->iAttackMax;
	}

	// 방어구를 장착하고 있을 경우 방어력에 방어구 방어력을 추가하여 출력한다.
	if (pPlayer->bEquip[int(EQUIP::ARMOR)] == true)
	{
		cout << "\t방어력 : " << pPlayer->iArmorMin << " + " <<
			pPlayer->tEquip[int(EQUIP::ARMOR)].iMin << " - " <<
			pPlayer->iArmorMax << " + " << pPlayer->tEquip[int(EQUIP::ARMOR)].iMax << '\n';
	}
	else
	{
		cout << "\t방어력 : " << pPlayer->iArmorMin << " - " <<
			pPlayer->iArmorMax << '\n';
	}

	cout << "체력 : " << pPlayer->iHP << " / " << pPlayer->iHPMax <<
		"\t마나 : " << pPlayer->iMP << " / " << pPlayer->iMPMax << '\n';

	if (pPlayer->bEquip[int(EQUIP::WEAPON)])
		cout << "장착무기 : " << pPlayer->tEquip[int(EQUIP::WEAPON)].strName;

	else
		cout << "장착무기 : 없음";

	if (pPlayer->bEquip[int(EQUIP::ARMOR)])
		cout << "\t장착방어구 : " << pPlayer->tEquip[int(EQUIP::ARMOR)].strName << '\n';

	else
		cout << "\t장착방어구 : 없음\n";

	cout << "보유골드 : " << pPlayer->tInventory.iGold << " Gold" << "\n\n";
}

void OutputMonster(_tagMonster *pMonster) {
	// 몬스터 정보 출력
	cout << "================== Monster ==================\n";
	cout << "이름 : " << pMonster->strName << "\t레벨 : " <<
		pMonster->iLevel << "\n";
	cout << "공격력 : " << pMonster->iAttackMin << " - " <<
		pMonster->iAttackMax << "\t방어력 : " << pMonster->iArmorMin <<
		" - " << pMonster->iArmorMax << "\n";
	cout << "체력 : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t마나 : " << pMonster->iMP << " / " << pMonster->iMPMax << "\n";
	cout << "획득경험치 : " << pMonster->iExp << "\t획득골드 : " <<
		pMonster->iGoldMin << " - " << pMonster->iGoldMax << "\n\n";
}

BATTLE OutputBattleMenu() {
	cout << "1. 공격\n";
	cout << "2. 도망가기\n";
	cout << "메뉴를 선택하세요 : ";
	BATTLE iMenu = BATTLE(InputInt());
	
	if (int(iMenu) == INT_MAX || iMenu <= BATTLE::NONE || iMenu > BATTLE::BACK)
		return BATTLE::NONE;

	return iMenu;
	
}
void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster) {

	int	iAttackMin = pPlayer->iAttackMin;
	int	iAttackMax = pPlayer->iAttackMax;

	// 무기를 장착하고 있을 경우 무기와 Min, Max를 더해준다.
	if (pPlayer->bEquip[int(EQUIP::WEAPON)]){
		iAttackMin += pPlayer->tEquip[int(EQUIP::WEAPON)].iMin;
		iAttackMax += pPlayer->tEquip[int(EQUIP::WEAPON)].iMax;
	}

	int	iAttack = rand() % (iAttackMax - iAttackMin + 1) +
		iAttackMin;
	int	iArmor = rand() % (pMonster->iArmorMax - pMonster->iArmorMin + 1) +
		pMonster->iArmorMin;

	int	iDamage = iAttack - iArmor;
	iDamage = iDamage < 1 ? 1 : iDamage;

	pMonster->iHP -= iDamage;

	cout << pPlayer->strName << " 가 " << pMonster->strName <<
		"에게 " << iDamage << " 피해를 입혔습니다.\n";

	// 몬스터가 죽었을 경우를 처리한다.
	if (pMonster->iHP <= 0){
		cout << pMonster->strName << " 몬스터가 사망하였습니다.\n";

		pPlayer->iExp += pMonster->iExp;
		int	iGold = (rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) +
			pMonster->iGoldMin);
		pPlayer->tInventory.iGold += iGold;

		cout << pMonster->iExp << " 경험치를 획득하였습니다.\n";
		cout << iGold << " Gold를 획득하였습니다.\n";

		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		// 레벨업을 했는지 체크해본다.
		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1])
		{
			// 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
			pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];

			// 레벨을 증가시킨다.
			++pPlayer->iLevel;

			cout << "레벨업 하였습니다.\n";

			// 능력치를 상승시킨다.
			// 직업 인덱스를 구한다.
			int	iJobIndex =  int(pPlayer->eJob) - 1;
			int	iHPUp = rand() % (g_tLvUpTable[iJobIndex].iHPMax - g_tLvUpTable[iJobIndex].iHPMin + 1) +
				g_tLvUpTable[iJobIndex].iHPMin;
			int	iMPUp = rand() % (g_tLvUpTable[iJobIndex].iMPMax - g_tLvUpTable[iJobIndex].iMPMin + 1) +
				g_tLvUpTable[iJobIndex].iMPMin;

			pPlayer->iAttackMin += g_tLvUpTable[iJobIndex].iAttackMin;
			pPlayer->iAttackMax += g_tLvUpTable[iJobIndex].iAttackMax;
			pPlayer->iArmorMin += g_tLvUpTable[iJobIndex].iArmorMin;
			pPlayer->iArmorMax += g_tLvUpTable[iJobIndex].iArmorMax;

			pPlayer->iHPMax += iHPUp;
			pPlayer->iMPMax += iMPUp;

			// 체력과 마나를 회복시킨다.
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}
		return;
	}

	// 몬스터가 살아있다면 플레이어를 공격한다.
	iAttack = rand() % (pMonster->iAttackMax - pMonster->iAttackMin + 1) +
		pMonster->iAttackMin;

	int	iArmorMin = pPlayer->iArmorMin;
	int	iArmorMax = pPlayer->iArmorMax;

	if (pPlayer->bEquip[int(EQUIP::ARMOR)])
	{
		iArmorMin += pPlayer->tEquip[int(EQUIP::ARMOR)].iMin;
		iArmorMax += pPlayer->tEquip[int(EQUIP::ARMOR)].iMax;
	}

	iArmor = rand() % (iArmorMax - iArmorMin + 1) +
		iArmorMin;

	iDamage = iAttack - iArmor;
	// 삼항연산자 : 조건식 ? true일때값 : false일때값;
	//if (iDamage < 1)
	//	iDamage = 1;
	iDamage = iDamage < 1 ? 1 : iDamage;

	// 플레이어의 HP를 감소시킨다.
	pPlayer->iHP -= iDamage;

	cout << pMonster->strName << " 가 " << pPlayer->strName <<
		"에게 " << iDamage << " 피해를 입혔습니다.\n";

	// 플레이어가 죽었을 경우
	if (pPlayer->iHP <= 0)
	{
		cout << pPlayer->strName << " 플레이어가 사망하였습니다.\n";

		int	iExp = pPlayer->iExp * 0.1f;
		int	iGold = pPlayer->tInventory.iGold * 0.1f;

		pPlayer->iExp -= iExp;
		pPlayer->tInventory.iGold -= iGold;

		cout << iExp << " 경험치를 잃었습니다.\n";
		cout << iGold << " Gold를 잃었습니다.\n";

		// 플레이어의 HP와 MP를 회복한다.
		pPlayer->iHP = pPlayer->iHPMax;
		pPlayer->iMP = pPlayer->iMPMax;
	}
}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, MAP_TYPE iMenu) {

	_tagMonster tMonster = pMonsterArr[int(iMenu) - 1];

	while (true) {
		system("cls");
		OutputBattleTag(iMenu);

		// 플레이어 출력
		OutputPlayer(pPlayer);
		OutputMonster(&tMonster);

		switch (OutputBattleMenu())
		{
		case BATTLE::ATTACK:
			Battle(pPlayer, &tMonster);
			system("pause");
			break;
		case BATTLE::BACK:
			return;
		}
	}
}

// Map 관련 동작 처리
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr) {
	bool bLoop = true;
	while (bLoop) {
		MAP_TYPE iMenu = OutputMapMenu();

		if (iMenu == MAP_TYPE::BACK)
			return;

		RunBattle(pPlayer, pMonsterArr, iMenu);
	}

}

JOB SelectJob() {
	JOB	iJob = JOB::NONE;
	while (iJob == JOB::NONE)
	{
		system("cls");
		cout << "1. 기사\n";
		cout << "2. 궁수\n";
		cout << "3. 마법사\n";
		cout << "직업을 선택하세요 : ";
		iJob = JOB(InputInt());

		if (iJob <= JOB::NONE || iJob >= JOB::END)
			iJob = JOB::NONE;
	}
	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer) {

	// 플레이어 이름을 입력받는다.
	cout << "이름 : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);
	
	pPlayer->eJob = SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob)
	{
	case JOB::KNIGHT:
		strcpy_s(pPlayer->strJobName, "기사");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMax = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMP = 100;
		pPlayer->iMPMax = 100;
		break;
	case JOB::ARCHER:
		strcpy_s(pPlayer->strJobName, "궁수");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 15;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMP = 200;
		pPlayer->iMPMax = 200;
		break;
	case JOB::WIZARD:
		strcpy_s(pPlayer->strJobName, "마법사");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMax = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMP = 300;
		pPlayer->iMPMax = 300;
		break;
	}
}

_tagMonster CreatMonster(const char *pName, int iAttackMin,
	int iAttackMax, int iArmorMin, int iArmorMax, int iHP,
	int iMP, int iLevel, int iExp, int iGoldMin, int iGoldMax) {

	_tagMonster tMonster = {};

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = iHP;
	tMonster.iHPMax = iHP;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;

	return tMonster;
}

void SetMonster(_tagMonster* pMonsterArr) {
	pMonsterArr[0] = CreatMonster("고블린", 20, 30, 2, 5,
		100, 10, 1, 1000, 500, 1500);

	pMonsterArr[1] = CreatMonster("트롤", 80, 130, 60, 90,
		2000, 100, 5, 7000, 6000, 8000);

	pMonsterArr[2] = CreatMonster("드래곤", 250, 500, 200, 400,
		30000, 20000, 10, 30000, 20000, 50000);
}

_tagLevelUpStatus CreatLvUpStatus(int iAttackMin, int iAttackMax,
	int iArmorMin, int iArmorMax, int iHPMin, int iHPMax,
	int iMPMin, int iMPMax) {

	_tagLevelUpStatus tStatus = {};

	tStatus.iAttackMin = iAttackMin;
	tStatus.iAttackMax = iAttackMax;
	tStatus.iArmorMin = iArmorMin;
	tStatus.iArmorMax = iArmorMax;
	tStatus.iHPMin = iHPMin;
	tStatus.iHPMax = iHPMax;
	tStatus.iMPMin = iMPMin;
	tStatus.iMPMax = iMPMax;

	return tStatus;
}

void SetLvUpTable() {
	g_tLvUpTable[int(JOB::KNIGHT) - 1] = CreatLvUpStatus(4, 10, 8, 16, 50, 100, 10, 20);
	g_tLvUpTable[int(JOB::ARCHER) - 1] = CreatLvUpStatus(10, 15, 5, 10, 30, 60, 30, 50);
	g_tLvUpTable[int(JOB::WIZARD) - 1] = CreatLvUpStatus(15, 20, 3, 7, 20, 40, 50, 100);
}



_tagItem CreatItem(const char *pName, ITEM_TYPE eType, int iMin,
	int iMax, int iPrice, int iSell, const char *pDesc) {

	_tagItem tItem = {};

	strcpy_s(tItem.strName, pName);
	strcpy_s(tItem.strDesc, pDesc);

	tItem.eType = eType;

	switch (eType)
	{
	case ITEM_TYPE::WEAPON:
		strcpy_s(tItem.strTypeName, "무기");
		break;
	case ITEM_TYPE::ARMOR:
		strcpy_s(tItem.strTypeName, "방어구");
		break;
	}
	
	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;

	return tItem;
}

void SetItem(_tagItem* pWeapon, _tagItem *pArmor) {
	// ================ 무기정보 설정 =================
	pWeapon[0] = CreatItem("목검", ITEM_TYPE::WEAPON, 5, 10,
		1000, 500, "나무로 만든 칼");
	pWeapon[1] = CreatItem("장궁", ITEM_TYPE::WEAPON, 20, 40,
		7000, 3500, "나무로 만든 활");
	pWeapon[2] = CreatItem("지팡이", ITEM_TYPE::WEAPON, 90, 150,
		30000, 15000, "나무로 만든 지팡이");

	// ================ 방어구정보 설정 =================
	pArmor[0] = CreatItem("천갑옷", ITEM_TYPE::ARMOR, 2, 5,
		1000, 500, "천으로 만든 갑옷");
	pArmor[1] = CreatItem("가죽갑옷", ITEM_TYPE::ARMOR, 10, 20,
		7000, 3500, "가죽으로 만든 갑옷");
	pArmor[2] = CreatItem("풀플레이트아머", ITEM_TYPE::ARMOR, 70, 90,
		30000, 15000, "강철로 만든 판금갑옷");
}

STORE_MENU OutputStoreMenu() {
	system("cls");
	cout << "*************************** 상점 ***************************\n";
	cout << "1. 무기상점\n";
	cout << "2. 방어구상점\n";
	cout << "3. 뒤로가기\n";
	cout << "상점을 선택하세요 : ";
	STORE_MENU iMenu = STORE_MENU(InputInt());

	if (iMenu <= STORE_MENU::NONE || iMenu > STORE_MENU::BACK)
		iMenu = STORE_MENU::NONE;

	return iMenu;
}

int OutputStoreItemList(_tagInventory* pInventory,
	_tagItem* pStore, int iItemCount) {
	for (int i = 0; i < iItemCount; ++i)
	{
		cout << i + 1 << ". 이름 : " << pStore[i].strName <<
			"\t종류 : " << pStore[i].strTypeName << '\n';
		if(strcmp(pStore[i].strTypeName, "무기") == 0){
			cout << "공격력 : " << pStore[i].iMin << " - " <<
			pStore[i].iMax << '\n';
		}
		else {
			cout << "방어력 : " << pStore[i].iMin << " - " <<
				pStore[i].iMax << '\n';
		}

		cout << "판매가격 : " << pStore[i].iPrice <<
			"\t구매가격 : " << pStore[i].iSell << '\n';
		cout << "설명 : " << pStore[i].strDesc << "\n";
	}

	cout << iItemCount + 1 << ". 뒤로가기\n";
	cout << "보유금액 : " << pInventory->iGold << " Gold\n";
	cout << "남은공간 : " << INVENTORY_MAX - pInventory->iItemCount << '\n';
	cout << "구입할 아이템을 선택하세요 : ";
	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > iItemCount + 1)
		return INT_MAX;
	return iMenu;
}

void BuyItem(_tagInventory* pInventory, _tagItem* pStore,
	int iItemCount, STORE_MENU StoreType) {
	
	while (true) {
		system("cls");

		switch (StoreType) {
		case STORE_MENU::WEAPON:
			cout << "*************************** 무기상점 ***************************\n";
			break;
		case STORE_MENU::ARMOR:
			cout << "*************************** 방어구상점 ***************************\n";
			break;
		}
		int iInput = OutputStoreItemList(pInventory, pStore, iItemCount);

		if (iInput == INT_MAX) {
			cout << "잘못 입력하였습니다.\n";
			system("pause");
			continue;
		}
		else if (iInput == iItemCount + 1)
			break;

		int	iIndex = iInput - 1;

		// 인벤토리가 꽉 찼는지 검사한다.
		if (pInventory->iItemCount == INVENTORY_MAX){
			cout << "가방이 꽉 찼습니다.\n";
			system("pause");
			continue;
		}

		// 돈이 부족할 경우
		else if (pInventory->iGold < pStore[iIndex].iPrice){
			cout << "보유금액이 부족합니다.\n";
			system("pause");
			continue;
		}

		// 처음에 iItemCount는 하나도 추가되어있지 않기 때문에 0으로 초기화
		// 되어 있으므로 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고
		// 카운트가 1이 된다. 다음번에 추가할때는 1번 인덱스에 추가하게된다.
		pInventory->tItem[pInventory->iItemCount] =
			pStore[iIndex];
		++pInventory->iItemCount;

		// 골드를 차감한다.
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << pStore[iIndex].strName << " 아이템을 구매하였습니다.\n";
		system("pause");
	}
}

void RunStore(_tagInventory* pInventory, _tagItem *pWeapon,
	_tagItem *pArmor) {
	
	while (true) {
		switch (OutputStoreMenu()) {
		case STORE_MENU::WEAPON:
			BuyItem(pInventory, pWeapon, STORE_WEAPON_MAX, STORE_MENU::WEAPON);
			break;
		case STORE_MENU::ARMOR:
			BuyItem(pInventory, pArmor, STORE_ARMOR_MAX, STORE_MENU::ARMOR);
			break;
		case STORE_MENU::BACK:
			return;
		}
	}
}

int OutputInventory(_tagPlayer *pPlayer) {
	system("cls");
	cout << "*************************** 가방 ***************************\n";
	OutputPlayer(pPlayer);

	for (int i = 0; i < pPlayer->tInventory.iItemCount; ++i)
	{
		cout << i + 1 << ". 이름 : " << pPlayer->tInventory.tItem[i].strName <<
			"\t종류 : " << pPlayer->tInventory.tItem[i].strTypeName << '\n';

		if (strcmp(pPlayer->tInventory.tItem[i].strTypeName, "무기") == 0) {
			cout << "공격력 : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
				pPlayer->tInventory.tItem[i].iMax << '\n';
		}
		else {
			cout << "방어력 : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
				pPlayer->tInventory.tItem[i].iMax << '\n';
		}
		cout << "공격력 : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
			pPlayer->tInventory.tItem[i].iMax << '\n';
		cout << "판매가격 : " << pPlayer->tInventory.tItem[i].iPrice <<
			"\t구매가격 : " << pPlayer->tInventory.tItem[i].iSell << '\n';
		cout << "설명 : " << pPlayer->tInventory.tItem[i].strDesc << "\n\n";
	}

	cout << pPlayer->tInventory.iItemCount + 1 << ". 뒤로가기\n";
	cout << "장착할 아이템을 선택하세요 : ";
	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > pPlayer->tInventory.iItemCount + 1)
		return INT_MAX;
	return iMenu;
}

EQUIP ComputeEquipType(ITEM_TYPE eType) {
	EQUIP eq;

	switch (eType)
	{
	case ITEM_TYPE::WEAPON:
		eq = EQUIP::WEAPON;
		break;
	case ITEM_TYPE::ARMOR:
		eq = EQUIP::ARMOR;
		break;
	}
	return eq;
}

void RunInventory(_tagPlayer *pPlayer) {
	while (true) {
		int iInput = OutputInventory(pPlayer);

		if (iInput == INT_MAX){
			cout << "잘못 선택하였습니다.\n";
			system("pause");
			continue;
		}

		else if (iInput == pPlayer->tInventory.iItemCount + 1)
			break;

		// 아이템 인덱스를 구해준다.
		int	idx = iInput - 1;

		// 제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를
		// 결정하게 한다.
		EQUIP eq = ComputeEquipType(pPlayer->tInventory.tItem[idx].eType);

		// 아이템이 장착되어 있을 경우 장착되어있는 아이템과 장착할 아이템을
		// 교체해 주어야 한다. Swap 알고리즘을 활용한다.
		if (pPlayer->bEquip[int(eq)] == true)
		{
			_tagItem tSwap = pPlayer->tEquip[int(eq)];
			pPlayer->tEquip[int(eq)] = pPlayer->tInventory.tItem[idx];
			pPlayer->tInventory.tItem[idx] = tSwap;
		}

		// 장착되어있지 않을 경우 인벤토리 아이템을 장착창으로 옮기고
		// 인벤토리는 1칸 비워지게 된다.
		else
		{
			pPlayer->tEquip[int(eq)] = pPlayer->tInventory.tItem[idx];

			for (int i = idx; i < pPlayer->tInventory.iItemCount - 1; ++i)
			{
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}

			--pPlayer->tInventory.iItemCount;

			// 장착을 했기 때문에 true로 만들어준다.
			pPlayer->bEquip[int(eq)] = true;
		}

		cout <<pPlayer->tEquip[int(eq)].strName << " 아이템을 장착하였습니다.\n" ;

		system("pause");
	}

}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	srand((unsigned int)time(0));
	
	// 플레이어의 정보를 담을 구조체를 선언한다
	_tagPlayer	tPlayer = {};

	// 플레이어 정보를 정의한다.
	SetPlayer(&tPlayer);

	// 몬스터를 생성한다.
	_tagMonster	tMonsterArr[int(MAP_TYPE::BACK) - 1] = {};
	SetMonster(tMonsterArr);

	// 레벨업시 상승 스테이터스 표를 생성한다.
	SetLvUpTable();

	// 상점에서 판매할 아이템 목록을 생성한다.
	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};
	SetItem(tStoreWeapon, tStoreArmor);
	bool bLoop = true;

	while (bLoop) {
		switch (MAIN_MENU(OutputMainMenu()))
		{
		case MAIN_MENU::MAP:
			RunMap(&tPlayer, tMonsterArr);	// 맵 관련 루프함수
			break;
		case MAIN_MENU::STORE:
			RunStore(&tPlayer.tInventory, tStoreWeapon, tStoreArmor);
			break;
		case MAIN_MENU::INVENTORY:
			RunInventory(&tPlayer);
			break;
		case MAIN_MENU::EXIT:
			bLoop = false;
			break;

		default:
			break;
		}
	}

	return 0;
}
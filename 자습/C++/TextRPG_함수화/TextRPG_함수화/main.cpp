
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



// ���ڸ� �Է¹޴� �Լ�. ������ �߻��� ��� INT_MAX ����
int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		// ������ �߻��� ��� INT_MAX ����
		return INT_MAX;

	}
	return iInput;
}

// ���θ޴��� ȭ�鿡 ����� �� �Է¹��� �޴��� ��ȯ�Ѵ�.
// �Է� ���� �Ǵ� �߸��� ��ȣ�� ���� ��� MM_NONE�� ��ȯ�Ѵ�.
MAIN_MENU OutputMainMenu() {
	system("cls");
	cout << "*************************** �κ� ***************************\n";
	cout << "1. ��\n";
	cout << "2. ����\n";
	cout << "3. ����\n";
	cout << "4. ����\n";
	cout << "�޴��� �����ϼ��� : ";
	MAIN_MENU iMenu = MAIN_MENU(InputInt());

	if (int(iMenu) == INT_MAX || iMenu <= MAIN_MENU::NONE || iMenu > MAIN_MENU::EXIT)
		return MAIN_MENU::NONE;

	return iMenu;
}

MAP_TYPE OutputMapMenu() {
	system("cls");
	cout << "*************************** �� ***************************\n";
	cout << "1. ����\n";
	cout << "2. ����\n";
	cout << "3. �����\n";
	cout << "4. �ڷΰ���\n";
	cout << "���� �����ϼ��� : ";
	MAP_TYPE iMenu = MAP_TYPE(InputInt());

	if (int(iMenu) == INT_MAX || iMenu <= MAP_TYPE::NONE || iMenu > MAP_TYPE::BACK)
		return MAP_TYPE::NONE;

	return iMenu;
}

void OutputBattleTag(MAP_TYPE iMenu) {
	switch (iMenu)
	{
	case MAP_TYPE::EASY:
		cout << "*************************** ���� ***************************\n" ;
		break;
	case MAP_TYPE::NORMAL:
		cout << "*************************** ���� ***************************\n";
		break;
	case MAP_TYPE::HARD:
		cout << "*************************** ����� ***************************\n";
		break;
	}
}

void OutputPlayer(_tagPlayer* pPlayer) {
	cout << "================== Player ==================\n";
	cout << "�̸� : " << pPlayer->strName << "\t���� : " <<
		pPlayer->strJobName << '\n';
	cout << "���� : " << pPlayer->iLevel << "\t����ġ : " <<
		pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << '\n';

	// ���⸦ �����ϰ� ���� ��� ���ݷ¿� ������ݷ��� �߰��Ͽ� ����Ѵ�.
	if (pPlayer->bEquip[int(EQUIP::WEAPON)] == true)
	{
		cout << "���ݷ� : " << pPlayer->iAttackMin << " + " <<
			pPlayer->tEquip[int(EQUIP::WEAPON)].iMin << " - " <<
			pPlayer->iAttackMax << " + " << pPlayer->tEquip[int(EQUIP::WEAPON)].iMax;
	}

	else
	{
		cout << "���ݷ� : " << pPlayer->iAttackMin << " - " <<
			pPlayer->iAttackMax;
	}

	// ���� �����ϰ� ���� ��� ���¿� �� ������ �߰��Ͽ� ����Ѵ�.
	if (pPlayer->bEquip[int(EQUIP::ARMOR)] == true)
	{
		cout << "\t���� : " << pPlayer->iArmorMin << " + " <<
			pPlayer->tEquip[int(EQUIP::ARMOR)].iMin << " - " <<
			pPlayer->iArmorMax << " + " << pPlayer->tEquip[int(EQUIP::ARMOR)].iMax << '\n';
	}
	else
	{
		cout << "\t���� : " << pPlayer->iArmorMin << " - " <<
			pPlayer->iArmorMax << '\n';
	}

	cout << "ü�� : " << pPlayer->iHP << " / " << pPlayer->iHPMax <<
		"\t���� : " << pPlayer->iMP << " / " << pPlayer->iMPMax << '\n';

	if (pPlayer->bEquip[int(EQUIP::WEAPON)])
		cout << "�������� : " << pPlayer->tEquip[int(EQUIP::WEAPON)].strName;

	else
		cout << "�������� : ����";

	if (pPlayer->bEquip[int(EQUIP::ARMOR)])
		cout << "\t������ : " << pPlayer->tEquip[int(EQUIP::ARMOR)].strName << '\n';

	else
		cout << "\t������ : ����\n";

	cout << "������� : " << pPlayer->tInventory.iGold << " Gold" << "\n\n";
}

void OutputMonster(_tagMonster *pMonster) {
	// ���� ���� ���
	cout << "================== Monster ==================\n";
	cout << "�̸� : " << pMonster->strName << "\t���� : " <<
		pMonster->iLevel << "\n";
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " <<
		pMonster->iAttackMax << "\t���� : " << pMonster->iArmorMin <<
		" - " << pMonster->iArmorMax << "\n";
	cout << "ü�� : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t���� : " << pMonster->iMP << " / " << pMonster->iMPMax << "\n";
	cout << "ȹ�����ġ : " << pMonster->iExp << "\tȹ���� : " <<
		pMonster->iGoldMin << " - " << pMonster->iGoldMax << "\n\n";
}

BATTLE OutputBattleMenu() {
	cout << "1. ����\n";
	cout << "2. ��������\n";
	cout << "�޴��� �����ϼ��� : ";
	BATTLE iMenu = BATTLE(InputInt());
	
	if (int(iMenu) == INT_MAX || iMenu <= BATTLE::NONE || iMenu > BATTLE::BACK)
		return BATTLE::NONE;

	return iMenu;
	
}
void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster) {

	int	iAttackMin = pPlayer->iAttackMin;
	int	iAttackMax = pPlayer->iAttackMax;

	// ���⸦ �����ϰ� ���� ��� ����� Min, Max�� �����ش�.
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

	cout << pPlayer->strName << " �� " << pMonster->strName <<
		"���� " << iDamage << " ���ظ� �������ϴ�.\n";

	// ���Ͱ� �׾��� ��츦 ó���Ѵ�.
	if (pMonster->iHP <= 0){
		cout << pMonster->strName << " ���Ͱ� ����Ͽ����ϴ�.\n";

		pPlayer->iExp += pMonster->iExp;
		int	iGold = (rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) +
			pMonster->iGoldMin);
		pPlayer->tInventory.iGold += iGold;

		cout << pMonster->iExp << " ����ġ�� ȹ���Ͽ����ϴ�.\n";
		cout << iGold << " Gold�� ȹ���Ͽ����ϴ�.\n";

		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		// �������� �ߴ��� üũ�غ���.
		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1])
		{
			// �÷��̾� ����ġ�� �������� �ʿ��� ����ġ��ŭ �����Ѵ�.
			pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];

			// ������ ������Ų��.
			++pPlayer->iLevel;

			cout << "������ �Ͽ����ϴ�.\n";

			// �ɷ�ġ�� ��½�Ų��.
			// ���� �ε����� ���Ѵ�.
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

			// ü�°� ������ ȸ����Ų��.
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}
		return;
	}

	// ���Ͱ� ����ִٸ� �÷��̾ �����Ѵ�.
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
	// ���׿����� : ���ǽ� ? true�϶��� : false�϶���;
	//if (iDamage < 1)
	//	iDamage = 1;
	iDamage = iDamage < 1 ? 1 : iDamage;

	// �÷��̾��� HP�� ���ҽ�Ų��.
	pPlayer->iHP -= iDamage;

	cout << pMonster->strName << " �� " << pPlayer->strName <<
		"���� " << iDamage << " ���ظ� �������ϴ�.\n";

	// �÷��̾ �׾��� ���
	if (pPlayer->iHP <= 0)
	{
		cout << pPlayer->strName << " �÷��̾ ����Ͽ����ϴ�.\n";

		int	iExp = pPlayer->iExp * 0.1f;
		int	iGold = pPlayer->tInventory.iGold * 0.1f;

		pPlayer->iExp -= iExp;
		pPlayer->tInventory.iGold -= iGold;

		cout << iExp << " ����ġ�� �Ҿ����ϴ�.\n";
		cout << iGold << " Gold�� �Ҿ����ϴ�.\n";

		// �÷��̾��� HP�� MP�� ȸ���Ѵ�.
		pPlayer->iHP = pPlayer->iHPMax;
		pPlayer->iMP = pPlayer->iMPMax;
	}
}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, MAP_TYPE iMenu) {

	_tagMonster tMonster = pMonsterArr[int(iMenu) - 1];

	while (true) {
		system("cls");
		OutputBattleTag(iMenu);

		// �÷��̾� ���
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

// Map ���� ���� ó��
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
		cout << "1. ���\n";
		cout << "2. �ü�\n";
		cout << "3. ������\n";
		cout << "������ �����ϼ��� : ";
		iJob = JOB(InputInt());

		if (iJob <= JOB::NONE || iJob >= JOB::END)
			iJob = JOB::NONE;
	}
	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer) {

	// �÷��̾� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);
	
	pPlayer->eJob = SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob)
	{
	case JOB::KNIGHT:
		strcpy_s(pPlayer->strJobName, "���");
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
		strcpy_s(pPlayer->strJobName, "�ü�");
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
		strcpy_s(pPlayer->strJobName, "������");
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
	pMonsterArr[0] = CreatMonster("���", 20, 30, 2, 5,
		100, 10, 1, 1000, 500, 1500);

	pMonsterArr[1] = CreatMonster("Ʈ��", 80, 130, 60, 90,
		2000, 100, 5, 7000, 6000, 8000);

	pMonsterArr[2] = CreatMonster("�巡��", 250, 500, 200, 400,
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
		strcpy_s(tItem.strTypeName, "����");
		break;
	case ITEM_TYPE::ARMOR:
		strcpy_s(tItem.strTypeName, "��");
		break;
	}
	
	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;

	return tItem;
}

void SetItem(_tagItem* pWeapon, _tagItem *pArmor) {
	// ================ �������� ���� =================
	pWeapon[0] = CreatItem("���", ITEM_TYPE::WEAPON, 5, 10,
		1000, 500, "������ ���� Į");
	pWeapon[1] = CreatItem("���", ITEM_TYPE::WEAPON, 20, 40,
		7000, 3500, "������ ���� Ȱ");
	pWeapon[2] = CreatItem("������", ITEM_TYPE::WEAPON, 90, 150,
		30000, 15000, "������ ���� ������");

	// ================ ������ ���� =================
	pArmor[0] = CreatItem("õ����", ITEM_TYPE::ARMOR, 2, 5,
		1000, 500, "õ���� ���� ����");
	pArmor[1] = CreatItem("���װ���", ITEM_TYPE::ARMOR, 10, 20,
		7000, 3500, "�������� ���� ����");
	pArmor[2] = CreatItem("Ǯ�÷���Ʈ�Ƹ�", ITEM_TYPE::ARMOR, 70, 90,
		30000, 15000, "��ö�� ���� �Ǳݰ���");
}

STORE_MENU OutputStoreMenu() {
	system("cls");
	cout << "*************************** ���� ***************************\n";
	cout << "1. �������\n";
	cout << "2. ������\n";
	cout << "3. �ڷΰ���\n";
	cout << "������ �����ϼ��� : ";
	STORE_MENU iMenu = STORE_MENU(InputInt());

	if (iMenu <= STORE_MENU::NONE || iMenu > STORE_MENU::BACK)
		iMenu = STORE_MENU::NONE;

	return iMenu;
}

int OutputStoreItemList(_tagInventory* pInventory,
	_tagItem* pStore, int iItemCount) {
	for (int i = 0; i < iItemCount; ++i)
	{
		cout << i + 1 << ". �̸� : " << pStore[i].strName <<
			"\t���� : " << pStore[i].strTypeName << '\n';
		if(strcmp(pStore[i].strTypeName, "����") == 0){
			cout << "���ݷ� : " << pStore[i].iMin << " - " <<
			pStore[i].iMax << '\n';
		}
		else {
			cout << "���� : " << pStore[i].iMin << " - " <<
				pStore[i].iMax << '\n';
		}

		cout << "�ǸŰ��� : " << pStore[i].iPrice <<
			"\t���Ű��� : " << pStore[i].iSell << '\n';
		cout << "���� : " << pStore[i].strDesc << "\n";
	}

	cout << iItemCount + 1 << ". �ڷΰ���\n";
	cout << "�����ݾ� : " << pInventory->iGold << " Gold\n";
	cout << "�������� : " << INVENTORY_MAX - pInventory->iItemCount << '\n';
	cout << "������ �������� �����ϼ��� : ";
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
			cout << "*************************** ������� ***************************\n";
			break;
		case STORE_MENU::ARMOR:
			cout << "*************************** ������ ***************************\n";
			break;
		}
		int iInput = OutputStoreItemList(pInventory, pStore, iItemCount);

		if (iInput == INT_MAX) {
			cout << "�߸� �Է��Ͽ����ϴ�.\n";
			system("pause");
			continue;
		}
		else if (iInput == iItemCount + 1)
			break;

		int	iIndex = iInput - 1;

		// �κ��丮�� �� á���� �˻��Ѵ�.
		if (pInventory->iItemCount == INVENTORY_MAX){
			cout << "������ �� á���ϴ�.\n";
			system("pause");
			continue;
		}

		// ���� ������ ���
		else if (pInventory->iGold < pStore[iIndex].iPrice){
			cout << "�����ݾ��� �����մϴ�.\n";
			system("pause");
			continue;
		}

		// ó���� iItemCount�� �ϳ��� �߰��Ǿ����� �ʱ� ������ 0���� �ʱ�ȭ
		// �Ǿ� �����Ƿ� 0�� �ε����� ������ �������� �߰��ϰ� �ȴ�. �׸���
		// ī��Ʈ�� 1�� �ȴ�. �������� �߰��Ҷ��� 1�� �ε����� �߰��ϰԵȴ�.
		pInventory->tItem[pInventory->iItemCount] =
			pStore[iIndex];
		++pInventory->iItemCount;

		// ��带 �����Ѵ�.
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << pStore[iIndex].strName << " �������� �����Ͽ����ϴ�.\n";
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
	cout << "*************************** ���� ***************************\n";
	OutputPlayer(pPlayer);

	for (int i = 0; i < pPlayer->tInventory.iItemCount; ++i)
	{
		cout << i + 1 << ". �̸� : " << pPlayer->tInventory.tItem[i].strName <<
			"\t���� : " << pPlayer->tInventory.tItem[i].strTypeName << '\n';

		if (strcmp(pPlayer->tInventory.tItem[i].strTypeName, "����") == 0) {
			cout << "���ݷ� : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
				pPlayer->tInventory.tItem[i].iMax << '\n';
		}
		else {
			cout << "���� : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
				pPlayer->tInventory.tItem[i].iMax << '\n';
		}
		cout << "���ݷ� : " << pPlayer->tInventory.tItem[i].iMin << " - " <<
			pPlayer->tInventory.tItem[i].iMax << '\n';
		cout << "�ǸŰ��� : " << pPlayer->tInventory.tItem[i].iPrice <<
			"\t���Ű��� : " << pPlayer->tInventory.tItem[i].iSell << '\n';
		cout << "���� : " << pPlayer->tInventory.tItem[i].strDesc << "\n\n";
	}

	cout << pPlayer->tInventory.iItemCount + 1 << ". �ڷΰ���\n";
	cout << "������ �������� �����ϼ��� : ";
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
			cout << "�߸� �����Ͽ����ϴ�.\n";
			system("pause");
			continue;
		}

		else if (iInput == pPlayer->tInventory.iItemCount + 1)
			break;

		// ������ �ε����� �����ش�.
		int	idx = iInput - 1;

		// ����� �������� ��� �ش� �������� ������ ���� ���� ������
		// �����ϰ� �Ѵ�.
		EQUIP eq = ComputeEquipType(pPlayer->tInventory.tItem[idx].eType);

		// �������� �����Ǿ� ���� ��� �����Ǿ��ִ� �����۰� ������ ��������
		// ��ü�� �־�� �Ѵ�. Swap �˰����� Ȱ���Ѵ�.
		if (pPlayer->bEquip[int(eq)] == true)
		{
			_tagItem tSwap = pPlayer->tEquip[int(eq)];
			pPlayer->tEquip[int(eq)] = pPlayer->tInventory.tItem[idx];
			pPlayer->tInventory.tItem[idx] = tSwap;
		}

		// �����Ǿ����� ���� ��� �κ��丮 �������� ����â���� �ű��
		// �κ��丮�� 1ĭ ������� �ȴ�.
		else
		{
			pPlayer->tEquip[int(eq)] = pPlayer->tInventory.tItem[idx];

			for (int i = idx; i < pPlayer->tInventory.iItemCount - 1; ++i)
			{
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}

			--pPlayer->tInventory.iItemCount;

			// ������ �߱� ������ true�� ������ش�.
			pPlayer->bEquip[int(eq)] = true;
		}

		cout <<pPlayer->tEquip[int(eq)].strName << " �������� �����Ͽ����ϴ�.\n" ;

		system("pause");
	}

}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	srand((unsigned int)time(0));
	
	// �÷��̾��� ������ ���� ����ü�� �����Ѵ�
	_tagPlayer	tPlayer = {};

	// �÷��̾� ������ �����Ѵ�.
	SetPlayer(&tPlayer);

	// ���͸� �����Ѵ�.
	_tagMonster	tMonsterArr[int(MAP_TYPE::BACK) - 1] = {};
	SetMonster(tMonsterArr);

	// �������� ��� �������ͽ� ǥ�� �����Ѵ�.
	SetLvUpTable();

	// �������� �Ǹ��� ������ ����� �����Ѵ�.
	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};
	SetItem(tStoreWeapon, tStoreArmor);
	bool bLoop = true;

	while (bLoop) {
		switch (MAIN_MENU(OutputMainMenu()))
		{
		case MAIN_MENU::MAP:
			RunMap(&tPlayer, tMonsterArr);	// �� ���� �����Լ�
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
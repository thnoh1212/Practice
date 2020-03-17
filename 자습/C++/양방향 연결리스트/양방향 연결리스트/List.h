
// #pragma once : �� ��������� �� 1���� ���Խ�Ű�ڴٶ�� �ǹ��̴�.
#pragma once

#include <iostream>

using namespace std;

// ��������� ���� �Լ� ����κ��� ������ش�.
#define NAME_SIZE 32

enum class OUTPUT_TYPE 
{
	NONE,
	OUTPUT,
	INVERSE
};

enum class SORT_TYPE {
	NONE,
	NUMBER,
	AVG
};

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, * PSTUDENT;

typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;
}NODE, * PNODE;

typedef struct _tagList
{
	// pBegin�� pEnd�� ��������� ó���� ���� �ǹ��ϵ��� �����. ���� �����͸� �����ϴ�
	// ���� �ƴϴ�. ���� �����͸� �����ϴ� ���� pBegin�� pEnd ���̿� �����ϰ� �����.
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;


int InputInt();
void InputString(char* pString, int iSize);
void InitList(PLIST pList);
// void ClearList(PLIST pList);
void DestoryList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);
void Search(PLIST pList);
void Delete(PLIST pList);
void Sort(PLIST pList);
/**
 * @file	revAddCode.cpp
 * @author	������� �.�., ��. 515�, ������� 4
 * @date	23 ���� 2018
 * @brief	������������ �������
 *
 * �������� � �������������� ��� �����
 */


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

/**
 * ��������� ��������� ���� �����
 *
 * @param	srcNum - �������� �����
 * @param	sysBase - ������� ��������
 * @param	digitNum - ����������� �����
 * @return	revCode - �������� ��� �����
 */
char* reverseCode (int, int, int);

/**
 * ��������� ��������������� ���� �����
 *
 * @param	srcNum - �������� �����
 * @param	sysBase - ������� ��������
 * @param	digitNum - ����������� �����
 * @return	addCode - �������������� ��� �����
 */
char* additionalCode (int, int, int);

char alpha[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int main ()
{
	setlocale(LC_ALL, "rus");
	int srcNum, sysBase, digitNum;
	printf("������� ������� ���������: ");
	scanf("%i", &sysBase);
	while (sysBase < 2 || sysBase > 36)
	{
		printf("������������ ����! ���������� �������� ���� ���������� - 2..36\n������� ������: ");
		scanf("%i", &sysBase);
	}
	printf("������� ���������� �������� �����: ");
	scanf("%i", &digitNum);
	while (digitNum < 1 || digitNum > 1024)
	{
		printf("������������ ����! ���������� �������� ���� ���������� - 1..1024\n������� ������: ");
		scanf("%i", &digitNum);
	}
	if (pow((float)sysBase, digitNum) >= pow(16.0f, 8))
	{
		printf("\n��������! �� ����� ������ ������!\n��� ��� ��� ��������� ��������� ����� ������������ ��� int (4 �����),\n�� ������������� ������������ ������������� ����� ��� �������� �������� ������\n� ����� �������������� ��������������� ������������!\n\n");
	}
	printf("������� �����: ");
	scanf("%i", &srcNum);
	printf("\n�������� ���: %s\n", reverseCode(srcNum, sysBase, digitNum));
	printf("�������������� ���: %s\n\n", additionalCode(srcNum, sysBase, digitNum));
	return 0;
}


char* reverseCode (int srcNum, int sysBase, int digitNum)
{
	char* revCode = (char*) malloc(1);
	if (srcNum >= pow((float)sysBase, digitNum)/2 || srcNum <= -pow((float)sysBase, digitNum)/2)
	{
		revCode = "(������� ����������: �������� ����� �� ���������� � ��������� ���������� ��������)";
	}
	else
	{
		revCode = (char*) realloc(revCode, digitNum+1);
		revCode[digitNum] = 0;
		if (srcNum < 0)
		{
			srcNum += pow((float)sysBase, digitNum) - 1;
		}
		for (int i = digitNum; i > 0; i--)
		{
			revCode[digitNum-i] = alpha[srcNum / (int)pow((float)sysBase, i-1) % sysBase];
			srcNum %= (int)pow((float)sysBase, i);
		}
	}
	return revCode;
}


char* additionalCode (int srcNum, int sysBase, int digitNum)
{
	char* addCode = (char*) malloc(1);
	if (srcNum >= (pow((float)sysBase, digitNum)/2) || srcNum < -pow((float)sysBase, digitNum)/2)
	{
		addCode = "(������� ����������: �������� ����� �� ���������� � ��������� ���������� ��������)";
	}
	else
	{
		addCode = (char*) realloc(addCode, digitNum+1);
		addCode[digitNum] = 0;
		if (srcNum < 0)
		{
			srcNum += pow((float)sysBase, digitNum);
		}
		for (int i = digitNum; i > 0; i--)
		{
			addCode[digitNum-i] = alpha[srcNum / (int)pow((float)sysBase, i-1) % sysBase];
			srcNum %= (int)pow((float)sysBase, i);
		}
	}
	return addCode;
}
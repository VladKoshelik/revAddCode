/**
 * @file	revAddCode.cpp
 * @author	Кошелик В.О., гр. 515и, вариант 4
 * @date	23 июня 2018
 * @brief	Практическое задание
 *
 * Обратный и дополнительный код числа
 */


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

/**
 * Получение обратного кода числа
 *
 * @param	srcNum - исходное число
 * @param	sysBase - система счиления
 * @param	digitNum - разрядность числа
 * @return	revCode - обратный код числа
 */
char* reverseCode (int, int, int);

/**
 * Получение дополнительного кода числа
 *
 * @param	srcNum - исходное число
 * @param	sysBase - система счиления
 * @param	digitNum - разрядность числа
 * @return	addCode - дополнительный код числа
 */
char* additionalCode (int, int, int);

char alpha[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int main ()
{
	setlocale(LC_ALL, "rus");
	int srcNum, sysBase, digitNum;
	printf("Введите систему счисления: ");
	scanf("%i", &sysBase);
	while (sysBase < 2 || sysBase > 36)
	{
		printf("Некорректный ввод! Допустимый диапазон этой переменной - 2..36\nВведите заново: ");
		scanf("%i", &sysBase);
	}
	printf("Введите количество разрядов числа: ");
	scanf("%i", &digitNum);
	while (digitNum < 1 || digitNum > 1024)
	{
		printf("Некорректный ввод! Допустимый диапазон этой переменной - 1..1024\nВведите заново: ");
		scanf("%i", &digitNum);
	}
	if (pow((float)sysBase, digitNum) >= pow(16.0f, 8))
	{
		printf("\nВнимание! Вы ввели особые данные!\nТак как для вводимого исходного числа используется тип int (4 байта),\nне рекомендуется использовать отрицательные числа при введённых исходных данных\nв целях предотвращения арифметического переполнения!\n\n");
	}
	printf("Введите число: ");
	scanf("%i", &srcNum);
	printf("\nОбратный код: %s\n", reverseCode(srcNum, sysBase, digitNum));
	printf("Дополнительный код: %s\n\n", additionalCode(srcNum, sysBase, digitNum));
	return 0;
}


char* reverseCode (int srcNum, int sysBase, int digitNum)
{
	char* revCode = (char*) malloc(1);
	if (srcNum >= pow((float)sysBase, digitNum)/2 || srcNum <= -pow((float)sysBase, digitNum)/2)
	{
		revCode = "(Перевод невозможен: заданное число не помещается в отведённое количество разрядов)";
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
		addCode = "(Перевод невозможен: заданное число не помещается в отведённое количество разрядов)";
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
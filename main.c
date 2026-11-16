#include <stdio.h>
#include "myarrfunc.h"
int main(void)
{
	int arr[100];
	size_t n = 0;
	int filled = 0;
	int k, result;
	int ch, extra;
	char choice;
	while (1)
	{
		printf("\na. Задать размер массива\n");
		printf("b. Заполнить массив\n");
		printf("c. Показать массив и адреса\n");
		printf("d. Последний положительный элемент\n");
		printf("e. Количество элементов меньше k\n");
		printf("f. Индексы элементов больше k\n");
		printf("g. Выход\n");
		printf("Выберете пункт: ");
		
		ch = getchar();
		if (ch == EOF)
			break;
		choice = (char)ch;
		extra = getchar();
		if (extra != '\n' && extra != EOF)
		{
			while (extra != '\n' && extra != EOF)
				extra = getchar();
			printf("Неверный пункт\n");
			continue;
		}
		switch (choice)
		{
		case 'a':
			if (setSize(&n))
				filled = 0;
			break;
		case 'b':
			if (n == 0)
			{
				printf("Сначала задайте размер\n");
				break;
			}
			filled = 0;
			if (fillArray(arr, n))
				filled = 1;
			break;
		case 'c':
			if (filled)
				showArray(arr, n);
			else
				printf("Массив не заполнен\n");
			break;
		case 'd':
			if (!filled)
			{
				printf("Массив не заполнен\n");
			break;
			}
			if (lastPositive(arr, n, &result))
				printf("Последний положительный: %d\n", result);
			else
				printf("Положительных элементов нет.\n");
			break;
		case 'e':
			if (!filled)
			{
				printf("Массив не заполнен\n");
				break;
			}
			printf("Введите k: ");
			if (!readNumber(&k))
			{
				printf("Ошибка ввода\n");
				break;
			}
			result = countBelow(arr, n, k);
			printf("Количество: %d\n", result);
			break;
		case 'f':
			if (!filled)
			{
				printf("Массив не заполнен\n");
				break;
			}
			printf("Введите k: ");
			if (!readNumber(&k))
			{
				printf("Ошибка ввода\n");
				break;
			}
			printf("Индексы: ");
			result = indicesAbove(arr, n, k);
			if (result == 0)
				printf("нет");
			printf("\n");
			break;
		case 'g':
			return 0;

		default:
			printf("Неверный пункт\n");
		}
	}
	return 0;
}
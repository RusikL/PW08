#include <stdio.h>
#include "myarrfunc.h"
int readNumber(int *number)
{
	char line[100];
	char extra;
	int ch;

	if (fgets(line, sizeof(line), stdin) == NULL)
		return 0;
	int i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] != '\n' && !feof(stdin))
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		return 0;
	}
	if (sscanf(line, " %d %c", number, &extra) != 1)
		return 0;
	return 1;
}
int setSize(size_t *n)
{
	int size;
	printf("Введите размер от 1 до 100: ");
	if (!readNumber(&size))
	{
		printf("Ошибка ввода!\n");
		return 0;
	}
	if (size < 1 || size > 100)
	{
		printf("Неверный размер!\n");
		return 0;
	}
	*n = size;
	printf("Размер установлен: %zu\n", *n);
	return 1;
}
int fillArray(int *arrptr, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("Элемент %zu: ", i);
		if (!readNumber(arrptr + i))
		{
			printf("Ошибка ввода! Заполните массив заново\n");
			return 0;
		}
	}
	printf("Массив заполнен\n");
	return 1;
}
void showArray(int *arrptr, size_t n)
{
	printf("\nИндекс Значение Адрес\n");
	for (size_t i = 0; i < n; i++)
	{
		printf("%6zu %8d %p\n", i, *(arrptr + i), (void *)(arrptr + i));
	}
}
int lastPositive(int *arrptr, size_t n, int *result)
{
	int found = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (*(arrptr + i) > 0)
		{
			*result = *(arrptr + i);
			found = 1;
		}
	}
	return found;
}
int countBelow(int *arrptr, size_t n, int k)
{
	int count = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (*(arrptr + i) < k)
			count++;
	}
	return count;
}
int indicesAbove(int *arrptr, size_t n, int k)
{
	int count = 0;
	for (size_t i = 0; i < n, i++)
	{
		if (*(arrptr + i) > k)
		{
			printf("%zu ", i);
			count++;
		}
	}
	return count;
}
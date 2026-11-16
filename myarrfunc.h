#ifndef MYARRFUNC_H
#define MYARRFUNC_H
#include <stddef.h>
int readNumber(int *number);
int setSize(size_t *n);
int fillArray(int *arrptr, size_t n);
void showArray(int *arrptr, size_t n);

int lastPositive(int *arrptr, size_t n, int *result);
int countBelow(int *arrptr, size_t n, int k);
int indicesAbove(int *arrptr, size_t n, int k);

#endif
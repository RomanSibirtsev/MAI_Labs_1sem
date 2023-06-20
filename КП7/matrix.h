#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t n, m, size;
    int *lb;
    int *ye;
} Matrix;

void matrixCreate(Matrix *matrix);

void matrixDestroy(Matrix *matrix);

void matrixScan(FILE *file, Matrix *matrix);

void matrixPrint(Matrix *matrix);

void matrixPrintTable(Matrix *matrix);

void matrixResize(Matrix *matrix);

void matrixSet(Matrix *matrix, int val, int i, int j);

int matrixGet(Matrix *matrix, size_t i, size_t j);

void matrixGetSize(Matrix *matrix, size_t **arr);

void func(Matrix *matrix, int* arr);

#endif // MATRIX_H

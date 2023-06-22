#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void matrixCreate(Matrix *matrix) {
    matrix->n = 0;
    matrix->m = 0;
    matrix->size = 0;
    matrix->ye = NULL;
    matrix->lb = NULL;
}

void matrixDestroy(Matrix *matrix) {
    free(matrix->lb);
    free(matrix->ye);
    matrix->n = 0;
    matrix->m = 0;
    matrixCreate(matrix);
}

void matrixResize(Matrix *matrix) {
    if (matrix->size == 0) {
        matrix->size = 1;
        matrix->ye = malloc(sizeof(int));
        matrix->lb = malloc(sizeof(int)*2);
        matrix->lb[0] = -1;
    }
    else {
        matrix->size = matrix->size * 2;
        matrix->ye = realloc(matrix->ye, sizeof(int)*matrix->size);
        matrix->lb = realloc(matrix->lb, sizeof(int)*(matrix->size + 1));
    }
}

void matrixSet(Matrix *matrix, int val, int i, int j) {
    int k = 0;

    if (matrix->size == 0) matrixResize(matrix);

    for(; k < matrix->size; ++k)
        if (matrix->lb[k] == -1)
            break;

    if (k == matrix->size) matrixResize(matrix);

    matrix->lb[k] = i * matrix->m + j;
    matrix->lb[k + 1] = -1;
    matrix->ye[k] = val;
}


int matrixGet(Matrix *matrix, size_t i, size_t j) {
    for (int k = 0; matrix->lb[k] != -1; ++k) {
        if (matrix->lb[k] == i * matrix->m + j)
            return matrix->ye[k];
    }
    return 0;
}

void matrixScan(FILE *file, Matrix *matrix) {
    fscanf(file, "%ld %ld", &matrix->n, &matrix->m);
    int val;
    for (int k = 0; k < matrix->n*matrix->m; ++k) {
        fscanf(file, "%d", &val);
        if (val != 0) {
            matrixSet(matrix, val, k / matrix->m, k % matrix->m);
        }
    }
}

void matrixPrint(Matrix *matrix) {
    for(int i = 0; i < matrix->size; ++i) {
        if (matrix->lb[i] == -1) break;
        printf("(%d %d)\n", matrix->lb[i], matrix->ye[i]);
    }
}

void matrixGetSize(Matrix *matrix, size_t** arr) {

    arr[0] = &matrix->n;
    arr[1] = &matrix->m;
}

void func(Matrix *matrix, int* arr) {
    int result[matrix->m];
    int v;
    int count = 0;
    printf("res = (");
    for (int i = 0; i < matrix->m; ++i) {
        v = 0;
        for (int j = 0; j < matrix->n; ++j) {
            int val = matrixGet(matrix, j, i);
            v += val * arr[j];
        }
        result[i] = v;
        printf(" %d", result[i]);
        if (result[i] > 0)
            count++;
    }
    printf(" ) count = %d\n", count);
}

void matrixPrintTable(Matrix *matrix) {
    for(size_t i = 0; i < matrix->n; ++i) {
        for(size_t j = 0; j < matrix->m; ++j) 
            printf("%d ", matrixGet(matrix, i, j));
        printf("\n");
    }
}
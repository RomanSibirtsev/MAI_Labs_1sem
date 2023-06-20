#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void printMenu() {
    printf("0 - print menu\n"
           "1 - print simple matrix\n"
           "2 - print matrix\n"
           "3 - multiplication\n" 
           "4 - exit\n");
}



int main(int argc, char* argv[]) {
    FILE *file;
    if (argc == 2)
        file = fopen(argv[1], "r");
    else 
        file = fopen("t1.txt", "r");
    Matrix matrix;
    matrixCreate(&matrix);
    matrixScan(file, &matrix);
    printMenu();
    int a;
    while (1) {
        scanf("%d", &a);
        if (a == 0) 
            printMenu();
        else if (a == 1)
            matrixPrint(&matrix);
        else if (a == 2)
            matrixPrintTable(&matrix);
        else if (a == 3) {

            size_t *arr[2];
            matrixGetSize(&matrix, arr);
            size_t n = *arr[0];
            int string[n];
            printf("enter vector (1x%ld)   ", n);
            for (int i = 0; i < n; ++i) 
                scanf("%d", &string[i]);
            func(&matrix, string);
        } else if (a == 4) {
            matrixDestroy(&matrix);
            fclose(file);
            break;
        }
        else
            printf("incorrect parametr\n");
    }
}
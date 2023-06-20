#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <locale.h>

#include "enrollee.h"

#define NEUD 20

int readEnrollee(FILE* file, Enrollee* enrollee) {
    return fread(enrollee, sizeof(Enrollee), 1, file) == 1;
}

void printBase(FILE *file) {
    Enrollee enrollee;
    printHead();
    while (readEnrollee(file, &enrollee)){
        printEnrolleeTable(&enrollee);
    }
}

void func(FILE *file) {
    Enrollee enrollee;
    printHead();
    while (readEnrollee(file, &enrollee)){
        if (enrollee.medal == 1 && enrollee.marks[1] <= NEUD)
            printEnrolleeTable(&enrollee);
    }
}

int main(int argc, char* argv[]) {

    if (argc == 3 && strcmp(argv[1], "print") == 0) {
        FILE *file = fopen(argv[2], "r");
        if (file) {
            printBase(file);
        }
        fclose(file);
    }
    if (argc == 3 && strcmp(argv[1], "func") == 0) {
        FILE *file = fopen(argv[2], "r");
        if (file) {
            func(file);
        }
        fclose(file);
    }

    return 0;
}
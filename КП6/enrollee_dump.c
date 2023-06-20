#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <locale.h>

#include "enrollee.h"
#include "types.h"

int readEnrollee(Enrollee* enrollee) {
    return scanf("%[^;];%[^;];%c;%d;%d;%d;%d;%d;%d\n",
    enrollee->lastName,
    enrollee->firstMiddle,
    &enrollee->gender,
    &enrollee->schoolNumber,
    &enrollee->medal,
    &enrollee->marks[0],
    &enrollee->marks[1],
    &enrollee->marks[2],
    &enrollee->essay) == 9;
}

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        printf("input file");
        return 1;
    }
    Enrollee enrollee;
    FILE* file = fopen(argv[1], "w");
    if (!file) {
        perror("can`t open file");
        return 2;
    }
    while (readEnrollee(&enrollee)) {
        fwrite(&enrollee, sizeof(enrollee), 1, file);
    }
    fclose(file);
    return 0;
}
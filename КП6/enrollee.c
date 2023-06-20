#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "enrollee.h"

void printEnrollee(Enrollee *enrollee) {
    printf("%s;%s;%d;%d;%d;%d;%d;%d;%d\n", 
    enrollee->lastName,
    enrollee->firstMiddle,
    enrollee->gender,
    enrollee->schoolNumber,
    enrollee->medal,
    enrollee->marks[0],
    enrollee->marks[1],
    enrollee->marks[2],
    enrollee->essay);
}

void printEnrolleeTable(Enrollee *enrollee) {
    printf("%s", enrollee->lastName);
    for (int i = 0; i < LINE_SIZE - strlen(enrollee->lastName); ++ i)
        printf(" ");
    printf("|");
    printf("%c", enrollee->firstMiddle[0]);
    printf("%c", enrollee->firstMiddle[1]);   
    printf("      |");
    printf("%c", enrollee->gender);
    printf("     |");
    printf("%d", enrollee->schoolNumber);
    for (int i = 0; i < 11 - (int)log10((double)enrollee->schoolNumber); ++ i)
        printf(" ");
    printf("|");
    printf("%d", enrollee->medal);
    printf("    |");
    printf("%d", enrollee->marks[0]);
    printf(" |");
    printf("%d", enrollee->marks[1]);
    printf("  |");
    printf("%d", enrollee->marks[2]);
    printf("       |");
    printf("%d", enrollee->essay);
    printf("   |");
    printf("\n");
}

void printHead(){
    printf("Lastname            |Initials|Gender|SchoolNumber|Medal|Rus|Math|Phys/Info|Essay\n");
    printf("--------------------|--------|------|------------|-----|---|----|---------|-----\n");
}
#ifndef ENROLLEE_H
#define ENROLLEE_H

#include <stdbool.h>

#include "types.h"


#define LINE_SIZE (20U)

#define CLASS_LETTER 26

typedef struct {
    char lastName[LINE_SIZE];
    char firstMiddle[2];
    char gender;
    int schoolNumber;
    bool medal;
    int marks[3];
    bool essay;
} Enrollee;

void printEnrollee(Enrollee *enrollee);

void printEnrolleeTable(Enrollee *enrollee);

void printHead();

#endif // ENROLLEE_H
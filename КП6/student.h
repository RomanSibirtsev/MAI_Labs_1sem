#ifndef STUDENT_H
#define STUDENT_H

#include <stdbool.h>

#include "types.h"

#define LINE_SIZE (40U)

#define CLASS_LETTER 26

typedef enum {
    MALE,
    FEMALE
} Gender;

typedef struct {
    uint russ;
    uint math;
    uint phys;
    uint info;
} Marks;

typedef struct {
    char lastName[LINE_SIZE];
    char firstMiddle[2];
    bool gender;
    uint schoolNumber;
    bool medal;
    Marks marks;
    bool offset;
} Student;
// [I][v][a][n][o][v][0]...[0]
//             40
// [K][L]
// [\0] [0]

void select(
    bool (*get)(Student *, void *),
    void (*put)(char, void *),
    void *data
);

#endif // STUDENT_H
#include <stdbool.h>
#include <stddef.h>

#include "student.h"

void select(
    bool (* const get)(Student *, void *),
    void (* const put)(char, void *),
    void * const data
) {
    Student student;
    while (get(&student, data)) {
        const ptrdiff_t i = classmate.classLetter - 'A';
        if ((classmate.university != NO_UNIVERSITY ||
            classmate.conscription[0] != '\0') &&
            i >= 0 && i < CLASS_LETTER && !classLetter[i]
        ) {
            classLetter[i] = true;
            put(classmate.classLetter, data);
        }
    }
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

int main() {
    FILE *file;
    file = fopen("t.txt", "r");
    Table table;
    tableCreate(&table);
    size_t size;
    char key[KEY_LENGTH] = "b";
    char value[VALUE_LENGTH];
    fscanf(file, "%ld", &size);
    for (size_t i = 0; i < size; ++i) {
        fscanf(file, "%s %s\n", key, value);
        tablePushBack(&table, key, value);
    }
    fclose(file);
    tablePrintGood(&table);
    tableSort(&table);
    printf("\n");
    tablePrintGood(&table);
    scanf("%s", key);
    tableSearch(&table, key);
    tableDestroy(&table);

}
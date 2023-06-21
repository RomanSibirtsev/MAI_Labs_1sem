#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

int main() {
    char *key = "key2";
    char *value = "value2222";
    char str[KEY_LENGTH + VALUE_LENGTH];

    Table table;
    tableCreate(&table);
    tablePushBack(&table, key, value);
    key = "key";
    value = "value___";
    tablePushBack(&table, key, value);
    key = "key3";
    value = "value3333";
    tablePushBack(&table, key, value);
    tablePrintSimple(&table);
    bool a = tableCheckSort(&table);
    bool b = tableCheckSortInv(&table);
    printf("%d %d\n", a, b);
    tableSort(&table);
    tablePrintGood(&table);
    tableDestroy(&table);
}
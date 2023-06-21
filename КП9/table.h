#ifndef TABLE_H
#define TEBLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 5
#define VALUE_LENGTH 10

typedef struct Cell Cell;

struct Cell {
    char data[KEY_LENGTH + VALUE_LENGTH];
};

typedef struct {
    Cell *cell;
    size_t capacity, size;
} Table;

void tableCreate(Table *table);
size_t tableCopacity(Table *table);
void tablePushBack(Table *table, char *key, char *value);
void tableResize(Table *table, size_t newsize);
bool tabeIsEmpty(Table *teble);
char *tableGetBack(Table *table);
void tableDestroy(Table *table);
void tablePrintSimple(Table *table);
void tablePrintGood(Table *table);
void tableGetKey(Table *table, char key[KEY_LENGTH] ,size_t i);
void tableGetValue(Table *table, char value[VALUE_LENGTH] ,size_t i);
void tableSort(Table *table);
bool tableCheckSort(Table *table);
bool tableCheckSortInv(Table *table);
void tableSwap(Table *table, size_t i, size_t j);

#endif //TABLE_H
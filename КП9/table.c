#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

void tableCreate(Table *table) {
    table->cell = NULL;
    table->capacity = 0;
    table->size = 0;
}

size_t tableCopacity(Table *table) {
    return table->capacity;
}

void tableResize(Table *table, size_t newsize) {
    if (table->size == 0) {
        table->cell = malloc(newsize * sizeof(Cell));
        table->size = newsize;
    }
    else if (newsize > table->size) {
        table->cell = realloc(table->cell, newsize * sizeof(Cell));
        table->size = newsize;
    }
    else if (newsize < table->size) {
        table->size = newsize;
        if (table->size < table->capacity)
            table->capacity = table->size;
    }
}

void tablePushBack(Table *table, char *key, char *value) {
    char data[KEY_LENGTH + VALUE_LENGTH];
    strcpy(data, key);
    strcpy(data + KEY_LENGTH, value);

    Cell newcell;
     for (int i = 0; i <KEY_LENGTH + VALUE_LENGTH; ++ i)
         newcell.data[i] = data[i];

    if (table->capacity < table->size) {
        table->cell[table->capacity] = newcell;
        table->capacity++;
    } else {
        tableResize(table, table->size + 1);
        table->cell[table->capacity] = newcell;
        table->capacity++;
    }
}

void tablePrintSimple(Table *table) {
    for (size_t i = 0; i < table->capacity; ++i) {
        for (size_t j = 0; j < KEY_LENGTH + VALUE_LENGTH; ++j)
            printf("%c", table->cell[i].data[j]);
        printf("\n");
    }
}

void tableDestroy(Table *table) {
    free(table->cell);
    table->cell = NULL;
    table->size = 0;
    table->capacity = 0;
}

void tableGetValue(Table *table, char value[VALUE_LENGTH] ,size_t i) {
    for (int j = KEY_LENGTH; j < KEY_LENGTH + VALUE_LENGTH; ++j) {
        value[j - KEY_LENGTH] = table->cell[i].data[j];
    }
}

void tableGetKey(Table *table, char key[KEY_LENGTH] ,size_t i) {
    for (int j = 0; j < KEY_LENGTH; ++j) {
        key[j] = table->cell[i].data[j];
    }
}

// линейный выбор с обменом
void tableSort(Table *table) {
    bool sort = tableCheckSort(table);
    if (sort) {
        printf("the table is already sorted \n");
        return;
    }
    bool sortinv = tableCheckSortInv(table);
    if (sortinv) {
        printf("the table is already sorted in reverse order \n");
        tableReverse(table);
        return;
    }
    char key1[KEY_LENGTH];
    char key2[KEY_LENGTH];
    size_t a;
    for (size_t i = 0; i < table->size - 1; ++i) {
        a = i;
        tableGetKey(table, key1, i);
        for (size_t j = i + 1; j < table->capacity; ++j) {
            tableGetKey(table, key2, j);
            if (strcmp(key2, key1) < 0) {
                tableGetKey(table, key1, j);
                a = j;
            }
        }
        tableSwap(table, a, i);
    }

}

void tableSwap(Table *table, size_t i, size_t j) {
    Cell tmp = table->cell[i];
    for (int k = 0; k < KEY_LENGTH+VALUE_LENGTH; ++k) {
        table->cell[i].data[k] = table->cell[j].data[k];
    }
    for (int k = 0; k < KEY_LENGTH+VALUE_LENGTH; ++k) {
        table->cell[j].data[k] = tmp.data[k];
    }
}

bool tableCheckSort(Table *table) {
    bool check = 1;
    char first[KEY_LENGTH];
    char second[KEY_LENGTH];
    for (size_t i = 1; i < table->capacity; ++i) {
        tableGetKey(table, first, i - 1);
        tableGetKey(table, second, i);
        if (strcmp(first, second) > 0){
            check = 0;
            break;
        }
    }
    return check;
}

void tableReverse(Table *table) {
    for (size_t i = 0; i < table->capacity / 2; ++i) {
        tableSwap(table, i, table->capacity - 1 - i);
    }
}

bool tableCheckSortInv(Table *table) {
    bool check = 1;
    char first[KEY_LENGTH];
    char second[KEY_LENGTH];
    for (size_t i = 1; i < table->capacity; ++i) {
        tableGetKey(table, first, i - 1);
        tableGetKey(table, second, i);
        if (strcmp(first, second) < 0){
            check = 0;
            break;
        }
    }
    return check;
}

void tablePrintGood(Table *table) {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
    for (size_t i = 0; i < table->capacity; ++i) {
        tableGetKey(table, key, i);
        tableGetValue(table, value, i);
        printf("%s", key);  
        printf("  "); 
        printf("%s", value);
        printf("\n");
    }
}

void tableSearch(Table *table, char key[KEY_LENGTH]) {
    size_t len = table->capacity;
    size_t middle = len / 2;
    char V[VALUE_LENGTH];
    while(len != 0) {
        len = len / 2;
        char K[KEY_LENGTH];
        tableGetKey(table, K, middle);
        if (strcmp(K, key) > 0) {
            middle -= len / 2 + 1;
        } else if (strcmp(K, key) < 0) {
            middle += len / 2 + 1;
        } else {
            tableGetValue(table, V, middle);
            printf("%s\n", V);
            return;
        }
    }
    printf("key not in table\n");
}
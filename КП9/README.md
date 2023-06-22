
# Отчет по курсовому проекту по заданию №9 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «20» июня 2023 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Отчет сдан___ «20» июня 2023 г., ___итоговая оценка___ 
Подпись преподавателя: ________________ 

## 1. Тема

Сортировка и поиск

## 2. Цель работы

Составить программу на языке Си с использованием процедур и функций для сортировки таблицы заданным методом и двоичного поиска по ключу в таблице

## 3. Задание
Программа должна вводить значения элементов неупорядоченной таблицы и проверять работу процедуры
сортировки в трех случаях: (1) элементы таблицы с самого начала упорядочены; (2) элементы таблицы расставлены в
обратном порядке; (3) элементы таблицы не упорядочены. В последнем случае можно использовать встроенные процедуры
генерации псевдослучайных чисел.
Для каждого вызова процедуры сортировки необходимо печатать исходное состояние таблицы и результаты
сортировки. После выполнения сортировки программа должна вводить ключи и для каждого из них выполнять поиск в
упорядоченной таблице с помощью процедуры двоичного поиска и печатать найденные элементы, если они присутствуют в
таблице.

## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB
## 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Manjaro Linux, ___версия___  5.15.65-1-MANJARO
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano
## 6. Идея, метод, алгоритм решения

## 7. Сценарий выполнения работы
main.c
```c
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
```
table.h
```c
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
void tableReverse(Table *table);
void tableSwap(Table *table, size_t i, size_t j);
void tableSearch(Table *table, char key[KEY_LENGTH]);

#endif //TABLE_H
```
table.c
```c
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
```
## 8. Распечатка протокола
```bash
roman@DESKTOP-R7FKK1E:~/fundamentals-of-computer-science-RomanSibirtsev/КП9$ ./a.out 
aaaa  val1
abaa  val2
adfr  ahaha
fgfd  dadaaa
pppp  hihi
aaab  aaaaaa
abcd  fdgdfx
bbbc  nope
aaav  ddddd
abbc  dszdg
dsfg  fdbcv
vbtd  val0000
zzzz  ru
dgse  fdfsdf

aaaa  val1
aaab  aaaaaa
aaav  ddddd
abaa  val2
abbc  dszdg
abcd  fdgdfx
adfr  ahaha
bbbc  nope
dgse  fdfsdf
dsfg  fdbcv
fgfd  dadaaa
pppp  hihi
vbtd  val0000
zzzz  ru
adfr
ahaha
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата     | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ |----------| ------ | ------ | ------ | ------ |
| 1 | дом. | 20.06.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы


## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева

Подпись студента _________________

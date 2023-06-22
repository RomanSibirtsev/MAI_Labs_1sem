
# Отчет по курсовому проекту по заданию №6 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «20» июня 2023 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Отчет сдан___ «20» июня 2023 г., ___итоговая оценка___ 
Подпись преподавателя: ________________ 

## 1. Тема

Обработка последовательной файловой структуры на языке Си

## 2. Цель работы

Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом.

## 3. Задание

Разработать последовательную структуру данных для представления простейшей базы данных на
файлах в СП Си в соответствии с заданным вариантом. Составить программу генерации внешнего
нетекстового файла заданной структуры, содержащего представительный набор записей.
Распечатать содержимое сгенерированного файла в виде таблицы и выполнить над ним заданное действие для
3–5 значений параметров запроса p и распечатать результат.

## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB
## 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Manjaro Linux, ___версия___  5.15.65-1-MANJARO
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano
## 6. Идея, метод, алгоритм решения
Программа содержит два исполняемых файла: один переводит из текстового формата в бинарный, другой обрабатывает бинарный файл.
## 7. Сценарий выполнения работы
Makefile
```
CC=gcc

main: main.o  enrollee.c enrollee.h enrollee_dump
	$(CC) main.o enrollee.c enrollee.h -lm -o main

enrollee_dump: enrollee_dump.o
	$(CC) enrollee_dump.o -o enrollee_dump

enrollee_dump.o: enrollee_dump.c
	$(CC) -c enrollee_dump.c -o enrollee_dump.o

main.o: main.c enrollee.c enrollee.h
	$(CC) -c main.c -lm -o main.o

clean:
	rm -r build
```
main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <locale.h>

#include "enrollee.h"

#define FAILED 20

int readEnrollee(FILE* file, Enrollee* enrollee) {
    return fread(enrollee, sizeof(Enrollee), 1, file) == 1;
}

void printBase(FILE *file) {
    Enrollee enrollee;
    printHead();
    while (readEnrollee(file, &enrollee)){
        printEnrolleeTable(&enrollee);
    }
}

void func(FILE *file) {
    Enrollee enrollee;
    printHead();
    while (readEnrollee(file, &enrollee)){
        if (enrollee.medal == 1 && enrollee.marks[1] <= FAILED)
            printEnrolleeTable(&enrollee);
    }
}

int main(int argc, char* argv[]) {

    if (argc == 3 && strcmp(argv[1], "print") == 0) {
        FILE *file = fopen(argv[2], "r");
        if (file) {
            printBase(file);
        }
        fclose(file);
    }
    if (argc == 3 && strcmp(argv[1], "func") == 0) {
        FILE *file = fopen(argv[2], "r");
        if (file) {
            func(file);
        }
        fclose(file);
    }

    return 0;
}
```
enrollee.c
```c
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
```
enrolle.h
```c
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
```
enrollee.c
```c
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
```
text.txt
```txt
Formalev;AH;M;107;1;80;60;100;1
Khalimov;IH;M;1;1;10;10;100;1
Ivanov;AG;M;14;1;60;60;80;1
Anreev;VP;F;52;1;90;90;90;1
Danilov;GD;F;12;0;80;90;90;1
```



## 8. Распечатка протокола
```bash
roman@DESKTOP-R7FKK1E:~/fundamentals-of-computer-science-RomanSibirtsev/КП6$ ./enrollee_dump t.txt < text.txt
roman@DESKTOP-R7FKK1E:~/fundamentals-of-computer-science-RomanSibirtsev/КП6$ ./main print t.txt
Lastname            |Initials|Gender|SchoolNumber|Medal|Rus|Math|Phys/Info|Essay
--------------------|--------|------|------------|-----|---|----|---------|-----
Formalev            |AH      |M     |107         |1    |80 |60  |100      |1   |
Khalimov            |IH      |M     |1           |1    |10 |10  |100      |1   |
Ivanov              |AG      |M     |14          |1    |60 |60  |80       |1   |
Anreev              |VP      |F     |52          |1    |90 |90  |90       |1   |
Danilov             |GD      |F     |12          |0    |80 |90  |90       |1   |
roman@DESKTOP-R7FKK1E:~/fundamentals-of-computer-science-RomanSibirtsev/КП6$ ./main func t.txt
Lastname            |Initials|Gender|SchoolNumber|Medal|Rus|Math|Phys/Info|Essay
--------------------|--------|------|------------|-----|---|----|---------|-----
Khalimov            |IH      |M     |1           |1    |10 |10  |100      |1   |
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата     | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ |----------| ------ | ------ | ------ | ------ |
| 1 | дом. | 20.06.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы


## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева

Подпись студента _________________

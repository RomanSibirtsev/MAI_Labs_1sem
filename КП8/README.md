
# Отчет по курсовому проекту по заданию №8 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «20» июня 2023 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Отчет сдан___ «20» июня 2023 г., ___итоговая оценка___ 
Подпись преподавателя: ________________ 

## 1. Тема

Линейные списки

## 2. Цель работы

Составить и отладить программу на языке Си для обработки линейного списка

## 3. Задание

Составить и отладить программу на языке Си для обработки линейного списка заданной организации с отображением
списка на динамические структуры (группы 1, 2, 3, 8, 9, 11, 13) или на массив (только с индексным доступом, без
применения ссылок и указателей, для групп 4, 5, 6, 7, 10, 12). Навигацию по списку следует реализовать с применением
итераторов. Предусмотреть выполнение одного нестандартного и четырех стандартных действий:
1. Печать списка.
2. Вставка нового элемента в список.
3. Удаление элемента из списка.
4. Подсчет длины списка.


## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB
## 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Manjaro Linux, ___версия___  5.15.65-1-MANJARO
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano
## 6. Идея, метод, алгоритм решения
Был реализован линейный однонаправленный список с барьерным элементом;
## 7. Сценарий выполнения работы
main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define COMMAND_LEN 40

int main() {
    List list;
    listCreate(&list);
    while (1) {
        printf("pushback\n"
               "print\n"
               "length\n"
               "func\n"
               "pushindex\n"
               "exit\n");
        char command[COMMAND_LEN];
        scanf("%s", command);
        if (strcmp(command, "pushback") == 0) {
            int val;
            printf("insert value:  ");
            scanf("%d", &val);
            listPushBack(&list, val);
        }
        if (strcmp(command, "print") == 0) {
            listPrint(&list);
        }
        if (strcmp(command, "length") == 0)
            printf("%ld\n", listLength(&list));
        if (strcmp(command, "func") == 0) {
            int val;
            printf("insert value:  ");
            scanf("%d", &val);
            listFunc(&list, val);
        }
        if (strcmp(command, "pushindex") == 0) {
            int val, index;
            printf("insert value and index:  ");
            scanf("%d %d", &val, &index);
            listPushIndex(&list, val, index);
        }
        if (strcmp(command, "exit") == 0) {
            break;
        }

    }
    listDestroy(&list);
}
```
list.h
```c
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include "types.h"

typedef struct ListNode ListNode;

typedef struct {
    ListNode *first;
} List;

typedef struct {
    ListNode *node;
} Iterator;

void listCreate(List *list);
void listClear(List *list);
bool listIsEmpty(List *list);
void listInsert(List *list, Iterator *iterator, int val);
void listErase(List *list, Iterator *iterator);
void listDestroy(List *list);
void listPrint(List *list);
void listPushBack(List *list, int val);
void listPushIndex(List *list, int val, int index);
size_t listLength(List *list);
void listFunc(List *list, int val);


Iterator listIteratorNext(List *list, const Iterator *iterator);
Iterator listIteratorPrev(List *list, const Iterator *iterator);
Iterator listIteratorBegin(List *list);
Iterator listIteratorEnd(List *list);
void listIteratorGet(const Iterator *iterator, int val);
Iterator listIteratorSet(List *list, int val);
Iterator listIteratorIndex(List *list, int index);



#endif // LIST_H
```
list.c
```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "list.h"

typedef struct ListNode ListNode;

struct ListNode{
    int *data;
    ListNode *next;
} ;

void listCreate(List *list) {
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->data = NULL;
    list->first = node;
}

void listClear(List *list) {
    Iterator it = listIteratorBegin(list);
     while (!listIsEmpty(list)) {
        listErase(list, &it);
        it = listIteratorBegin(list);
    }
}

bool listIsEmpty(List *list) {
    Iterator begin = listIteratorBegin(list);
    return begin.node->data == NULL;
}

void listInsert(List *list, Iterator *iterator, int val) {
    ListNode *newnode = malloc(sizeof(ListNode));
    int *a = malloc(sizeof(int));
    *a = val;
    newnode->next = iterator->node;
    newnode->data = a;
    Iterator prev;
    prev = listIteratorPrev(list, iterator);
    if (prev.node != NULL) {
        prev.node->next = newnode;
    }
    else
        list->first = newnode;
}

void listErase(List *list, Iterator *iterator) {
    //compareValues(iterator->node->data, val)
    Iterator prev, next;
    prev = listIteratorPrev(list, iterator);
    next = listIteratorNext(list, iterator);

    if (prev.node != NULL)
        prev.node->next = next.node; 
    else
        list->first = next.node;

    free(iterator->node->data);
    free(iterator->node);

    iterator = &next;
}

void listPrint(List *list) {
    Iterator it = listIteratorBegin(list);
    while(it.node->data != NULL) {
        printf("%d ", *it.node->data);
        it = listIteratorNext(list, &it);
    }
    printf("\n");
}
void listPushBack(List *list, int val) {
    Iterator end = listIteratorEnd(list);
    listInsert(list, &end, val);
}

void listPushIndex(List *list, int val, int index) {
    Iterator it = listIteratorIndex(list, index);
    listInsert(list, &it, val);
}

void listDestroy(List *list) {
    Iterator it = listIteratorBegin(list);
    while (!listIsEmpty(list)) {
        listErase(list, &it);
        it = listIteratorBegin(list);
    }
    free(list->first);
    list->first = NULL;
}

size_t listLength(List *list) {
    Iterator it = listIteratorBegin(list);
    size_t length = 0;
    while (it.node != NULL && it.node->data != NULL) {
        length++;
        it = listIteratorNext(list, &it);
    }
    return length;
}


void listFunc(List *list, int val) {
        Iterator it = listIteratorSet(list, val);
        if (it.node != NULL) {
            listClear(list);
            printf("list clear\n");
        }
        else 
            printf("not value in list\n");




}

// iterator
Iterator listIteratorBegin(List *list) {
    return (Iterator){.node = list->first};
}
Iterator listIteratorEnd(List *list) {
    Iterator it = listIteratorBegin(list);
    // if (it.node->end != 1) {
    //     while (it.node->next->end != 1) {
    //         it = listIteratorNext(list, &it);
    //     }
    // }
    while ((it.node)->next != NULL)
        it = listIteratorNext(list, &it);
    return it;
}

Iterator listIteratorNext(List *list, const Iterator *iterator) {
    return (Iterator){.node = iterator->node->next};
}
Iterator listIteratorPrev(List *list, const Iterator *iterator) {
    if (list->first == iterator->node) {
        return (Iterator){.node = NULL};
    }
    Iterator it = listIteratorBegin(list);

    while (it.node->next != iterator->node)
        it = listIteratorNext(list, &it);
    return it;
}

void listIteratorGet(const Iterator *iterator, int val) {
    val = *iterator->node->data;
}

bool compareValues(int v1, int v2) {
    if (v1 == v2)
        return 1; 
    return 0;
}

Iterator listIteratorSet(List *list, int val) {
    Iterator it = listIteratorBegin(list);
    while (it.node->data != NULL)
        if (!compareValues(*it.node->data, val))
            it = listIteratorNext(list, &it);
    if (it.node->data == NULL)
        return (Iterator){.node = NULL};
    return it;
}

Iterator listIteratorIndex(List *list, int index) {
    size_t id = 0;
    Iterator iter = listIteratorBegin(list);
    while (id != index && iter.node->data != NULL) {
        iter = listIteratorNext(list, &iter);
        ++id; 
    }
    return iter;

}
```
## 8. Распечатка протокола
```bash
roman@DESKTOP-R7FKK1E:~/fundamentals-of-computer-science-RomanSibirtsev/КП8$ ./a.out 
pushback
print
length
func
pushindex
exit
pushback
insert value:  5
pushback
insert value:  4
print
5 4 
pushindex
insert value and index:  9 0
print
9 5 4
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата     | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ |----------| ------ | ------ | ------ | ------ |
| 1 | дом. | 20.06.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы


## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева

Подпись студента _________________

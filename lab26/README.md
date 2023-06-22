
# Отчет по лабораторной работе №23 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «31» мая 2023 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Отчет сдан___ «1» июня 2023 г., ___итоговая оценка___ 
Подпись преподавателя: ________________ 

## 1. Тема

Динамические структуры данных. Обработка деревьев

## 2. Цель работы

Научиться работать с деревьями

## 3. Задание

Ситавить и отладить модуль определений и модуль реализации по заданной схеме модуля определений для фбстрактного типа данных. Составить программный модуль, сортирующий экзэмпляр данного абстрактного типа данных заданным методом, используя только оперции, импортированные из модуля UUDT.

 - Процедура: поиск в очереди первого от начала элемента, который меньше своего непосредственного предшественника. Если такой элемент найден, смещение его к началу до тех пор, пока он не станет первым или больше своего предшественника.

 - Метод: вариант метода вставки
## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB
## 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Manjaro Linux, ___версия___  5.15.65-1-MANJARO
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano
## 6. Идея, метод, алгоритм решения
Сначала была реализована структура данных очередь, описан базовый интерфейс взаимодействия со структурой. Очередь была реализована над динамическим массивом. Далее в отдельном файле были реализованы особая процедура, которая была дана в условии, и сортировка данным в условии методом.
## 7. Сценарий выполнения работы
queue.h
```c
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    dbl *data;
    size_t capacity, size, first;
} Queue;

void queue_create(Queue *);
bool queue_is_empty(const Queue *);
int queue_push(Queue *, dbl);
int queue_pop(Queue *);
void queue_print(const Queue *);
size_t queue_size(const Queue *);

#endif //QUEUE_H

```
queue.c
```c
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "queue.h"

static size_t newCapacity(const size_t capacity) {
    if (capacity == 0)
        return 1;
    return capacity <= SIZE_MAX / 2 ? capacity * 2 : SIZE_MAX;
}

void queue_create(Queue * queue) {
    dbl * const data = realloc(queue->data, sizeof(dbl));
    queue->data = data;
    queue->capacity = 1;
    queue->size = 0;
    queue->first = 0;
}

bool queue_is_empty(const Queue * const queue) {
    return queue->size == 0;
}

int queue_push(Queue * const queue, const dbl value) {
    if (queue->first + queue->size == queue->capacity) {
        for (size_t i = 0; i < queue->size; ++i)
            queue->data[i] = queue->data[i + queue->first];
        queue->first = 0;
    }

    if (queue->capacity == queue->size) {
        const size_t capacity = newCapacity(queue->capacity);
        dbl * const data = realloc(queue->data, capacity * sizeof(dbl));
        if (data == NULL)
            return errno;
        queue->data = data;
        queue->capacity = capacity;
    }

    queue->data[queue->size++] = value; // ???
    return 0;
}

int queue_pop(Queue * const queue) {
    if (queue->size == 0)
        return EINVAL;
    ++queue->first;
    --queue->size;
    return 0;
}
void queue_print(const Queue * const queue) {
    for (size_t i = 0; i < queue->size; ++i) {
        printf("%f\n", queue->data[(queue->first + i) % queue->capacity]);
    }
}
size_t queue_size(const Queue * const queue) {
    return queue->size;
}
```
## 8. Распечатка протокола

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата     | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ |----------| ------ | ------ | ------ | ------ |
| 1 | дом. | 31.05.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы


## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева

Подпись студента _________________

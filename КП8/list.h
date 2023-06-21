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
void listInsert(List *list, Iterator *iterator, void *val, char* type);
void listErase(List *list, Iterator *iterator);
void listDestroy(List *list);
void listPrint(List *list);
void listPushBack(List *lis, void* val, char* type);


Iterator listIteratorNext(List *list, const Iterator *iterator);
Iterator listIteratorPrev(List *list, const Iterator *iterator);
Iterator listIteratorBegin(List *list);
Iterator listIteratorEnd(List *list);
void listIteratorGet(const Iterator *iterator, void *val);
Iterator listIteratorSet(List *list, void *val, char *type);



#endif // LIST_H
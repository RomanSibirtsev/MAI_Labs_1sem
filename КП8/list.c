#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "list.h"

typedef struct ListNode ListNode;

struct ListNode{
    void *data;
    char *type;
    ListNode *next;
    bool end;
} ;

void listCreate(List *list) {
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->data = NULL;
    node->type = NULL;
    node->end = 1;
    list->first = node;
}

bool listIsEmpty(List *list) {
    Iterator begin = listIteratorBegin(list);
    return begin.node->end == 1;
}

void listInsert(List *list, Iterator *iterator, void *val, char* type) {
    ListNode *node = malloc(sizeof(ListNode));
    node->next = iterator->node;
    node->data = val;
    node->type = type;
    node->end = 0;
    Iterator prev;
    prev = listIteratorPrev(list, iterator);
    if (prev.node != NULL)
        prev.node->next = node;
    else
        list->first = node;
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

    free(iterator->node);

    iterator = &next;
}

void printVal(void* val, char* type) {
    if (strcmp(type, "int") == 0)
        printf("%d\n", *((int*)val));
    if (strcmp(type, "char") == 0) {
        char* a = (char*)val;
        printf("%s\n", a);
    }
} 

void listPrint(List *list) {
    Iterator it = listIteratorBegin(list);
    while(it.node->end != 1) {
        printVal(it.node->data, it.node->type);
        it = listIteratorNext(list, &it);
    }
}
void listPushBack(List *list, void* val, char* type) {
    Iterator end = listIteratorEnd(list);
    listInsert(list, &end, val, type);
}

void listDestroy(List *list) {
    Iterator it = listIteratorBegin(list);
    while (!listIsEmpty(list)) {
        listErase(list, &it);
        it = listIteratorBegin(list);
        printf("%d erase\n", listIsEmpty(list));
    }
    free(list->first);
    list->first = NULL;
}

// iterator
Iterator listIteratorBegin(List *list) {
    return (Iterator){.node = list->first};
}
Iterator listIteratorEnd(List *list) {
    Iterator it = listIteratorBegin(list);
    if ((it.node)->end != 1) {
        while ((it.node)->next->end != 1) {
            it = listIteratorNext(list, &it);
        }
    }
    if ((it.node)->next != NULL)
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

void listIteratorGet(const Iterator *iterator, void* val) {
    val = (void*)iterator->node->data;
}

bool compareValues(void* v1, char* type1, void *v2, char *type2) {

    if (strcmp(type1, type2) == 0) {
        if (strcmp(type1, "int") == 0)
            return *((int*)v1) == *((int*)v2);
        if (strcmp(type1, "char") == 0) {
            if (strcmp((char*)v1, (char*)v2) == 0)
                return 1;
            return 0;
        }
    }
    return 0;
}

Iterator listIteratorSet(List *list, void *val, char *type) {
    Iterator it = listIteratorBegin(list);
    while (!compareValues(it.node->data, it.node->type, val, type) && it.node->end != 1)
        it = listIteratorNext(list, &it);
    if (it.node->end == 1)
        return (Iterator){.node = NULL};
    return it;
}
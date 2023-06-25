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
    while (it.node->data != NULL) {
        if (!compareValues(*it.node->data, val))
            it = listIteratorNext(list, &it);
        else
            break;
    }
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
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void commands(List *list) {
    return;
}

int main() {
    List list;
    char *a = "hui";
    char *type = "char";
    void* ptr = (void*)a;
    int b = 12;
    listCreate(&list);
    listPushBack(&list, ptr, type);
    listPushBack(&list, (void*)&b, "int");
    //listPushBack(&list, (void*)"aboba", (char*)"char");
    Iterator i = listIteratorSet(&list, (void*)&b, "int");
    //listErase(&list, &i);
    bool is = listIsEmpty(&list);
    printf("%d\n", is);
    listPrint(&list);
    listDestroy(&list);
    
}
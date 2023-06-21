#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main() {
    List list;
    listCreate(&list);
    int a = 3, b = 5, c = 987, d = 456;
    char *s1 = "qwe", *s2 = "aaaa", *s3 = "bbbb";
    listPushBack(&list, (void*)&a, "int");
    listPushBack(&list, (void*)s2, "char");
    listPushBack(&list, (void*)&b, "int");
    listPushBack(&list, (void*)s1, "char");
    listPushBack(&list, (void*)&d, "int");
    listPushBack(&list, (void*)s3, "char");
    listPushBack(&list, (void*)&c, "int");
    listPrint(&list);
    listFunc(&list, (void*)&b, "char");
    listFunc(&list, (void*)&b, "int");
    listDestroy(&list);
    
}
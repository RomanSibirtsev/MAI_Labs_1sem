#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define COMMAND_LEN 40

int main() {
    List list;
    listCreate(&list);
    printf("pushback\n"
               "print\n"
               "length\n"
               "func\n"
               "pushindex\n"
               "exit\n");
    while (1) {
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
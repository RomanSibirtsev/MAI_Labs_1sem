#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main() {

    Tree tree;

    while (1) {
        printf(
                "0 - create tree\n"
                "1 - add node\n"
                "2 - print tree\n"
                "3 - delete node\n"
                "4 - check symmetric\n"
                "5 - end program\n"
                "6 - preorder\n"
                "7 - inorder\n"
                "8 - postorder\n"
               );

        int key;
        scanf("%d", &key);

        if (key == 0)
            treeCreate(&tree);
        else if (key == 1) {
            printf("enter value\n");
            int val;
            scanf("%d", &val);
            treeInsert(&tree, val);
        }
        else if (key == 2)
            treePrint(&tree);
        else if (key == 3) {
            printf("enter value\n");
            int val2;
            scanf("%d", &val2);
            treeErase(&tree, val2);
        }
        else if (key == 4)
            printf("%d\n", treeCheckSym(&tree));
        else if (key == 5)
            break;
        else if (key == 6)
            treePreorder(&tree);
        else if (key == 7)
            treeInorder(&tree);
        else if (key == 8)
            treePostorder(&tree);
    }

    return 0;
}
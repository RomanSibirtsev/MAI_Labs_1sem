#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main() {

    Tree tree;

    printf(
                "0 - create tree\n"
                "1 - add node\n"
                "2 - print tree\n"
                "3 - delete node\n"
                "4 - check symmetric\n"
                "5 - preorder\n"
                "6 - inorder\n"
                "7 - postorder\n"
                "8 - treeClear\n"
                "9 - end program\n"
               );

    while (1) {

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
        else if (key == 9) {
            treeClear(&tree);
            break;
        }
        else if (key == 5)
            treePreorder(&tree);
        else if (key == 6)
            treeInorder(&tree);
        else if (key == 7)
            treePostorder(&tree);
         else if (key == 8)
            treeClear(&tree);
    }

    return 0;
}
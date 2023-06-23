#ifndef STACKBIN_H
#define STACKBIN_H

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct TreeNode TreeNode;
typedef struct Pair Pair;

struct Pair{    
    TreeNode *node;
    bool v;
};

typedef struct {
    Pair *data;
    int top, size;
} StackBin;

void stackBinCreate(StackBin *stack);
void stackBinDestroy(StackBin *stack);
Pair stackBinTop(StackBin *stack);
void stackBinPush(StackBin *stack, TreeNode *node, bool v);
Pair stackBinPop(StackBin *stack);
void stackBinResize(StackBin *stack, int newsize);
bool stackBinIsEmpty(StackBin *stack);
void stackBinPrint(StackBin *stack);


#endif //TREE_H

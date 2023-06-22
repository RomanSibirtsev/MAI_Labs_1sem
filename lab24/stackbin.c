#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackbin.h"
#include "tree.h"


void stackBinCreate(StackBin *stack) {
    stack->data = NULL;
    stack->top = -1;
    stack->size = 0;
}
void stackBinDestroy(StackBin *stack) {
    free(stack->data);
    stack->top = -1;
    stack->size = 0;
    stack->data = NULL;
}
struct Pair stackBinTop(StackBin *stack) {
    return stack->data[stack->top];
}
void stackBinPush(StackBin *stack, TreeNode *node, bool v) {
    Pair pair;
    pair.node = node;
    pair.v = v;

    if (stack->top + 1 == stack->size)
        stackBinResize(stack, stack->size + 1);
    stack->data[stack->top + 1] = pair;
    stack->top++;
}
struct Pair stackBinPop(StackBin *stack) {
    stack->top--;
    return stack->data[stack->top + 1];

}
void stackBinResize(StackBin *stack, int newsize) {
    if (stack->data == NULL) {
        stack->data = malloc(sizeof(char) * newsize);
        stack->size = newsize;
    } else {
        stack->data = realloc(stack->data, sizeof(char) * newsize);
        stack->size = newsize;
    }
}
bool stackBinIsEmpty(StackBin *stack) {
    return stack->top == -1;
}

void stackBinPrint(StackBin *stack) {
    while (!stackIsEmpty(stack))
        printf("%c ", stackPop(stack));
}

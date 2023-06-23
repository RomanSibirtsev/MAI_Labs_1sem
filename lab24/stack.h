#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int top, size;
} Stack;

void stackCreate(Stack *stack);
void stackDestroy(Stack *stack);
char stackTop(Stack *stack);
void stackPush(Stack *stack, char v);
char stackPop(Stack *stack);
void stackResize(Stack *stack, int newsize);
bool stackIsEmpty(Stack *stack);
void stackPrint(Stack *stack);
void toPostfix(Stack *stack, char *expression);
int precedence(char ch);
int checkIfOperand(char ch);


#endif //TREE_H

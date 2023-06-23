#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void stackCreate(Stack *stack) {
    stack->data = NULL;
    stack->top = -1;
    stack->size = 0;
}
void stackDestroy(Stack *stack) {
    free(stack->data);
    stack->top = -1;
    stack->size = 0;
    stack->data = NULL;
}
char stackTop(Stack *stack) {
    return stack->data[stack->top];
}
void stackPush(Stack *stack, char v) {
    if (stack->top + 1 == stack->size)
        stackResize(stack, stack->size + 1);
    stack->data[stack->top + 1] = v;
    stack->top++;
}
char stackPop(Stack *stack) {
    stack->top--;
    return stack->data[stack->top + 1];

}
void stackResize(Stack *stack, int newsize) {
    if (stack->data == NULL) {
        stack->data = malloc(sizeof(char) * newsize);
        stack->size = newsize;
    } else {
        stack->data = realloc(stack->data, sizeof(char) * newsize);
        stack->size = newsize;
    }
}
bool stackIsEmpty(Stack *stack) {
    return stack->top == -1;
}

void stackPrint(Stack *stack) {
    while (!stackIsEmpty(stack))
        printf("%c ", stackPop(stack));
}

int checkIfOperand (char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence (char ch) {
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}

void toPostfix(Stack *stack, char *expression) {
      int i, j;

  for (i = 0, j = -1; expression[i]; ++i)
    {
      if (checkIfOperand (expression[i]))
	expression[++j] = expression[i];

      else if (expression[i] == '(')
		stackPush(stack, expression[i]);

      else if (expression[i] == ')')
	{
	  while (!stackIsEmpty(stack) && stackTop(stack) != '(')
	    expression[++j] = stackPop(stack);
	  if (!stackIsEmpty(stack) && stackTop(stack) != '(')
	    return ;	              
	  else
	    stackPop(stack);
	}
      else	
	{
	  while (!stackIsEmpty(stack)
		 && precedence(expression[i]) <= precedence(stackTop(stack)))
	    expression[++j] = stackPop(stack);
	  stackPush(stack, expression[i]);
	}
    }
  while (!stackIsEmpty(stack))
    expression[++j] = stackPop(stack);

  expression[++j] = '\0';
}
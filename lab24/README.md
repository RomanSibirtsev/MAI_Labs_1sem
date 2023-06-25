# Отчет по лабораторной работе №24 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «20» июня 2023 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Отчет сдан___ «20» июня 2023 г., ___итоговая оценка___ 
Подпись преподавателя: ________________ 

## 1. Тема

Динамические структуры данных. Обработка деревьев

## 2. Цель работы

Составить программу на Си выполнения заданных преобразований арифметическиз выражений с применением деревьев.

## 3. Задание

Убрать из частных все делители, равные единице

## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB
## 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Manjaro Linux, ___версия___  5.15.65-1-MANJARO
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano
## 6. Идея, метод, алгоритм решения

Выражение представляется в виде бинарного дерева, вершины-листы которого представляют переменные или числовые значения, а вершины, не являющиеся листами хранят в себе операцию, выполняемую над выражениями в поддеревьях.

## 7. Сценарий выполнения работы

main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "stack.h"
#include "stackbin.h"

#define MAX_SIZE 100

void exptostack(Stack *stack, char *expression) {
	int i = 0;
	char c = expression[i];
	while(c != '\0') {
		stackPush(stack, c);
		c = expression[++i];
	}
}

int main() {
	char expression[MAX_SIZE];
	Stack stack, res;
	StackBin s;
	Tree tree;
	treeCreate(&tree);
	stackBinCreate(&s);
	stackCreate(&stack);
	stackCreate(&res);

	printf("enter expression\n");
	scanf("%s", expression);
	//printf("%s\n", expression);
	toPostfix(&stack, expression);
	exptostack(&res, expression);
	treeFromPostfix(&tree, &res, &s);
	treePrint(&tree);
	printf("\n");
	treeF(&tree);
	treePrint(&tree);
	printf("\n");
	printf("count = %d\n", treeCount(&tree));


	treeDestroy(&tree);
	stackDestroy(&stack);
	stackDestroy(&res);
	stackBinDestroy(&s);

    return 0;
}
```
tree.h
```c
#ifndef TREE_H
#define TREE_H


#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>


#include "stackbin.h"
#include "stack.h"

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root;
    size_t size;
} Tree;

void treeClear(Tree *tree);
void treeCreate(Tree *tree);
void treeDestroy(Tree *tree);
void treePrint(Tree *tree);
void treeFromPostfix(Tree *tree, Stack *postfix, StackBin *stack);
void treeDelOnes(Tree *tree);
bool treeF(Tree *tree);
int treeCount(Tree *tree);

#endif //TREE_H

```
tree.c
```c
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "stackbin.h"
#include "stack.h"
#include "tree.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    TreeNode *parent, *left, *right;
    char value;
};

void treeCreate(Tree *tree) {
    tree->root= NULL;
    tree->size = 0;
}

size_t treeSize(Tree *tree) {
    return tree->size;
}

void treeFromPostfix(Tree *tree, Stack *postfix, StackBin *stack) {
    char ch;
    TreeNode **root = &tree->root;
    stackBinPush(stack, *root, 0);
    Pair pair;
    TreeNode *node = NULL;
    TreeNode *parent = NULL;

	while (!stackBinIsEmpty(stack)) {
		pair = stackBinPop(stack);
		parent = pair.node;
		bool isleft = pair.v;
        node = malloc(sizeof(TreeNode));
		node->parent = parent;
		node->value = stackPop(postfix);
        node->left = NULL;
        node->right = NULL;

		if (parent == NULL) {
			*root = node;
		} else if (isleft) {
			parent->left = node;
            tree->size++;
		} else {
			parent->right = node;
            tree->size++;
		}
		if (precedence(node->value) != -1) {
			stackBinPush(stack, node, 1);
			stackBinPush(stack, node, 0);
		}
	}
}

void nodePrint(TreeNode * node, size_t depth) {

    for (size_t i = 0; i < depth; ++i)
        printf(" ");
    printf("%c\n", node->value);
    if (node->left != NULL)
        nodePrint(node->left, depth + 1);
    if (node->right != NULL)
        nodePrint(node->right, depth + 1);

}

void treePrint(Tree * const tree) {
    bool check = treeSize(tree);
    if (!check)
        printf("Tree is empty\n");
    else
        nodePrint(tree->root, 0);

}

void nodeFunc(TreeNode * node) {
    TreeNode *copy = node;
    if (node->value == '/') {
        if (node->right->value == '1') {
            if (node->parent->left == node) {
                node->left->parent = node->parent;
                node->parent->left = node->left;
                copy = node->parent;
                free(node->right);
                free(node);
            } else {
                node->left->parent = node->parent;
                node->parent->right = node->left;
                copy = node->parent;
                free(node->right);
                free(node);
            }
        }
    }
    if (copy != NULL) {
        if (copy->left != NULL)
            nodeFunc(copy->left);
        if (copy->right != NULL)
            nodeFunc(copy->right);
    }

}

bool treeF(Tree *tree) {
    nodeFunc(tree->root);
}

void treeDestroy(Tree *tree)  {
    TreeNode *node = tree->root;
    TreeNode *root = tree->root;
    while (root->left != NULL || root->right != NULL) {
        if (node->left != NULL)
            node = node->left;
        else if (node->right != NULL)
            node = node->right;
        else {
            if (node->parent->left == node) {
                node = node->parent;
                free(node->left);
                node->left = NULL;
                --tree->size;
            }
            else if (node->parent->right == node) {
                node = node->parent;
                free(node->right);
                node->right = NULL;
                --tree->size;
            }
        }
    }
    free(root);
    tree->root = NULL;
    --tree->size;
}

int nodeCount(TreeNode *node) {
    if (checkIfOperand(node->value)) {
        return node->value - '0';
    }
    if (node->value == '/') {
        return nodeCount(node->left) / nodeCount(node->right);
    }
    if (node->value == '*') {
        return nodeCount(node->left) * nodeCount(node->right);
    }
    if (node->value == '+') {
        return nodeCount(node->left) + nodeCount(node->right);
    }
    if (node->value == '-') {
        return nodeCount(node->left) - nodeCount(node->right);
    }
}

int treeCount(Tree *tree) {
    return nodeCount(tree->root);
}
```
stack.h
```c
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
```
stack.c
```c
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
```
stackbin.h
```c
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
```
stackbin.c
```c
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackbin.h"

typedef struct Pair Pair;

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
        stack->data = malloc(sizeof(Pair) * newsize);
        stack->size = newsize;
    } else {
        stack->data = realloc(stack->data, sizeof(Pair) * newsize);
        stack->size = newsize;
    }
}
bool stackBinIsEmpty(StackBin *stack) {
    return stack->top == -1;
}

void stackBinPrint(StackBin *stack) {
    while (!stackBinIsEmpty(stack))
        printf("%d ", stackBinPop(stack).v);
}
```
## 8. Распечатка протокола
```bash
roman@DESKTOP-R7FKK1E:~/fundamentals-of-computer-science-RomanSibirtsev/lab24$ ./a.out 
enter expression
1*2+(7+9*(a-1))/1+b
+
 +
  *
   1
   2
  /
   +
    7
    *
     9
     -
      a
      1
   1
 b

+
 +
  *
   1
   2
  +
   7
   *
    9
    -
     a
     1
 b
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата     | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ |----------| ------ | ------ | ------ | ------ |
| 1 | дом. | 20.06.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

[div2_A](https://codeforces.com/contest/1837/submission/207186306)

## 11. Выводы
Были детальнее изучены динамические структуры данных. Были получены основы синтаксического анализа и написания парсеров для текста. 

Подпись студента _________________

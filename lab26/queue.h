#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    dbl *data;
    size_t capacity, size, first;
} Queue;

void queue_create(Queue *);
bool queue_is_empty(const Queue *);
int queue_push(Queue *, dbl);
int queue_pop(Queue *);
void queue_print(const Queue *);
size_t queue_size(const Queue *);

#endif //QUEUE_H

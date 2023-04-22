#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "queue.h"

static size_t newCapacity(const size_t capacity) {
    if (capacity == 0)
        return 1;
    return capacity <= SIZE_MAX / 2 ? capacity * 2 : SIZE_MAX;
}

void queue_create(Queue * queue) {
    dbl * const data = realloc(queue->data, sizeof(dbl));
    queue->data = data;
    queue->capacity = 1;
    queue->size = 0;
    queue->first = 0;
}

bool queue_is_empty(const Queue * const queue) {
    return queue->size == 0;
}

int queue_push(Queue * const queue, const dbl value) {
    if (queue->first + queue->size == queue->capacity) {
        for (size_t i = 0; i < queue->size; ++i)
            queue->data[i] = queue->data[i + queue->first];
        queue->first = 0;
    }

    if (queue->capacity == queue->size) {
        const size_t capacity = newCapacity(queue->capacity);
        dbl * const data = realloc(queue->data, capacity * sizeof(dbl));
        if (data == NULL)
            return errno;
        queue->data = data;
        queue->capacity = capacity;
    }

    queue->data[queue->size++] = value; // ???
    return 0;
}

int queue_pop(Queue * const queue) {
    if (queue->size == 0)
        return EINVAL;
    ++queue->first;
    --queue->size;
    return 0;
}
void queue_print(const Queue * const queue) {
    for (size_t i = 0; i < queue->size; ++i) {
        printf("%f\n", queue->data[(queue->first + i) % queue->capacity]);
    }
}
size_t queue_size(const Queue * const queue) {
    return queue->size;
}
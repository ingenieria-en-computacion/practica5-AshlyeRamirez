#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
typedef int Data;

typedef struct {
    Data *data;
    int head;
    int tail;
    int len;
} Queue;

Queue queue_create(int len);
void queue_enqueue(Queue* q, Data d);
Data queue_dequeue(Queue* q);
bool queue_is_empty(Queue* q);
Data queue_front(Queue* q);
void queue_empty(Queue* q);
void queue_delete(Queue* q);

#endif // __QUEUE_H__
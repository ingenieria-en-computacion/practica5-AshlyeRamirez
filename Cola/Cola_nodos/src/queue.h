#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "node.h"
#include <stdbool.h>

typedef struct {
    Node* head;
    Node *tail;
} Queue;

Queue* queue_create();
void queue_enqueue(Queue* q, Data);
int queue_dequeue(Queue* q);
bool queue_is_empty(Queue* q);
Data queue_front(Queue* q);
void queue_empty(Queue* q);
void queue_delete(Queue* q);

#endif // __QUEUE_H__

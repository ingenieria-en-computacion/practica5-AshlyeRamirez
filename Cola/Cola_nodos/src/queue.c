#include "queue.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Queue* queue_create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error al crear la cola.\n");
        return NULL;  // Si no se puede asignar memoria, devuelve NULL
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d){
    Node* newNode = new_node(d);  // Crear un nuevo nodo con el dato
    if (newNode == NULL) {
        printf("Error al crear el nodo.\n");
        return;
    }
    if (q->tail == NULL) {
        // Si la cola está vacía, ambos apuntan al nuevo nodo
        q->head = q->tail = newNode;
    } else {
        // Si la cola no está vacía, agregamos el nodo al final
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int queue_dequeue(Queue* q) {
    if (q->head == NULL) {
        printf("La cola está vacía.\n");
        return -1;  // Indica error si la cola está vacía
    }

    Node* temp = q->head;
    Data dequeued_data = temp->data;

    // Mover el puntero head a siguiente 
    q->head = q->head->next;
    if (q->head == NULL) {
        // Si la cola quedó vacía, tail es NULL
        q->tail = NULL;
    }

    // Liberar la memoria del nodo eliminado
    delete_node(temp);
    return dequeued_data;
}

bool queue_is_empty(Queue* q){
    return (q->head == NULL);
}

Data queue_front(Queue* q){
    if (q->head == NULL) {
        printf("La cola está vacía.\n");
        return -1;  // Indica error si la cola está vacía
    }
    return q->head->data;
}

void queue_empty(Queue* q){
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q){
     queue_empty(q);  // Vaciar la cola
     free(q);  // Liberar la memoria de la estructura de la cola
}

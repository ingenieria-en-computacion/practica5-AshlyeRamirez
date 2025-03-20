#include "queue.h"
#include <stdio.h>

int main()  {
    Queue q = queue_create(10);
    if (queue_is_empty(&q)) {
        printf("Cola vacía al inicio.\n");
}

queue_enqueue(&q, 10);
queue_enqueue(&q, 20);
queue_enqueue(&q, 30);

printf("Frente de la cola: %d\n", queue_front(&q));

    Data removed = queue_dequeue(&q);
    printf("Elemento eliminado: %d\n", removed);

    if (!queue_is_empty(&q)) {
        printf("Cola aún tiene elementos.\n");
    }

    queue_empty(&q);

    if (queue_is_empty(&q)) {
        printf("Cola vacía después de vaciar.\n");
    }

    queue_delete(&q);
    printf("Cola eliminada correctamente.\n");

    return 0;
}

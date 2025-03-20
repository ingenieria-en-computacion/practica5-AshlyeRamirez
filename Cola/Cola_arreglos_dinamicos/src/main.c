#include <stdio.h>
#include "queue.h"

int main() {
    // Crear una cola con capacidad 4 
    Queue q = queue_create(4);
    
    // Verificar si se creó correctamente
    if (q.data == NULL) {
        printf("Error al crear la cola.\n");
        return 1;  // Salir si hubo error al crear la cola
    }

    // Verificar si la cola está vacía
    if (queue_is_empty(&q)) {
        printf("La cola está vacía.\n");
    } else {
        printf("La cola no está vacía.\n");
    }

    // Insertar elementos en la cola
    printf("Insertando elementos en la cola...\n");
    queue_enqueue(&q, 10);
    queue_enqueue(&q, 20);
    queue_enqueue(&q, 30);
    queue_enqueue(&q, 40);
    

    // Intentar insertar un quinto elemento ( no debería funcionar porque la cola está llena)
    queue_enqueue(&q, 50);

    // Mostrar el elemento al frente de la cola sin eliminarlo
    printf("Elemento al frente de la cola: %d\n", queue_front(&q));

    // Extraer elementos
    printf("Extrayendo elementos de la cola...\n");
    while (!queue_is_empty(&q)) {
        printf("Elemento extraído: %d\n", queue_dequeue(&q));
    }

    // Verificar si está vacía
    if (queue_is_empty(&q)) {
        printf("La cola está vacía después de las extracciones.\n");
    } else {
        printf("La cola no está vacía después de las extracciones.\n");
    }

    // Vaciar la cola manualmente (aunque ya debería estar vacía)
    queue_empty(&q);

    // Verificar si la cola está vacía nuevamente
    if (queue_is_empty(&q)) {
        printf("La cola está vacía después de vaciarla manualmente.\n");
    }

    // Eliminar la cola y liberar la memoria
    queue_delete(&q);

    return 0;
}
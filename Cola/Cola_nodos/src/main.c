#include "node.h"
#include "queue.h"
#include <stdio.h>

int main() {
    // Crear una cola
    Queue* q = queue_create();
    if (q == NULL) {
        printf("Error al crear la cola.\n");
        return -1;
    }

    // Agregar elementos a la cola 
    printf("Encolando 10\n");
    queue_enqueue(q, 10);
    printf("Encolando 20\n");
    queue_enqueue(q, 20);
    printf("Encolando 30\n");
    queue_enqueue(q, 30);

    // Mostrar el primer elemento 
    printf("Elemento al frente de la cola: %d\n", queue_front(q));

    // Desencolar un elemento
    printf("Desencolando: %d\n", queue_dequeue(q));

    // Mostrar el primer elemento después de desencolar
    printf("Elemento al frente de la cola después de desencolar: %d\n", queue_front(q));

    // Crear y manipular nodos 
    printf("\nCreando un nodo con valor 100\n");
    Node* n1 = new_node(100);  // Crear un nodo con el valor 100
    print_node(n1);  // Imprimir 

    printf("Creando un nodo con valor 200\n");
    Node* n2 = new_node(200);  // Crear otro nodo con valor 200
    print_node(n2);

    // Liberar los nodos creados
    delete_node(n1);
    delete_node(n2);

    // Vaciar la cola
    queue_empty(q);
    printf("¿La cola está vacía? %s\n", queue_is_empty(q) ? "Sí" : "No");

    // Eliminar la cola
    queue_delete(q);

    return 0;
}
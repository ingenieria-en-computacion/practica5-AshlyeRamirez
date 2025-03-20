#include <stdio.h>
#include "stack.h"
#include "node.h"

int main() {
    // Crear una pila
    Stack* stack = stack_create();
    if (stack == NULL) {
        printf("Error al crear la pila.\n");
        return 1;
    }

    // Agregar elementos a la pila
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    // Imprimir los elementos de la pila
    printf("Elementos de la pila:\n");
    stack_print(stack);

    // Verificar si la pila está vacía
    if (stack_is_empty(stack)) {
        printf("La pila está vacía.\n");
    } else {
        printf("La pila no está vacía.\n");
    }

    // Eliminar el elemento de la pila
    printf("Elemento eliminado: %d\n", stack_pop(stack));

    // Imprimir los elementos restantes de la pila
    printf("Elementos de la pila después de eliminar un elemento:\n");
    stack_print(stack);

    // Vaciar la pila
    stack_empty(stack);
    printf("La pila ha sido vaciada.\n");

    // Verificar si la pila está vacía
    if (stack_is_empty(stack)) {
        printf("La pila está vacía.\n");
    } else {
        printf("La pila no está vacía.\n");
    }

    // Eliminar la pila y liberar la memoria
    stack_delete(stack);

    // Crear un nodo
    Node* node = new_node(100);
    if (node != NULL) {
        printf("Nodo creado con dato: %d\n", node->data);
        print_node(node);  // Imprimir el nodo
        delete_node(node);  // Eliminar el nodo
    } else {
        printf("Error al crear el nodo.\n");
    }

    return 0;
}
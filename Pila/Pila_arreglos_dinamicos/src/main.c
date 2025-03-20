#include <stdio.h>
#include "stack.h"

int main() {
    // Crear una pila con capacidad para 5 elementos
    Stack stack = stack_create(5);
    
    // Comprobar si la pila está vacía
    printf("¿Está la pila vacía? %s\n", stack_is_empty(&stack) ? "Sí" : "No");

    // Insertar elementos en la pila
    printf("Insertando elementos en la pila...\n");
    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);
    stack_push(&stack, 40);
    stack_push(&stack, 50);

    // Imprimir la pila
    printf("Estado de la pila después de insertar elementos:\n");
    stack_print(&stack);

    // Intentar insertar otro elemento (esto no debe funcionar, ya que la pila está llena)
    printf("Intentando insertar un elemento más...\n");
    stack_push(&stack, 60);  // La pila ya está llena, pero lo intentamos de todos modos

    // Eliminar elementos de la pila
    printf("Eliminando elementos de la pila...\n");
    printf("Elemento eliminado: %d\n", stack_pop(&stack));
    printf("Elemento eliminado: %d\n", stack_pop(&stack));

    // Imprimir la pila después de eliminar dos elementos
    printf("Estado de la pila después de eliminar dos elementos:\n");
    stack_print(&stack);

    // Vaciar la pila
    printf("Vaciando la pila...\n");
    stack_empty(&stack);

    // Imprimir la pila después de vaciarla
    printf("Estado de la pila después de vaciarla:\n");
    stack_print(&stack);

    // Eliminar la pila
    stack_delete(&stack);

    return 0;
}
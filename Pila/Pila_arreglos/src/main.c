#include "stack.h"
#include <stdio.h>

int main() {
    // Crear una pila
    Stack s = stack_create();
    printf("Pila creada.\n");

    // Verificar si la pila está vacía
    if (stack_is_empty(&s)) {
        printf("La pila está vacía.\n");
    } else {
        printf("La pila no está vacía.\n");
    }

    // Agregar elementos a la pila
    stack_push(&s, 5);
    stack_push(&s, 10);
    stack_push(&s, 20);
    printf("Se agregaron 3 elementos a la pila.\n");

    // Mostrar los elementos de la pila
    stack_print(&s);

    // Verificar si la pila está vacía ahora
    if (stack_is_empty(&s)) {
        printf("La pila está vacía.\n");
    } else {
        printf("La pila no está vacía.\n");
    }

    // Obtener y eliminar el elemento superior
    printf("Elemento eliminado: %d\n", stack_pop(&s));
    printf("Elemento eliminado: %d\n", stack_pop(&s));

    // Mostrar la pila después de eliminar elementos
    stack_print(&s);

    // Vaciar la pila
    stack_empty(&s);
    printf("Pila vaciada.\n");

    // Verificar si la pila está vacía después de vaciarla
    if (stack_is_empty(&s)) {
        printf("La pila está vacía.\n");
    } else {
        printf("La pila no está vacía.\n");
    }

    return 0;
}
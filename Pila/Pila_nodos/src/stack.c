#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un auntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y top apunta a NULL
 */
Stack *stack_create(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;  // Si no se puede asignar memoria, devuelve NULL
    }
    stack->top = NULL;  // Inicializamos el puntero top como NULL
    return stack;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s == NULL) {
        return;  // Si el puntero de la pila es NULL, no hacer nada
    }

    Node* newNode = new_node(d);  // Creamos un nuevo nodo
    if (newNode == NULL) {
        printf("Error al crear el nodo.\n");
        return;
    }

    // Enlazamos el nuevo nodo al top de la pila
    newNode->next = s->top;
    s->top = newNode;  // Actualizamos top a nuevo nodo
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (s == NULL || s->top == NULL) {
        printf("La pila está vacía.\n");
        return -1;  // Indica error si la pila está vacía
    }

    Node* temp = s->top;  // Apuntamos al nodo mayor
    Data poppedData = temp->data;

    // Actualizamos el top para que apunte al siguiente 
    s->top = s->top->next;

    // Liberamos la memoria del nodo
    delete_node(temp);

    return poppedData;
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Auntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s){
    if (s == NULL) {
        return -1;  // Si el puntero es NULL, no se verificar
    }
    return (s->top == NULL);  // Devuelve 1 si está vacía, 0 si no lo está
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Auntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s){
    if (s == NULL) {
        return;  // Si el puntero es NULL, no hacer nada
    }

    while (s->top != NULL) {
        stack_pop(s);  // Eliminamos todos los elementos
    }
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Auntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s){
    if (s == NULL) {
        return;  // Si el puntero es NULL, no hacer nada
    }

    stack_empty(s);  // Vaciar la pila 
    free(s);  // Liberar la memoria de la pila
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Auntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (s == NULL || s->top == NULL) {
        printf("La pila está vacía o es inválida.\n");
        return;
    }

    Node* current = s->top;
    while (current != NULL) {
        printf("%d\n", current->data);  // Imprimir el dato del nodo
        current = current->next;  // Mover al siguiente nodo
    }
}
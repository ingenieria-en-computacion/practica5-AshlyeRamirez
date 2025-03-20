#include "node.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea un nuevo nodo con los datos proporcionados y lo devuelve.
 * 
 * @param d Dato que se almacenará en el nuevo nodo.
 * @return Un apuntador al nuevo nodo creado. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para un nuevo nodo utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. El nodo creado
 *          tiene sus campos inicializados, y el campo de datos se establece con el valor
 *          proporcionado en el parámetro `d`, el siguiente .
 */
Node *new_node(Data d){
    Node *n = (Node *)malloc(sizeof(Node));  // Asignamos memoria para un nuevo nodo
    if (n == NULL) {  // Verificamos 
        return NULL;  // Si no se pudo, retornamos NULL
    }
    n->data = d;  // Establecemos el dato 
    n->next = NULL;  // Inicializamos el siguiente nodo como NULL
    return n;  // Devolvemos el nuevo nodo 
}

/**
 * Elimina un nodo y libera la memoria asociada a él.
 * 
 * @param n Apuntador al nodo que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para el nodo utilizando `free`.
 *          Si el apuntador pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que el nodo ya no se utiliza después
 *          de ser eliminado. Está función solo libera nodos cuyo enlace al siguiente es nulo
 */
void delete_node(Node* n){
     if (n == NULL) {  // Si es NULL, no hacemos nada
            return;
        }
        if (n->next == NULL) {  // Solo eliminamos el nodo si el siguiente nodo es NULL
            free(n);  // Liberamos la memoria del nodo
        }    
}

/**
 * Imprime la información contenida en un nodo.
 * 
 * @param n Apuntador al nodo que se desea imprimir.
 * @details Esta función imprime los campos del nodo, como su valor y punteros a otros nodos,
 *          en un formato legible. Si el puntero pasado es NULL, la función imprime un mensaje
 *          indicando que el nodo es inválido. La salida se dirige a la salida estándar (stdout).
 */
void print_node(Node* n){
    if (n == NULL) {  // Si el puntero es NULL, imprimimos un mensaje de error
        printf("Nodo inválido.\n");
    } else {
        printf("Nodo: %d\n", n->data);  // Imprimimos el dato almacenado en el nodo
        if (n->next == NULL) {
            printf("Siguiente: NULL\n");  // Si no hay siguiente, indicamos que es NULL
        } else {
            printf("Siguiente: %p\n", (void*)n->next);  // Imprimime la dirección del siguiente nodo
        }
    }
}
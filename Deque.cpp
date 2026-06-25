#include "Deque.h"
#include <stdio.h>


/* Crea un deque vacío. */
void Make(LPPF &deque) {
    deque.prim = NULL;
    deque.ult = NULL;
}

/* Agrega un elemento al principio del deque. */
void Insfront(LPPF &deque, int t){
    Nodo *nuevo = new Nodo;
    nuevo->info = t;
    nuevo->sig = deque.prim;
    deque.prim = nuevo;

    if (deque.ult == NULL) {
        deque.ult = nuevo;
    }
}

/* Agrega un elemento al final del deque. */
void Insback(LPPF &deque, int t) {
    Nodo *nuevo = new Nodo;
    nuevo->info = t;
    nuevo->sig = NULL;

    if (deque.ult == NULL) {
        deque.prim = nuevo;
    } else {
        deque.ult->sig = nuevo;
    }
    deque.ult = nuevo;
}

/* Determina si el deque está vacío o no. */
bool Empty(LPPF deque){
    return deque.prim == NULL;
}

/* Devuelve el primer elemento del deque. */
int Front(LPPF deque){
    return deque.prim->info;
}

/* Devuelve el último elemento del deque. */
int Back(LPPF deque){
    return deque.ult->info;
}

/* Devuelve el deque sin el primer elemento. */
void Remfront(LPPF &deque){
    if (Empty(deque)) {
        printf("Error: Deque is empty.\n");
        return; // or throw an exception
    }
    Nodo *temp = deque.prim;
    deque.prim = deque.prim->sig;
    delete temp;

    if (deque.prim == NULL) {
        deque.ult = NULL;
    }
}

/* Devuelve el deque sin el último elemento. */
void Remback(LPPF &deque){
    if (Empty(deque)) {
        printf("Error: Deque is empty.\n");
        return; // or throw an exception
    }
    if (deque.prim == deque.ult) {
        delete deque.ult;
        deque.prim = NULL;
        deque.ult = NULL;
    } else {
        Nodo *temp = deque.ult;
        Nodo *current = deque.prim;
        while (current->sig != temp) {
            current = current->sig;
        }
        current->sig = NULL;
        deque.ult = current;
        delete temp;
    }
}

/*
    Sumar los elementos en posiciones simétricas respecto de
    los extremos serán sustituidos por la suma de ambos. Por ejemplo, si el deque cuenta
    inicialmente con los valores [2, 4, 8, 6, 7] entonces deberá quedar con los valores [9, 10, 16, 10, 9]
    tras la operación. Implemente la operación solicitada en forma puramente recursiva y usando
    solamente operaciones primitivas del TAD Deque
*/
void SumarSimetricos(LPPF &deque){
    if (Empty(deque) || deque.prim == deque.ult) {
        return; // Base case: empty or single element
    }

    int frontValue = Front(deque);
    int backValue = Back(deque);

    Remfront(deque);
    Remback(deque);

    SumarSimetricos(deque); // Recursive call

    Insfront(deque, frontValue + backValue);
    Insback(deque, frontValue + backValue);
}
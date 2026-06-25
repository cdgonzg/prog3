#include "QueueLPPF.h"

/* Crea un queue vacío. */
void Make(QueueLPPF &q){
    q.prim = NULL;
    q.ult = NULL;
}

/* Agrega un elemento al final del queue. */
void InsBack(QueueLPPF &q, int item){
    Nodo *nuevo = new Nodo;
    nuevo->info = item;
    nuevo->sig = NULL;

    if (q.ult != NULL) {
        q.ult->sig = nuevo;
    } else {
        q.prim = nuevo;
    }
    q.ult = nuevo;
}

/* Determina si el queue está vacío o no. */
bool Empty(const QueueLPPF &q){
    return q.prim == NULL;
}

/* Devuelve el primer elemento del queue. */
/* Precondición: el queue no está vacío. */
int Front(const QueueLPPF &q){
    if (!Empty(q)) {
        return q.prim->info;
    }
}


/* Elimina el primer elemento del queue. */
/* Precondición: el queue no está vacío. */
void RemFront(QueueLPPF &q){
    if (!Empty(q)) {
        Nodo *temp = q.prim;
        q.prim = q.prim->sig;
        if (q.prim == NULL) {
            q.ult = NULL;
        }
        delete temp;
    }
}
#include "QueueArr.h"
// TAD de Queue de int
// Implementación con arreglo con tope

const int QUEUE_CAPACITY = 100;

struct QueueArr {
    int items[QUEUE_CAPACITY];
    int tope;
};

/* Crea un queue vacío. */
void Make(QueueArr &q){
    q.tope = 0;
}

/* Agrega un elemento al final del queue. */
void InsBack(QueueArr &q, int item){
    if (q.tope < QUEUE_CAPACITY) {
        q.items[q.tope] = item;
        q.tope++;
    }
}

/* Determina si el queue está vacío o no. */
bool Empty(const QueueArr &q){
    return q.tope == 0;
}

/*  
    Devuelve el primer elemento del queue.
    Precondición: el queue no está vacío.
*/
int Front(const QueueArr &q){
    if (!Empty(q)) {
        return q.items[0];
    }
}

/*
    Devuelve el queue sin su primer elemento.
    Precondición: el queue no está vacío.
*/
void RemFront(QueueArr &q){
    if (!Empty(q)) {
        for (int i = 0; i < q.tope - 1; i++) {
            q.items[i] = q.items[i + 1];
        }
        q.tope--;
    }
}
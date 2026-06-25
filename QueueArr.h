#ifndef QUEUEARR_H
#define QUEUEARR_H

// TAD de Queue de int
// Implementación de cola circular con capacidad fija

const int QUEUE_CAPACITY = 100;

struct QueueArr {
    int items[QUEUE_CAPACITY];
    int tope;
};

/* Crea un queue vacío. */
void Make(QueueArr &q);

/* Agrega un elemento al final del queue. */
void InsBack(QueueArr &q, int item);

/* Determina si el queue está vacío o no. */
bool Empty(const QueueArr &q);

/*  
    Devuelve el primer elemento del queue.
    Precondición: el queue no está vacío.
*/
int Front(const QueueArr &q);

/*
    Devuelve el queue sin su primer elemento.
    Precondición: el queue no está vacío.
*/
void RemFront(QueueArr &q);

#endif // QUEUEARR_H
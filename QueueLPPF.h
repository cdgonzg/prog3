#ifndef QUEUELPPF_H
#define QUEUELPPF_H

typedef struct nodoL { 
    int info;
    nodoL *sig;
    } Nodo;

typedef struct { 
    Nodo * prim;
    Nodo * ult;
 } QueueLPPF;

/* Crea un queue vacío. */
void Make(QueueLPPF &q);

/* Agrega un elemento al final del queue. */
void InsBack(QueueLPPF &q, int item);

/* Determina si el queue está vacío o no. */
bool Empty(const QueueLPPF &q);

/* Devuelve el primer elemento del queue. */
int Front(const QueueLPPF &q);  
/* Precondición: el queue no está vacío. */

/* Elimina el primer elemento del queue. */
void RemFront(QueueLPPF &q);
/* Precondición: el queue no está vacío. */

#endif // QUEUELPPF_H
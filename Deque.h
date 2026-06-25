#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>

typedef struct nodoL { 
    int info;
    nodoL *sig;
} Nodo;

typedef struct { 
    Nodo * prim;
    Nodo * ult;
} LPPF;

/* Crea un deque vacío. */
void Make(LPPF &deque);

/* Agrega un elemento al principio del deque. */
void Insfront(LPPF &deque, int t);

/* Agrega un elemento al final del deque. */
void Insback(LPPF &deque, int t);

/* Determina si el deque está vacío o no. */
bool Empty(LPPF deque);

/* Devuelve el primer elemento del deque. */
int Front(LPPF deque);

/* Devuelve el último elemento del deque. */
int Back(LPPF deque);

/* Devuelve el deque sin el primer elemento. */
void Remfront(LPPF &deque);

/* Devuelve el deque sin el último elemento. */
void Remback(LPPF &deque);

/*
    Sumar los elementos en posiciones simétricas respecto de
    los extremos serán sustituidos por la suma de ambos. Por ejemplo, si el deque cuenta
    inicialmente con los valores [2, 4, 8, 6, 7] entonces deberá quedar con los valores [9, 10, 16, 10, 9]
    tras la operación. Implemente la operación solicitada en forma puramente recursiva y usando
    solamente operaciones primitivas del TAD Deque
*/
void SumarSimetricos(LPPF &deque);

#endif
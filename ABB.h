#ifndef ABB_H
#define ABB_H

typedef struct nodoA { 
    int info;
    struct nodoA * izq;
    struct nodoA * der;
} Nodo;

 typedef Nodo * ABB;

#endif
#ifndef ABB_H
#define ABB_H

#include <stdio.h>

typedef struct nodoA { 
    int info;
    struct nodoA * izq;
    struct nodoA * der;
} Nodo;

 typedef Nodo * ABB;

/* Crea un diccionario vacío. */
void Make(ABB &abb);

/* Determina si en el diccionario existe un elemento con la clave especificada */
bool Member(ABB abb, int k);

/* Inserta un elemento de tipo T en el diccionario. */
/* Precondición: el elemento a insertar no es miembro del diccionario. */
void Insert(ABB &abb, int t);

/* Dada la clave de un elemento devuelve el elemento con dicha clave */
/* Precondición: el elemento es miembro del diccionario. */
int Find(ABB abb, int k);

#endif
#ifndef HASH_H
#define HASH_H

const int B = 100; /* valor adecuado */

typedef struct nodoL { 
    int info;
    nodoL * sig;
    } Nodo;

typedef Nodo * Lista;

typedef Lista Hash[B];

/* Crea un diccionario vacío. */
void Make(Hash &h);

/* Determina si en el diccionario existe un elemento con la clave especificada */
bool Member(Hash h, int k);

/* Inserta un elemento de tipo T en el diccionario. */
/* Precondición: el elemento a insertar no es miembro del diccionario. */
void Insert(Hash &h, int t);

/* Dada la clave de un elemento devuelve el elemento con dicha clave */
/* Precondición: el elemento es miembro del diccionario. */
int Find(Hash h, int k);

#endif
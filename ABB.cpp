#include "ABB.h"

/* Crea un diccionario vacío. */
void Make(ABB &abb){
    abb = NULL;
}

/* Determina si en el diccionario existe un elemento con la clave especificada */
bool Member(ABB abb, int k){
    if (abb == NULL) {
        return false;
    } else {
        if (k == abb->info) return true;
        else 
            if (k < abb->info) 
                return Member(abb->izq, k);
            else 
                return Member(abb->der, k);
    } 
}

/* Inserta un elemento de tipo T en el diccionario. */
/* Precondición: el elemento a insertar no es miembro del diccionario. */
void Insert(ABB &abb, int t){
    if (abb == NULL) {
        abb = new Nodo;
        abb->info = t;
        abb->izq = NULL;
        abb->der = NULL;
    } else {
        if (t < abb->info) 
            Insert(abb->izq, t);
        else 
            Insert(abb->der, t);
    }
}

/* Dada la clave de un elemento devuelve el elemento con dicha clave */
/* Precondición: el elemento es miembro del diccionario. */
int Find(ABB abb, int k){
    if (k == abb->info) {
        return abb->info;
    } else 
        if (k < abb->info) {
            return Find(abb->izq, k);
        } else {
            return Find(abb->der, k);
        }
}
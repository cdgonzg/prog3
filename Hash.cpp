#include "Hash.h"

/* Crea un diccionario vacío. */
void Make(Hash &h){
    for (int i = 0; i < B; i++) {
        h[i] = nullptr;
    }
}

/* Determina si en el diccionario existe un elemento con la clave especificada */
bool Member(Hash h, int k){
    int index = k % B;
    Nodo *current = h[index];
    while (current != nullptr) {
        if (current->info == k) {
            return true;
        }
        current = current->sig;
    }
    return false;
}

/* Inserta un elemento de tipo T en el diccionario. */
/* Precondición: el elemento a insertar no es miembro del diccionario. */
void Insert(Hash &h, int t){
    int index = t % B;
    Nodo *newNode = new Nodo;
    newNode->info = t;
    newNode->sig = h[index];
    h[index] = newNode;
}

/* Dada la clave de un elemento devuelve el elemento con dicha clave */
/* Precondición: el elemento es miembro del diccionario. */
int Find(Hash h, int k){
    int index = k % B;
    Nodo *current = h[index];
    while (current != nullptr) {
        if (current->info == k) {
            return current->info;
        }
        current = current->sig;
    }
}

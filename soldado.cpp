//
// Created by samuel on 17/10/18.
//

#include "soldado.h"

void soldado::crear(int vida, int ataque, int x, int y) {
    guerrero temp;
    temp.vida = vida;
    temp.ataque = ataque;
    temp.x = x;
    temp.y = y;
    soldado::cuerpo = temp;
}

void soldado::agregar(int x, int y, Vector2f v) {
    auto nuevo_nodo = new nodoSimple();
    nuevo_nodo->x = x;
    nuevo_nodo->y = y;
    nuevo_nodo->vector = v;
    nuevo_nodo->siguiente = nullptr;

    nodoSimple *cola = cabeza;

    if ( cabeza == nullptr ) {
        cabeza = nuevo_nodo;
    } else {
        while (cola->siguiente != nullptr) {
            cola = cola->siguiente;
        }
        cola->siguiente = nuevo_nodo;
    }
}

int soldado::total_eliminacion() {
    cabeza = nullptr;
}

void soldado::eliminar() {
    if ( cabeza->siguiente == nullptr ) {
        cabeza = nullptr;
    } else if ( cabeza->siguiente != nullptr ) {
        nodoSimple *temp = cabeza->siguiente;
        delete cabeza;
        cabeza = temp;
    }
}
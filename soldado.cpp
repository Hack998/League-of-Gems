//
// Created by samuel on 17/10/18.
//
#include "Enemigo.h"
#include "soldado.h"

void soldado::crear(float vida, float ataque, int x, int y) {
    guerrero temp;
    temp.vida = vida;
    temp.ataque = ataque;
    temp.x = x;
    temp.y = y;
    soldado::cuerpo = temp;
}

void soldado::agregar(int x, int y) {
    auto nuevo_nodo = new nodoSimple();
    nuevo_nodo->x = x;
    nuevo_nodo->y = y;
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

void soldado::atacar(int ataque, Enemigo enemigo) {
    switch(ataque){
        case 1:
            enemigo.vida -= soldado::cuerpo.ataque*1.25;
            break;
        case 2:
            enemigo.vida -= soldado::cuerpo.ataque*1.50;
            break;
        case 3:
            enemigo.vida -= soldado::cuerpo.ataque*1.75;
            break;
        case 4:
            enemigo.vida -= soldado::cuerpo.ataque*2;
            break;
        case 5:
            enemigo.vida -= soldado::cuerpo.ataque*2.25;
            break;
        case 6:
            enemigo.vida -= soldado::cuerpo.ataque*2.50;
            break;
        case 7:
            enemigo.vida -= soldado::cuerpo.ataque*2.75;
            break;
        case 8:
            enemigo.vida -= soldado::cuerpo.ataque*3;
            break;
        case 9:
            enemigo.vida -= soldado::cuerpo.ataque*3.25;
            break;
        case 10:
            enemigo.vida -= soldado::cuerpo.ataque*3.25;
            break;
        default:
            enemigo.vida -= soldado::cuerpo.ataque;
            break;
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
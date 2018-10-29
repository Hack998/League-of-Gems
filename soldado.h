//
// Created by samuel on 17/10/18.
//

#ifndef SFML_SOLDADO_H
#define SFML_SOLDADO_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Enemigo;

class soldado {
public:
    // Escructura del nodo de movimiento
    typedef struct NodoSimple {
        int x;
        int y;
        NodoSimple *siguiente;
    } nodoSimple;

    // Escructura del soldaado
    typedef struct Soldado {
        float vida;
        float ataque;
        int x;
        int y;
    } guerrero;

    nodoSimple *cabeza = nullptr;
    guerrero cuerpo;

    //Genera el soldado.
    void crear(float vida, float ataque, int x, int y);

    //Agregar al final.
    void agregar(int x, int y);

    //Atacar
    void atacar(int ataque, Enemigo enemigo);

    //Elimina todos los movimientos en la lista.
    int total_eliminacion();

    //Elimina la cabeza de la lista.
    void eliminar();
};


#endif //SFML_SOLDADO_H

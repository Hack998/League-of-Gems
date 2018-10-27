//
// Created by samuel on 17/10/18.
//

#ifndef SFML_SOLDADO_H
#define SFML_SOLDADO_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class soldado {
public:
    typedef struct NodoSimple {
        int x;
        int y;
        Vector2f vector;
        NodoSimple *siguiente;
    } nodoSimple;

    typedef struct Soldado {
        int vida;
        int ataque;
        int x;
        int y;
        NodoSimple nodo;
    } guerrero;

    nodoSimple *cabeza = nullptr;
    guerrero cuerpo;

    //Genera el soldado
    void crear(int vida, int ataque, int x, int y);

    //Agregar al final
    void agregar(int x, int y, Vector2f v);

    //Buscar en la lista
    int buscar();

    //Elimina la cabeza
    void eliminar();
};


#endif //SFML_SOLDADO_H

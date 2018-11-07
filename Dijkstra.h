//
// Created by samuel on 31/10/18.
//

#ifndef SFML_DIJKSTRA_H
#define SFML_DIJKSTRA_H

#include <string>
#include "window.h"

// Estructura de la Locacion
struct Posicion {
    int row, col;

    Posicion() {
        row = col = 0;
    };

    Posicion(int r, int c) {
        row = r;
        col = c;
    };
};

class Dijkstra {
public:
    static string dijkstra(const Posicion &locStart, const Posicion &locFinish, window::Matriz m);
};


#endif //SFML_DIJKSTRA_H

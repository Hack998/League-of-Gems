//
// Created by samuel on 27/10/18.
//

#ifndef SFML_INICIO_H
#define SFML_INICIO_H

#include <string>
#include "window.h"

using namespace std;

// Estructura de la Locacion
struct Location {
    int row, col;

    Location() {
        row = col = 0;
    };

    Location(int r, int c) {
        row = r;
        col = c;
    };
};

class Inicio {
public:
    static string pathFind(const Location &locStart, const Location &locFinish, window::Matriz m);
};


#endif //SFML_INICIO_H

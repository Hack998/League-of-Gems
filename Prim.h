//
// Created by samuel on 05/11/18.
//

#ifndef SFML_PRIM_H
#define SFML_PRIM_H

#include <string>
#include "window.h"

struct Lugar {
    int row, col, peso;

    Lugar() {
        row = col = peso = 0;
    };

    Lugar(int r, int c, int p) {
        row = r;
        col = c;
        peso = p;
    };
};

class Prim {
public:
    static string prim(const Lugar &locStart, const Lugar &locFinish, window::Matriz m);
};


#endif //SFML_PRIM_H

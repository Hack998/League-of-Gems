//
// Created by samuel on 05/11/18.
//

#ifndef SFML_KRUSKAL_H
#define SFML_KRUSKAL_H

#include <string>
#include "window.h"

struct nodo {
    int row, col, peso;

    nodo() {
        peso = 0;
        row = col = -1;
    };

    nodo(int r, int c, int p) {
        row = r;
        col = c;
        peso = p;
    };
};

class Kruskal {
public:
    static string kruskal(const nodo &locStart, const nodo &locFinish, window::Matriz m);

};


#endif //SFML_KRUSKAL_H

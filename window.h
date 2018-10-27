//
// Created by samuel on 16/10/18.
//

#ifndef SFML_WINDOW_H
#define SFML_WINDOW_H

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "soldado.h"
typedef soldado ejercito;
using namespace sf;
using namespace std;

class window {
public:
    typedef struct Matriz {
        int matriz_pos[23][43];
        Vector2f matriz_pixels[23][43];
    } matriz;

    void iniciar(int cant, string route);
    Matriz iniciar_matriz();
    bool ismove(ejercito *lo);
};


#endif //SFML_WINDOW_H

//
// Created by samuel on 16/10/18.
//

#ifndef SFML_WINDOW_H
#define SFML_WINDOW_H

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "soldado.h"
#include "Enemigo.h"

typedef soldado ejercito;
using namespace sf;
using namespace std;

class window {
public:
    typedef struct Matriz {
        int matriz_pos[23][43];
        Vector2f matriz_pixels[23][43];
    } matriz;

    int screen = 5;
    ejercito array_s[15];
    Enemigo em;

    void iniciar(int cant, string route);
    Matriz iniciar_matriz();
    bool ismove(ejercito *lo);
    int* buscarMouse ();
    void checkLines(int* lines, string* impresion);
    bool enemigoCerca(matriz* matriz,Enemigo* array_e, Enemigo* tempE, soldado* tempS, int cant);
    bool enemigoCerca(int matriz_pos[23][43], int i, int j);
    bool soldadoCerca(int matriz_pos[23][43], int i, int j);
    void validarAtaque(IntRect* rectSourceSprite, int attack);

};


#endif //SFML_WINDOW_H

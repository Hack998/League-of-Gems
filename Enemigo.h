//
// Created by pablo on 18/10/18.
//

#ifndef ENEMIGOS_ENEMIGO_H
#define ENEMIGOS_ENEMIGO_H

#include <string>
#include <iostream>
#include "soldado.h"

class Enemigo {

    typedef Enemigo E;

public:
    float vida = 0.0;
    float ataque = 0;

    float nivel = vida + ataque;

    int min = 2;
    int max = 5;
    int random = std::rand() % max + min;

    int min2 = 20;
    int max2 = 50;
    int random2 = std::rand() % max2 + min2;

public:

    Enemigo() {
        this->vida = 0;
        this->ataque = 0;
        this->nivel = vida + ataque;
    }

public:
    Enemigo(int vi, int at) {
        this->vida = vi;
        this->ataque = at;
        this->nivel = vi + at;
    };

    void atacar(soldado soldier){
        soldier.cuerpo.vida -= this->ataque;
    }

    E *crearPoblacion(int cantidad) {
        E enem[cantidad];
        E *mu = enem;
        for (int i = 0; i < cantidad; i++) {
            E enemigo = E(random2 = std::rand() % max2 + min2, random = std::rand() % max + min);
            enem[i] = enemigo;
        }
        return mu;
    }

    E *ordenarArray(int cantidad) { //se debe pasar el array como parametro
        E enem[cantidad];
        E temporal;
        E *mu = enem;
        for (int i = 0; i < cantidad; i++) {
            for (int j = 0; j < cantidad - 1; j++) {
                if ( enem[j].nivel < enem[j +
                                          1].nivel ) { // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                    temporal = enem[j];
                    enem[j] = enem[j + 1];
                    enem[j + 1] = temporal;
                }
            }
        }
        return mu;
    }

    E *eliminar_inservibles(int cantidad) {
        E enem[cantidad];
        E sobrevivientes[cantidad / 5];
        E *mu = sobrevivientes;
        for (int i = 0; i < cantidad / 5; ++i) {
            sobrevivientes[i] = enem[i];
        }
        return mu;
    }

    E *combinacion(int cantidad) {
        E sobrevivientes[cantidad / 5];
        E nuevaGen[cantidad];
        E *mu = nuevaGen;
        for (int i = 0; i < cantidad; i++) {
            E padre = sobrevivientes[random2 = std::rand() % cantidad / 5 + 0];
            E madre = sobrevivientes[random2 = std::rand() % cantidad / 5 + 0];
            E hijo;

            if ( padre.ataque < madre.ataque ) {
                hijo.ataque = madre.ataque + 2;
                if ( padre.vida < madre.vida ) {
                    hijo.vida = madre.vida + 2;
                } else {
                    hijo.vida = padre.vida + 2;
                }
            } else {
                hijo.ataque = padre.ataque + 2;
                if ( padre.vida < madre.vida ) {
                    hijo.vida = madre.vida + 2;
                } else {
                    hijo.vida = padre.vida + 2;
                }
            }
            nuevaGen[i] = hijo;
        }
        return mu;
    }
};

#endif //ENEMIGOS_ENEMIGO_H

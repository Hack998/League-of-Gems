//
// Created by samuel on 27/10/18.
//

#include "Inicio.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

const int IDIM = 23; // Horizontales.
const int JDIM = 43; // Verticales.
const int NDIR = 4; // Numero de posibles movimientos.

// si NDIR = 4
const int iDir[NDIR] = {1, 0, -1, 0};
const int jDir[NDIR] = {0, 1, 0, -1};

// si NDIR = 8
//const int iDir[NDIR] = {1, 1, 0, -1, -1, -1, 0, 1};
//const int jDir[NDIR] = {0, 1, 1, 1, 0, -1, -1, -1};

int squares[IDIM][JDIM];

// Lista de nodos cerrados.
int closedNodes[IDIM][JDIM];

// Lista de nodos abiertos.
int openNodes[IDIM][JDIM];

// mapa de dirreccion (0: Abajo, 1: Derecha, 2: Arriba, 3: Izquierda).
int dirMap[IDIM][JDIM];


class Node {
    // Posicion actual.
    int rPos;
    int cPos;

    // Distancia total recorrida.
    int GValue;

    // FValue = GValue + Distancia faltante estimada.
    int FValue;  // El mas pequeno FValue tiene prioridad.

public:
    Node(const Location &loc, int g, int f) {
        rPos = loc.row;
        cPos = loc.col;
        GValue = g;
        FValue = f;
    }

    Location getLocation() const {
        return Location(rPos, cPos);
    }

    int getGValue() const {
        return GValue;
    }

    int getFValue() const {
        return FValue;
    }

    void calculateFValue(const Location &locDest) {
        FValue = GValue + getHValue(locDest) * 10;
    }


    void updateGValue(const int &i) // i: Direccion.
    {
        GValue += (NDIR == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
    }

    // Funcion que estima la distancia que falta.
    const int &getHValue(const Location &locDest) const {
        static int rd, cd, d;
        rd = locDest.row - rPos;
        cd = locDest.col - cPos;
        d = abs(rd) + abs(cd);
        return (d);
    }

    // Determina FValue (en prioridad).
    friend bool operator<(const Node &a, const Node &b) {
        return a.getFValue() > b.getFValue();
    }
};

// Algoritmo A estrella.
// El path es las direccion que tiene que tomar para llegar al final.
string Inicio::pathFind(const Location &locStart, const Location &locFinish, window::Matriz m) {
    for (int i = 0; i <= 22; i++) {
        for (int j = 0; j <= 42; j++) {
            if ( m.matriz_pos[i][j] == -1 || m.matriz_pos[i][j] == 3 ) {
                squares[i][j] = 1;
            } else {
                squares[i][j] = 0;
            }
        }
    }
// Lista de nodos abiertos.
    static priority_queue<Node> q[2];

// q index.
    static int qi;

    static Node *pNode1;
    static Node *pNode2;
    static int i, j, row, col, iNext, jNext;
    static char c;
    qi = 0;

// Reinicia la listas de nodos.
    for (j = 0; j < JDIM; j++) {
        for (i = 0; i < IDIM; i++) {
            closedNodes[i][j] = 0;
            openNodes[i][j] = 0;
        }
    }

// Crea el nodo de inicio y lo pone en lista de nodos abietos.
    pNode1 = new Node(locStart, 0, 0);
    pNode1->calculateFValue(locFinish);
    q[qi].push(*pNode1);

// Busqueda A*.
    while (!q[qi].empty()) {
// Obtiene el nodo actual por el mas pequeño FValue de la lista de nodos abiertos.
        pNode1 = new Node(q[qi].top().getLocation(), q[qi].top().getGValue(), q[qi].top().getFValue());
        row = (pNode1->getLocation()).row;
        col = pNode1->getLocation().col;

// Remueve el nodo de la lista de nodos abiertos.
        q[qi].pop();

        openNodes[row][col] = 0;

// Marca el nodo como nodo cerrado.
        closedNodes[row][col] = 1;

// Para de buscar cuando se encuentra el nodo final.
        if ( row == locFinish.row && col == locFinish.col ) {

// Genera el path.
            string path = "";
            while (!(row == locStart.row && col == locStart.col)) {
                j = dirMap[row][col];
                c = '0' + (j + NDIR / 2) % NDIR;
                path = c + path;
                row += iDir[j];
                col += jDir[j];
            }

// Basura.
            delete pNode1;

// Libre nodos.
            while (!q[qi].empty())
                q[qi].pop();
            return path;
        }

// Genera movimientos en todos las direcciones posibles.
        for (i = 0; i < NDIR; i++) {
            iNext = row + iDir[i];
            jNext = col + jDir[i];

// Si no es un obstaculo o no esta en la lista de nodos cerrados.
            if ( !(iNext < 0 || iNext > IDIM - 1 || jNext < 0 || jNext > JDIM - 1 || squares[iNext][jNext] == 1 ||
                   closedNodes[iNext][jNext] == 1)) {

// Genera nodos hijos
                pNode2 = new Node(Location(iNext, jNext), pNode1->getGValue(), pNode1->getFValue());
                pNode2->updateGValue(i);
                pNode2->calculateFValue(locFinish);

// Si el nodo no esta en la lista de nodos abiertos, lo incerta.
                if ( openNodes[iNext][jNext] == 0 ) {
                    openNodes[iNext][jNext] = pNode2->getFValue();

                    q[qi].push(*pNode2);
// Crea la direccion del padre.
                    dirMap[iNext][jNext] = (i + NDIR / 2) % NDIR;
                }

// Esta en la lista de nodo libre.
                else if ( openNodes[iNext][jNext] > pNode2->getFValue()) {
// Actualiza la informacion de FValue.
                    openNodes[iNext][jNext] = pNode2->getFValue();

// Actualiza la informacion de la direccion del nodo padre.,  marca esta direccion del nodo padre.
                    dirMap[iNext][jNext] = (i + NDIR / 2) % NDIR;

// Remplaza el nodo
                    while (!(q[qi].top().getLocation().row == iNext && q[qi].top().getLocation().col == jNext)) {
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();
                    }

// Remueve el nodo buscardo.
                    q[qi].pop();

// Elimina del mas grande q hasta el mas pequeno.
                    if ( q[qi].size() > q[1 - qi].size())
                        qi = 1 - qi;
                    while (!q[qi].empty()) {
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();
                    }
                    qi = 1 - qi;

// Anade el mejor nodo.
                    q[qi].push(*pNode2);
                } else
                    delete pNode2;
            }
        }
        delete pNode1;
    }
// No se encontro el path.
    return "";
}
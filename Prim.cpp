//
// Created by samuel on 05/11/18.
//

#include "Prim.h"

int p = 5;
Lugar nodos[23][43];

#include "Prim.h"

void iniciar() {
    while (p < 985) {
        for (int i = 0; i <= 22; i++) {
            for (int j = 0; j <= 42; j++) {
                if ( nodos[i][j].peso == 1 ) {
                    if ( nodos[i + 1][j].peso == 0 && i + 1 != 23 ) {
                        nodos[i + 1][j] = Lugar(i, j, 1);
                        p++;
                    }
                    if ( nodos[i - 1][j].peso == 0 && i - 1 >= 0 ) {
                        nodos[i - 1][j] = Lugar(i, j, 1);
                        p++;
                    }
                    if ( nodos[i][j + 1].peso == 0 && j + 1 != 43 ) {
                        nodos[i][j + 1] = Lugar(i, j, 1);
                        p++;
                    }
                    if ( nodos[i][j - 1].peso == 0 && j - 1 >= 0 ) {
                        nodos[i][j - 1] = Lugar(i, j, 1);
                        p++;
                    }
                }
            }
        }
    }
}

string Prim::prim(const Lugar &locStart, const Lugar &locFinish, window::Matriz m) {
    p = 5;
    for (int i = 0; i <= 22; i++) {
        for (int j = 0; j <= 42; j++) {
            if ( m.matriz_pos[i][j] == -1 || m.matriz_pos[i][j] == 3 || m.matriz_pos[i][j] == 2 ) {
                nodos[i][j] = Lugar(-1, -1, -1);
                p++;
            } else {
                nodos[i][j] = Lugar(i, j, 0);
            }
        }
    }
    nodos[locStart.row][locStart.col] = Lugar(-2, -2, -2);
    if ( nodos[locStart.row - 1][locStart.col].peso != -1 )
        nodos[locStart.row - 1][locStart.col] = Lugar(locStart.row, locStart.col, 1);
    if ( nodos[locStart.row + 1][locStart.col].peso != -1 )
        nodos[locStart.row + 1][locStart.col] = Lugar(locStart.row, locStart.col, 1);
    if ( nodos[locStart.row][locStart.col - 1].peso != -1 )
        nodos[locStart.row][locStart.col - 1] = Lugar(locStart.row, locStart.col, 1);
    if ( nodos[locStart.row][locStart.col + 1].peso != -1 )
        nodos[locStart.row][locStart.col + 1] = Lugar(locStart.row, locStart.col, 1);

    iniciar();
    nodos[locStart.row][locStart.col].peso = 0;
    nodos[locFinish.row][locFinish.col].peso = -2;

    cout << "Prim" << endl;
    for (int i = 0; i <= 22; i++) {
        cout << "" << endl;
        for (int j = 0; j <= 42; j++) {
            cout << "(" << nodos[i][j].row << "," << nodos[i][j].col << ")" << ";";
        }
    }

    Lugar pos_2(locFinish.row, locFinish.col, 0);
    Lugar pos;
    string path1;
    while (nodos[pos_2.row][pos_2.col].peso != 0) {
        pos.row = nodos[pos_2.row][pos_2.col].row;
        pos.col = nodos[pos_2.row][pos_2.col].col;
        if ( pos.row > pos_2.row )
            path1 = "2" + path1;
        else if ( pos.row < pos_2.row )
            path1 = "0" + path1;
        else if ( pos.col > pos_2.col )
            path1 = "3" + path1;
        else
            path1 = "1" + path1;
        pos_2.row = pos.row;
        pos_2.col = pos.col;
        cout << "Row: " << pos_2.row << "; Col: " << pos_2.col << endl;
        cout << path1 << endl;
    }
    return path1;
}
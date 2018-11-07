//
// Created by samuel on 05/11/18.
//

#include "Kruskal.h"

int z = 5;
nodo familia[23][43];
int arista_derecha[23][43];
int arista_abajo[23][43];

void iniciar_kruskal() {
    while (z < 985) {
        cout << z << endl;
        for (int i = 0; i <= 22; i++) {
            for (int j = 0; j <= 42; j++) {
                if ( familia[i][j].peso == 1 ) {
                    if ( familia[i + 1][j].peso == 0 && i + 1 != 23 && arista_abajo[i][j] == 1 ) {
                        familia[i + 1][j] = nodo(i, j, 1);
                        z++;
                    }
                    if ( familia[i - 1][j].peso == 0 && i - 1 >= 0 && arista_abajo[i - 1][j] == 1 ) {
                        familia[i - 1][j] = nodo(i, j, 1);
                        z++;
                    }
                    if ( familia[i][j + 1].peso == 0 && j + 1 != 43 && arista_derecha[i][j] == 1 ) {
                        familia[i][j + 1] = nodo(i, j, 1);
                        z++;
                    }
                    if ( familia[i][j - 1].peso == 0 && j - 1 >= 0 && arista_derecha[i][j - 1] == 1 ) {
                        familia[i][j - 1] = nodo(i, j, 1);
                        z++;
                    }
                }
            }
        }
    }
}


string Kruskal::kruskal(const nodo &locStart, const nodo &locFinish, window::Matriz m) {
    z = 5;
    for (int i = 0; i <= 22; i++) {
        for (int j = 0; j <= 42; j++) {
            if ( m.matriz_pos[i][j] == 0 || m.matriz_pos[i][j] == 1 ) {
                if ( m.matriz_pos[i][j + 1] == 0 || m.matriz_pos[i][j + 1] == 1 ) {
                    arista_derecha[i][j] = 1;
                } else {
                    arista_derecha[i][j] = -1;
                    z++;
                }
                if ( m.matriz_pos[i + 1][j] == 0 || m.matriz_pos[i + 1][j] == 1 ) {
                    arista_abajo[i][j] = 1;
                } else {
                    arista_abajo[i][j] = -1;
                }
            } else {
                arista_derecha[i][j] = -1;
                arista_abajo[i][j] = -1;
            }
        }
    }

    cout << "Kruskal_aristas" << endl;
    for (int i = 0; i <= 22; i++) {
        cout << "" << endl;
        for (int j = 0; j <= 42; j++) {
            cout << "(" << arista_derecha[i][j] << "," << arista_abajo[i][j] << ")"
                 << ";";
        }
    }


    familia[locStart.row][locStart.col] = nodo(-2, -2, -2);
    if ( familia[locStart.row - 1][locStart.col].peso != -1 && arista_abajo[locStart.row][locStart.col] == 1 )
        familia[locStart.row - 1][locStart.col] = nodo(locStart.row, locStart.col, 1);
    if ( familia[locStart.row + 1][locStart.col].peso != -1 && arista_abajo[locStart.row][locStart.col] == 1 )
        familia[locStart.row + 1][locStart.col] = nodo(locStart.row, locStart.col, 1);
    if ( familia[locStart.row][locStart.col - 1].peso != -1 && arista_derecha[locStart.row][locStart.col] == 1 )
        familia[locStart.row][locStart.col - 1] = nodo(locStart.row, locStart.col, 1);
    if ( familia[locStart.row][locStart.col + 1].peso != -1 && arista_derecha[locStart.row][locStart.col] == 1 )
        familia[locStart.row][locStart.col + 1] = nodo(locStart.row, locStart.col, 1);

    iniciar_kruskal();
    familia[locStart.row][locStart.col].peso = 0;
    familia[locFinish.row][locFinish.col].peso = -2;

    cout << "Kruskal" << endl;
    for (int i = 0; i <= 22; i++) {
        cout << "" << endl;
        for (int j = 0; j <= 42; j++) {
            cout << "(" << familia[i][j].row << "," << familia[i][j].col << ")" << ";";
        }
    }
    nodo pos_2(locFinish.row, locFinish.col, 0);
    nodo pos;
    string path1;
    while (familia[pos_2.row][pos_2.col].peso != 0) {
        pos.row = familia[pos_2.row][pos_2.col].row;
        pos.col = familia[pos_2.row][pos_2.col].col;
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
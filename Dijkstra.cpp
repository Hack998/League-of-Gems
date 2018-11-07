//
// Created by samuel on 31/10/18.
//

#include "Dijkstra.h"

int d = 5;
int tabla[23][43];
int GValue;
int FValue;

void iniciar_prim() {
    int r = 1;
    while (d < 985) {
        for (int i = 0; i <= 22; i++) {
            for (int j = 0; j <= 42; j++) {
                if ( tabla[i][j] == r ) {
                    if ( tabla[i + 1][j] == 0 && i + 1 != 23 ) {
                        tabla[i + 1][j] = r + 1;
                        d++;
                    }
                    if ( tabla[i - 1][j] == 0 && i - 1 >= 0 ) {
                        tabla[i - 1][j] = r + 1;
                        d++;
                    }
                    if ( tabla[i][j + 1] == 0 && j + 1 != 43 ) {
                        tabla[i][j + 1] = r + 1;
                        d++;
                    }
                    if ( tabla[i][j - 1] == 0 && j - 1 >= 0 ) {
                        tabla[i][j - 1] = r + 1;
                        d++;
                    }
                }
            }
        }
        r++;
    }
}

const int &getHValue(const Posicion &locDest, const Posicion &locPos) {
    static int rd, cd, d;
    rd = locDest.row - locPos.row;
    cd = locDest.col - locPos.col;
    d = abs(rd) + abs(cd);
    return (d);
}

void calculateFValue(const Posicion &locDest, const Posicion &locPos) {
    FValue = GValue + getHValue(locDest, locPos) * 10;
}

string Dijkstra::dijkstra(const Posicion &locStart, const Posicion &locFinish, window::Matriz m) {
    d = 5;
    for (int i = 0; i <= 22; i++) {
        for (int j = 0; j <= 42; j++) {
            if ( m.matriz_pos[i][j] == -1 || m.matriz_pos[i][j] == 3 || m.matriz_pos[i][j] == 2) {
                tabla[i][j] = -1;
                d++;
            } else {
                tabla[i][j] = 0;
            }
        }
    }
    tabla[locStart.row][locStart.col] = -2;
    if ( tabla[locStart.row - 1][locStart.col] != -1 )
        tabla[locStart.row - 1][locStart.col] = 1;
    if ( tabla[locStart.row + 1][locStart.col] != -1 )
        tabla[locStart.row + 1][locStart.col] = 1;
    if ( tabla[locStart.row][locStart.col - 1] != -1 )
        tabla[locStart.row][locStart.col - 1] = 1;
    if ( tabla[locStart.row][locStart.col + 1] != -1 )
        tabla[locStart.row][locStart.col + 1] = 1;

    iniciar_prim();
    tabla[locStart.row][locStart.col] = 0;

    cout << "Dijkstra" << endl;
    for (int i = 0; i <= 22; i++) {
        cout << "" << endl;
        for (int j = 0; j <= 42; j++) {
            cout << tabla[i][j] << ",";
        }
    }

    Posicion pos_2(locFinish.row, locFinish.col);
    Posicion pos;
    string path1;
    while ( tabla[pos_2.row][pos_2.col] != 0 ) {
        if ( tabla[pos_2.row - 1][pos_2.col] == tabla[pos_2.row][pos_2.col] - 1) {
            pos.row = pos_2.row - 1;
            pos.col = pos_2.col;
        }
        if ( tabla[pos_2.row + 1][pos_2.col] == tabla[pos_2.row][pos_2.col] - 1 ) {
            pos.row = pos_2.row + 1;
            pos.col = pos_2.col;
        }
        if ( tabla[pos_2.row][pos_2.col - 1] == tabla[pos_2.row][pos_2.col] - 1) {
            pos.row = pos_2.row;
            pos.col = pos_2.col - 1;
        }
        if ( tabla[pos_2.row][pos_2.col + 1] == tabla[pos_2.row][pos_2.col] - 1) {
            pos.row = pos_2.row;
            pos.col = pos_2.col + 1;
        }
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
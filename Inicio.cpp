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

const int IDIM = 23; // horizontal size of the squares
const int JDIM = 43; // vertical size size of the squares
const int NDIR = 4; // number of possible directions to go at any position

// if NDIR = 4
const int iDir[NDIR] = {1, 0, -1, 0};
const int jDir[NDIR] = {0, 1, 0, -1};

// if NDIR = 8
//const int iDir[NDIR] = {1, 1, 0, -1, -1, -1, 0, 1};
//const int jDir[NDIR] = {0, 1, 1, 1, 0, -1, -1, -1};

int squares[IDIM][JDIM];

// list of closed (check-out) nodes
int closedNodes[IDIM][JDIM];

// list of open (not-yet-checked-out) nodes
int openNodes[IDIM][JDIM];

// map of directions (0: East, 1: North, 2: West, 3: South)
int dirMap[IDIM][JDIM];


class Node {
    // current position
    int rPos;
    int cPos;

    // total distance already travelled to reach the node
    int GValue;

    // FValue = GValue + remaining distance estimate
    int FValue;  // smaller FValue gets priority

public:
    Node(const Location &loc,
         int g,
         int f
    ) {
        rPos = loc.row;
        cPos = loc.col;
        GValue = g;
        FValue = f;
    }

    Location getLocation() const { return Location(rPos, cPos); }

    int getGValue() const { return GValue; }

    int getFValue() const { return FValue; }

    void calculateFValue(const Location &locDest) {
        FValue = GValue + getHValue(locDest) * 10;
    }


    void updateGValue(const int &i) // i: direction
    {
        GValue += (NDIR == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
    }

    // Estimation function for the remaining distance to the goal.
    const int &getHValue(const Location &locDest) const {
        static int rd, cd, d;
        rd = locDest.row - rPos;
        cd = locDest.col - cPos;

        // Euclidian Distance
        // d = static_cast<int>(sqrt((double)(rd*rd+cd*cd)));

        // Manhattan distance
        d = abs(rd) + abs(cd);

        // Chebyshev distance
        //d = max(abs(rd), abs(cd));

        return (d);
    }

    // Determine FValue (in the priority queue)
    friend bool operator<(const Node &a, const Node &b) {
        return a.getFValue() > b.getFValue();
    }
};

// A-star algorithm.
// The path returned is a string of direction digits.
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
// list of open (not-yet-checked-out) nodes
    static priority_queue<Node> q[2];

// q index
    static int qi;

    static Node *pNode1;
    static Node *pNode2;
    static int i, j, row, col, iNext, jNext;
    static char c;
    qi = 0;

// reset the Node lists (0 = ".")
    for (j = 0; j < JDIM; j++) {
        for (i = 0; i < IDIM; i++) {
            closedNodes[i][j] = 0;
            openNodes[i][j] = 0;
        }
    }

// create the start node and push into list of open nodes
    pNode1 = new Node(locStart, 0, 0);
    pNode1->calculateFValue(locFinish);
    q[qi].push(*pNode1);

// A* search
    while (!q[qi].empty()) {
// get the current node w/ the lowest FValue
// from the list of open nodes
        pNode1 = new Node(q[qi].top().getLocation(), q[qi].top().getGValue(), q[qi].top().getFValue());
        row = (pNode1->getLocation()).row;
        col = pNode1->getLocation().col;

// remove the node from the open list
        q[qi].pop();

        openNodes[row][col] = 0;

// mark it on the closed nodes list
        closedNodes[row][col] = 1;

// stop searching when the goal state is reached
        if ( row == locFinish.row && col == locFinish.col ) {

// generate the path from finish to start from dirMap
            string path = "";
            while (!(row == locStart.row && col == locStart.col)) {
                j = dirMap[row][col];
                c = '0' + (j + NDIR / 2) % NDIR;
                path = c + path;
                row += iDir[j];
                col += jDir[j];
            }

// garbage collection
            delete pNode1;

// empty the leftover nodes
            while (!q[qi].empty())
                q[qi].pop();
            return path;
        }

// generate moves in all possible directions
        for (i = 0; i < NDIR; i++) {
            iNext = row + iDir[i];
            jNext = col + jDir[i];

// if not wall (obstacle) nor in the closed list
            if ( !(iNext < 0 || iNext > IDIM - 1 || jNext < 0 || jNext > JDIM - 1 || squares[iNext][jNext] == 1 ||
                   closedNodes[iNext][jNext] == 1)) {

// generate a child node
                pNode2 = new Node(Location(iNext, jNext), pNode1->getGValue(), pNode1->getFValue());
                pNode2->updateGValue(i);
                pNode2->calculateFValue(locFinish);

// if it is not in the open list then add into that
                if ( openNodes[iNext][jNext] == 0 ) {
                    openNodes[iNext][jNext] = pNode2->getFValue();

                    q[qi].push(*pNode2);
// mark its parent node direction
                    dirMap[iNext][jNext] = (i + NDIR / 2) % NDIR;
                }

// already in the open list
                else if ( openNodes[iNext][jNext] > pNode2->getFValue()) {
// update the FValue info
                    openNodes[iNext][jNext] = pNode2->getFValue();

// update the parent direction info,  mark its parent node direction
                    dirMap[iNext][jNext] = (i + NDIR / 2) % NDIR;

// replace the node by emptying one q to the other one
// except the node to be replaced will be ignored
// and the new node will be pushed in instead
                    while (!(q[qi].top().getLocation().row == iNext && q[qi].top().getLocation().col == jNext)) {
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();
                    }

// remove the wanted node
                    q[qi].pop();

// empty the larger size q to the smaller one
                    if ( q[qi].size() > q[1 - qi].size())
                        qi = 1 - qi;
                    while (!q[qi].empty()) {
                        q[1 - qi].push(q[qi].top());
                        q[qi].pop();
                    }
                    qi = 1 - qi;

// add the better node instead
                    q[qi].push(*pNode2);
                } else
                    delete pNode2;
            }
        }
        delete pNode1;
    }
// no path found
    return "";
}
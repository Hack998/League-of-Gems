//
// Created by davepj007 on 28/10/18.
//

#ifndef SFML_ATAQUE_H
#define SFML_ATAQUE_H


class Ataque {
    int power;

    int punch(int life);
    int uppercut(int life);
    int fastPunch(int life);
    int kick(int life);
    int fastKick(int life);
    int reverseKick(int life);
    int knife(int life);
    int hammer(int life);
    int sword(int life);
    int arrow(int life);
};


#endif //SFML_ATAQUE_H

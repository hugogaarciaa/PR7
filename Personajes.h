#pragma once
#include <iostream>

using namespace std;

class Personajes {
private:
    string name;
    int hp;
    int hab1;
    int hab2;
    int hab3;
    int posX;
    int posY;
    bool alive;

public:
    // CONSTRUCTORES
    Personajes(string pName, int pHp, int phab1, int phab2, int phab3, int pPosX, int pPosY, bool pAlive);

    Personajes(int pHp, int phab1, int phab2, bool pAlive);

    Personajes();

    // GETTERS
    string gettName();
    int gettHp();
    int gettHab1();
    int gettHab2();
    int gettHab3();
    int gettPosX();
    int gettPosY();
    bool gettAlive();

    // SETTERS
    void settHp(int pHp);
    void settPosX(int pPosX);
    void settPosY(int pPosY);
    void settAlive(bool pAlive);
};
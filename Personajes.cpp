#include "personajes.h"
#include <iostream>

using namespace std;


Personajes::Personajes(string pName, int pHp, int phab1, int phab2, int phab3, int pPosX, int pPosY, bool pAlive) {
    name = pName;
    hp = pHp;
    hab1 = phab1;
    hab2 = phab2;
    hab3 = phab3;
    posX = pPosX;
    posY = pPosY;
    alive = pAlive;
}

// Constructor sin parámetros
Personajes::Personajes() {
    name = "";
    hp = 0;
    hab1 = 0;
    hab2 = 0;
    hab3 = 0;
    posX = 0;
    posY = 0;
    alive = false;
}

// Constructor con parámetros parciales
Personajes::Personajes(int pHp, int phab1, int phab2, bool pAlive) {
    name = "";
    hp = pHp;
    hab1 = phab1;
    hab2 = phab2;
    hab3 = 0;
    posX = 0;
    posY = 0;
    alive = pAlive;
}

// Métodos getters
string Personajes::gettName() {
    return name;
}

int Personajes::gettHp() {
    return hp;
}

int Personajes::gettHab1() {
    return hab1;
}

int Personajes::gettHab2() {
    return hab2;
}

int Personajes::gettHab3() {
    return hab3;
}

int Personajes::gettPosX() {
    return posX;
}

int Personajes::gettPosY() {
    return posY;
}

bool Personajes::gettAlive() {
    return alive;
}

// Métodos setters
void Personajes::settHp(int pHp) {
    hp = pHp;
}

void Personajes::settPosX(int pPosX) {
    posX = pPosX;
}

void Personajes::settPosY(int pPosY) {
    posY = pPosY;
}

void Personajes::settAlive(bool pAlive) {
    alive = pAlive;
}
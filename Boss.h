#pragma once
#include "Enemigos.h"
class Boss : public Enemigos
{
private:
	int superHab;
	int def;
public:
	Boss(int pHp, int pDef, int superHab, int hab1, bool pAlive);

	int gettDef();
	int gettSuperHab();
};


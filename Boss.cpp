#include "Boss.h"

Boss::Boss(int pHp, int pDef, int pSuperHab, int pHab1, bool pAlive) : Enemigos(pHp, pHab1, pAlive) {
	def = pDef;
	superHab = pSuperHab;
}

int Boss::gettSuperHab() {
	return superHab;
}
int Boss::gettDef() {
	return def;
}
#include "HacksawRidge.h"


HacksawRidge::HacksawRidge(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d,int health) :Enemy(r_region, firep, arrivalt, reloadp, st, d,health){
	Clr=GREENYELLOW;
	type='q';

}

HacksawRidge::~HacksawRidge(){
}

void HacksawRidge::Attack(){
	dmg=0;
}
void HacksawRidge::Move(){
	if (Distance > MinDistance){
		Distance--;}
}

void HacksawRidge::calprio(){
}
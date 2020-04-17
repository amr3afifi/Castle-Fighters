#include "HacksawRidges.h"

HacksawRidges::HacksawRidges(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d,int health) :Enemy(r_region, firep, arrivalt, reloadp, st, d,health){
	Clr=GREENYELLOW;
	type='q';

}

HacksawRidges::~HacksawRidges(){
}

void HacksawRidges::Attack(){
	dmg=0;
}
void HacksawRidges::Move(){
	if (Distance > MinDistance){
		Distance--;}
}

void HacksawRidges::calprio(){
}

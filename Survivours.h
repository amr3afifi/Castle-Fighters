#pragma once
#include "Enemies\Enemy.h"
class Survivours :
	public Enemy
{
public:
Survivours(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d);
void Attack();
void Move();
~Survivours();
void decreasehealth(double damage,int timestep);
void calprio();
};

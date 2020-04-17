#pragma once
#include "Enemy.h"
class SFighter :public Enemy
{
	double c1; double c2; double c3;
public:
	SFighter(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d,int x , int y, int z);
	char gettype();
	void Attack();
	void Move();
	~SFighter();
};


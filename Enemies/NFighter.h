#pragma once
#include "Enemy.h"
class NFighter :public Enemy
{
	int prio;
public:
	NFighter(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d);
	void Attack();
	void Move();
	~NFighter();
};


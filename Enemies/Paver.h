#pragma once
#include "Paver.h"
#include "Enemy.h"
class Paver :public Enemy
{

public:
	Paver(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d);
	char gettype();
	void Attack();
	void Move();
	~Paver();
};


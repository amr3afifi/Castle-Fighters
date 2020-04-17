#pragma once
#include "Enemies\Enemy.h"

class HacksawRidges :public Enemy
{
	public:
		HacksawRidges (REGION r_region, double firep, double arrivalt, double reloadp, char st, int d,int health);
		void Attack();
		void Move();
		~HacksawRidges();
		void calprio();
};


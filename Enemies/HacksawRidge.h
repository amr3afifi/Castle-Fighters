#pragma once
#include"Enemy.h"

class HacksawRidge :public Enemy
{
	public:
		HacksawRidge (REGION r_region, double firep, double arrivalt, double reloadp, char st, int d,int health);
		void Attack();
		void Move();
		~HacksawRidge();
		void calprio();
};
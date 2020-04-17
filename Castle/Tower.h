#pragma once

#include "../Enemies/Enemy.h"
#include"../List.h"

class Tower
{
	
	double Health;
	double reloadperiod;
	REGION region;
	int unpaveddis;
	char state;
	//
	// TODO: Add More Data Members As Needed
	//
	int numbercanshoot;
	bool paved[60];

	/*Arrival Time stamp(Enemy Arrival Time) : When the enemy arrives.*/

public:
	Tower();
	int getunpaved();
	int firepower;
	void setnumberofshoot(int a);
	Tower(REGION g,double h,int t,double reload,int ni);
	void Attack(list &a,int N);
	void SetHealth(double h);
	void DecrementHealth(double h);
	double GetHealth() const;
	char getstate();
	int getN();
	REGION getregion();
	float getDamage(Enemy*A);
	void setfirepower(int g);
	//
	// TODO: Add More Member Functions As Needed
	//
	
	int getfirepower();
	bool checkpaved(int dis);
	void pave(int dis, double fp);

};


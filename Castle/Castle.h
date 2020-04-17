#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"

class Castle
{
	Tower* Towers[NoOfRegions];
	int health;
	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	void SetTowersHealth(double h);
	void SetTowerfirepower(int a);
	void setnumberof(int a);
	Tower*& returntower(int a);
	int gethealth();
	//
	// TODO: Add More Member Functions As Needed
	//
	void pave(REGION r,int dis,double fp);
	bool  checkpaved(REGION r, int dis);
};

#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include <fstream>
#include"DS\Queue.h"
// it is the controller of the project
class Battle
{
private:
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	//
	// TODO: Add More Data Members As Needed
	//
	double currenttime;
	double battletime;
	int deadenemies;
	int activeenemies;
	int deadtowers;
	int activetowers;
	int killed;

public:
	
	Battle();
	void AddEnemy(Enemy* Ptr);
	void DrawEnemies(GUI * pGUI);
	void Updateinterface();
	Castle & GetCastle();
	bool checkkill(REGION a);
	int countregion(REGION a);
	void killregion(REGION a);
	//
	// TODO: Add More Member Functions As Needed
	//
	void putqueue(Queue& A,Enemy* E);
	void activateenemies(int TimeStep);
	void load(Queue& A,Queue& B,Queue& C,Queue& D,GUI*PGUI);
	void DecrementDist();
	void print(list Alist,list Blist, list Clist,list Dlist,list killed,Castle A,GUI*pGUI);
	int deadregion(REGION a);
	void putqueue(Queue& a,REGION& SR);
	void kill(list& killlist,list &gq,list& h);
	int ckill();
	void Print();
	void Migrate(Castle A,list&a,list&b,int c,int d);
	void Attack(list &B,Castle A,list&killed,int timestep,int a);
	void outputfile(list killed);
	void pave();
	void move();

	
};


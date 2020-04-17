#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

// Enemy is the base class of each type of enemy
// Enemy is an abstract class.
class Enemy
{

protected:
	int ID;  //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	//
	// TODO: Add More Data Members As Needed
	//
	double firepower;
	float dmg;
	int arrivaltime;
	int reloadperiod;
	int killingtime;
	int firstshotdelay;
	int killdelay;
	int lifetime;
	int tfirstshot;
	double prio; //priority
	char state;  //k for killed, a for active, i for inactive
	char type;
	int realtime;
public:
	Enemy();
	Enemy(REGION r_region,double firep,double arrivalt,double reloadp,char st= 'i',int d = MaxDistance,int health=100);
	virtual ~Enemy();

	color GetColor() const;
	REGION GetRegion() const;
	void DecrementDist();
	void incrementhealth(int a);
	void realtimeinc();
		void setKT(int d);
	void setFD(int g);
	void setKD(int k);
	void setLT(int y);
	void setTFshot(int d);
	int getKT();
	int getFD();
	int getKD();
	int getLT();
	int getTFshot();
	void setprio(int g);
	void SetDistance(int d);
	int GetDistance() const;
	char gettype();
	void Print();
	// Virtual Functions: ----------------

	virtual void Move() = 0;	    //All enemies can move
	virtual void Attack() = 0;

	//
	// TODO: Add More Member Functions As Needed
	//
	double getarrivaltime() const;
	void decreasehealth(double d,int s);
	void setregion(REGION N);
	double getpriority()const;
	int getid()const;
	void setid(int g);
	double gethealth() const;
	double getreloadperiod()const;
	void setstate(char c);
	char getstate()const;
	double getfirepower()const;
	float getdmg();

};


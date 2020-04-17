#include "Enemy.h"
#include<iostream>
using namespace std;
Enemy::Enemy()
{
}

Enemy::Enemy(REGION r_region, double firep, double arrivalt, double reloadp,char st, int d,int health)
{
	Region = r_region;
	Health = health;
	firepower = firep;
	arrivaltime = arrivalt;
	reloadperiod = reloadp;
	state = st;
	SetDistance(d);
	realtime=0;
}

Enemy::~Enemy()
{
}
void Enemy::incrementhealth(int h)
{
	Health+=h;
}
void Enemy::Print()
{
	cout<<" type= "<<type<<" KTS ="<<killingtime<<" FD = "<<firstshotdelay<<" ID = "<<ID<<endl;
}
void Enemy::setprio(int g)
{
	prio=g;
}
void Enemy::setid(int g)
{
	ID=g;
}
color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
}

void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}

double Enemy::getarrivaltime() const
{
	return arrivaltime;
}

void Enemy::setFD(int g)
{
	firstshotdelay=g;
}
void Enemy::setKD(int h)
{
	killdelay=h;
}
void Enemy::setLT(int h)
{
	lifetime=h;
}
void Enemy::setKT(int h)
{
	killingtime=h;
}
void Enemy::setTFshot(int a)
{
	tfirstshot=a;
}
int Enemy::getFD()
{
	return firstshotdelay;
}
int Enemy::getKD()
{
	return killdelay;
}
int Enemy::getLT()
{
	return lifetime;
}
int Enemy::getKT()
{
	return killingtime;
}
int Enemy::getTFshot()
{
	return tfirstshot;
}
void Enemy::decreasehealth(double d,int timestep)
{
	if(Health>0)
	{
	Health -= d;
	if((double)Health<=0.000000000)
	{
		Health=0;
		state='k';
		PlaySound("starlord.wav", NULL,SND_FILENAME|SND_ASYNC);
		killingtime=timestep;
		killdelay=killingtime-tfirstshot;
		lifetime=killingtime-arrivaltime;
	}
	}
}
double Enemy::gethealth() const
{
	return Health;
}

void Enemy::setregion(REGION N)
{
	Region = N;
}

double Enemy::getpriority() const
{
	return prio;
}

int Enemy::getid() const
{
	return ID;
}

double Enemy::getreloadperiod() const
{
	return reloadperiod;
}

void Enemy::setstate(char c)
{
	state = c;
	if (state=='k')
		 Health=0;
}

char Enemy::getstate()const
{
	return state;
}

double Enemy::getfirepower()const
{
	return firepower;
}
char Enemy::gettype()
{
	return type;
}

void Enemy:: realtimeinc(){
		realtime++;
}

float Enemy::getdmg(){
return dmg;	}


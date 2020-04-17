#include "Tower.h"
#include"../Enemies/Enemy.h"
#include"../List.h"
Tower::Tower()
{
}
int Tower::getfirepower()
{
	return firepower;
}
Tower::Tower(REGION a,double health,int firepowers,double reloadperiods,int n)
{
	unpaveddis=30;
	region=a;
	Health=health;
	firepower=firepowers;
	reloadperiod=reloadperiods;
	numbercanshoot=n;
	state='a';
	for(int i=0;i<30;i++){
	
		paved[i]=false;
	
	
	}
	for(int i=30;i<61;i++){
	
		paved[i]=true;
	
	
	}


}
void Tower::setnumberofshoot(int a)
{
	numbercanshoot=a;
}
int Tower::getunpaved()
{
	return unpaveddis;
}
void Tower::setfirepower(int a)
{
	firepower=a;
}
REGION Tower::getregion()
{
	return region;
}
float Tower::getDamage(Enemy*ptr)
{
	int k=0;
	if(ptr->gettype()=='s')
	{
		k=2;
	}
	else
	{
		k=1;
	}
	float c=((1/(float)ptr->GetDistance()))*(float)(firepower)*(1.0/(float)k);
	return c;
}
int Tower::getN()
{
	return numbercanshoot;
}
char Tower::getstate()
{
	return state;
}
void Tower::DecrementHealth(double h)
{
	if(Health>0)
	{
	Health=Health-h;
	if((double)Health<=0.00000000)
	{
		Health=0;
		PlaySound("ironman.wav",NULL,SND_FILENAME|SND_ASYNC);
		state='k';
	}
	}
}
void Tower::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Tower::GetHealth() const
{
	return Health;
}

bool Tower::checkpaved(int dis){

return paved[dis+1];

}


void Tower::pave(int dis, double fp){
	for(int i=(dis-fp); i<(dis+1); i++){
	unpaveddis--;
	paved[i]=true;
	}


}
#include "Survivours.h"




Survivours::Survivours(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d) :Enemy(r_region,firep,arrivalt,reloadp,st, d)
{
	Clr = YELLOWGREEN;
	type = 'sr';
}

Survivours::~Survivours(){
}

void Survivours::calprio(){

}
void Survivours::decreasehealth(double damage,int timestep){
	if(Health>0){
	Health=Health-damage;
	Health=Health+(Health-damage)/2;
	firepower=firepower/2;
	}
	if(Health<0.000000000000){
		state='k';
		PlaySound("starlord.wav", NULL,SND_FILENAME|SND_ASYNC);
		killingtime=timestep;
		killdelay=killingtime-tfirstshot;
		lifetime=killingtime-arrivaltime;
	}
}

void Survivours::Attack(){
if((realtime-arrivaltime)%(reloadperiod+1)==0){
	dmg=(1.0/(float)(Distance))*(float)(firepower);
	return;

      }
}

void Survivours:: Move(){
	if (Distance > MinDistance){
		Distance--;}
}

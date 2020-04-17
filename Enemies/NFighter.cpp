#include "NFighter.h"


NFighter::NFighter(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d) :Enemy(r_region, firep, arrivalt, reloadp, st, d)
{
	Clr = DARKOLIVEGREEN;
	type = 'n';
	prio = MaxDistance - arrivaltime;
	dmg=0;
}
NFighter::~NFighter()
{
}


void NFighter::Attack(){
	if(realtime==arrivaltime){
	
	dmg=(1.0/(float)(Distance))*(float)(firepower);
	return;
	}

	if((realtime-arrivaltime)%(reloadperiod+1)==0){
	dmg=(1.0/(float)(Distance))*(float)(firepower);
	return;
	}

	dmg=0;
	return;
}
void NFighter:: Move(){
	if (Distance > MinDistance){
		Distance--;}


}
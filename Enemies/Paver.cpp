#include "Paver.h"
#include "Paver.h"


Paver::Paver(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d) :Enemy(r_region, firep, arrivalt, reloadp, st, d)
{
	Clr = DARKBLUE;
	type = 'p';
	prio = MaxDistance - arrivaltime;
	dmg=0;
}
Paver::~Paver()
{
}
void Paver::Attack()
{
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
void Paver:: Move(){
	if (Distance > MinDistance){
		Distance--;}


}
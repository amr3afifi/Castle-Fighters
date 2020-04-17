#include "SFighter.h"


SFighter::SFighter(REGION r_region, double firep, double arrivalt, double reloadp, char st, int d,int x , int y, int z) :Enemy(r_region,firep,arrivalt,reloadp,st, d)
{
	Clr = ORANGERED;
	type = 's';
	if(x>0)
	c1=x;
	if(y>0)
	c2=y;
	if(z>0)
	c3=z;
	double p1 = (firepower / Distance)*c1;
	double p2 = (c2 /(reloadperiod+1));
	double p3 = Health*c3;
	prio = p1 + p2 + p3;
	dmg=0;

}
SFighter::~SFighter()
{
}
void SFighter::Attack(){
	if(realtime==arrivaltime){
	
	dmg=(2.0/(float)(Distance))*(float)(firepower);
	return;
	
	}
	if((realtime-arrivaltime)%(reloadperiod+1)==0){
	dmg=(2.0/(float)(Distance))*(float)(firepower);
	return;
	}
	dmg=0;
	return;




}
void SFighter:: Move(){
	if (Distance > MinDistance){
		Distance--;}


}


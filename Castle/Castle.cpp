#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
	Tower* A1=new Tower(A_REG,200,50,0,1);
	Tower* B1=new Tower(B_REG,200,50,0,1);
	Tower *C1=new Tower(C_REG,200,50,0,1);
	Tower *D1=new Tower(D_REG,200,50,0,1);
	Towers[0]=A1; Towers[1]=B1; Towers[2]=C1; Towers[3]=D1;
}
Tower*& Castle::returntower(int a)
{
	return Towers[a];
}
int Castle::gethealth()
{
	return health;
}
void Castle::SetTowersHealth(double h)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i]->SetHealth(h);
	}
	health=h;
}
void Castle::SetTowerfirepower(int a)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i]->setfirepower(a);
	}
}
void Castle:: pave(REGION r,int dis,double fp){
for (int i = 0; i < NoOfRegions; i++)
	{
		if(Towers[i]->getregion()==r){
		
	Towers[i]->pave(dis,fp);
		
		
		}
	}}

void Castle::setnumberof(int a)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i]->setnumberofshoot(a);
	}
}
bool Castle:: checkpaved(REGION r, int dis){

	for (int i = 0; i < NoOfRegions; i++)
	{
		if(Towers[i]->getregion()==r){
		
		return(Towers[i]->checkpaved(dis));
		
		
		}
	}}
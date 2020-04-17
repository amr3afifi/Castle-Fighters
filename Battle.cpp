#include "Battle.h"
#include <fstream>
#include "Enemies\Enemy.h"
#include "Enemies\Paver.h"
#include "Enemies\NFighter.h"
#include "Enemies\SFighter.h"
#include "HacksawRidges.h"
#include "Survivours.h"
#include <cstdlib>
#include <MMSystem.h>
#include<playsoundapi.h>
#include<iostream>
using namespace std;
#include "List.h"
Battle::Battle()
{
	EnemyCount = 0;
	killed=0;
}

void Battle::AddEnemy(Enemy* Ptr)
{
	if (EnemyCount < MaxEnemyCount) 
		BEnemiesForDraw[EnemyCount++] = Ptr;
	BEnemiesForDraw[EnemyCount-1]->setid(EnemyCount-1);

	// Note that this function doesn't allocate any enemy objects
	// It only makes the first free pointer in the array
	// points to what is pointed to by the passed pointer Ptr
}
void Battle::Updateinterface()
{
	for (int i = 0; i<EnemyCount; i++)
	{
		if (BEnemiesForDraw[i]->gethealth()<=0)
		{
			BEnemiesForDraw[i] = NULL;
			BEnemiesForDraw[i] = BEnemiesForDraw[EnemyCount - 1];
			BEnemiesForDraw[EnemyCount - 1] = NULL;
			BEnemiesForDraw;
		}
	}
}
void Battle::DrawEnemies(GUI * pGUI)
{
	pGUI->DrawEnemies(BEnemiesForDraw, EnemyCount);
}
int Battle::countregion(REGION a)
{
	int count=0;
	for(int i=0;i<EnemyCount;i++){
	
		if(BEnemiesForDraw[i]->getstate()=='a' && BEnemiesForDraw[i]->GetRegion()==a){
		
			count++;
		}
	}
	return count;
}
Castle & Battle::GetCastle()
{
	return BCastle;
}

void Battle::activateenemies(int TimeStep)
{

	for (int i = 0; i < EnemyCount; i++)

	{
		BEnemiesForDraw[i]->realtimeinc();
		if(BEnemiesForDraw[i]->getarrivaltime()==TimeStep && BEnemiesForDraw[i]->getstate()!='k'){
		BEnemiesForDraw[i]->setstate('a');
	
	}
	
	
	 }
}

void Battle::load(Queue& A,Queue& B,Queue& C,Queue& D,GUI * pGUI){
ifstream load;
Point p;
string l;
pGUI->PrintMessage("enter file name");
pGUI->GetPointClicked(p);
l=pGUI->GetString();
pGUI->ClearStatusBar();
load.open(l+".txt", ios::in);

if (!load) {pGUI->PrintMessage("not found ya habiby");}

int health;
int tfp;
string type;
REGION SR;
int region;
double firep, arrivalt, reloadp;
char st;
int c1;
int c2;
int c3;
int d;
int numbercanshoot;
load>>health>>tfp>>c1>>c2>>c3>>numbercanshoot;
Enemy* E;

GetCastle().SetTowersHealth(health);
GetCastle().SetTowerfirepower(tfp);
GetCastle().setnumberof(numbercanshoot);
while(!load.eof()){
load>>type>>region>>firep>>arrivalt>>reloadp>>st>>d>>health;
 if(region==0)
	 SR=A_REG;
 if(region==1)
	 SR=B_REG;
 if(region==2)
	 SR=C_REG;
 if(region==3)
	 SR=D_REG;
 if (type=="Paver")
	 E=new Paver(SR,firep,arrivalt,reloadp,st,d);
 if (type=="NFighter")
	 E=new NFighter(SR,firep,arrivalt,reloadp,st,d);
 if (type=="SFighter")
	 E=new SFighter(SR,firep,arrivalt,reloadp,st,d,c1,c2,c3);
 if (type=="HacksawRidge")
	 E=new HacksawRidges(SR,firep,arrivalt,reloadp,st,d,health);
 if (type=="Survivour")
	 E=new Survivours(SR,firep,arrivalt,reloadp,st,d);
if(SR==A_REG)
	putqueue(A,E);
 if(SR==B_REG)
	 putqueue(B,E);
 if(SR==C_REG)
	 putqueue(C,E);
 if(SR==D_REG)
	 putqueue(D,E);
 AddEnemy(E);}}




void Battle::DecrementDist(){
	for(int i=0;i<EnemyCount;i++){
	
		if(BEnemiesForDraw[i]->getstate()=='a'){
		
			BEnemiesForDraw[i]->DecrementDist();
		}
	}
}

void Battle::putqueue(Queue& A,Enemy* E){
	
	A.enqueue(E);

}

void Battle::kill(list& killlist,list& gA,list& sheildA){
	if(killed==4) return;

	 int i=-1;
while(i<0 ||i>(EnemyCount-1)){
	
	i=rand();
}
		

if(BEnemiesForDraw[i]->gettype()=='p'||BEnemiesForDraw[i]->gettype()=='n')
{
bool b=gA.remove(BEnemiesForDraw[i]);
if(b)
{killed++; killlist.insert(BEnemiesForDraw[i]); BEnemiesForDraw[i]->setstate('k');}

}
else if(BEnemiesForDraw[i]->gettype()=='s')
{
bool a=sheildA.remove(BEnemiesForDraw[i]);
if(a)
{
	killed++; killlist.insert(BEnemiesForDraw[i]); BEnemiesForDraw[i]->setstate('k');
}
}
}


int  Battle:: ckill(){
	int c=0;
	for(int i=0;i<EnemyCount;i++){
	
		if(BEnemiesForDraw[i]->getstate()=='k'){
			c++;
		}
	}

	return c;
}
void Battle::Migrate(Castle A,list&a,list&b,int c,int d)
{
	if(A.returntower(c)->getstate()=='k')
	{
		if(a.isEmpty()==false)
		{
			Node*ptr=a.gethead();
			while(ptr)
			{
					ptr->getItem()->setregion(A.returntower(d)->getregion());
				if(A.returntower(d)->checkpaved(ptr->getItem()->GetDistance()+1)==false && ptr->getItem()->GetDistance()<30)
				{
					int dis=30;
					while(A.returntower(d)->checkpaved(dis)==true)
					{
						dis--;
					}
					ptr->getItem()->SetDistance(dis);
				}
				ptr->getItem()->setregion(A.returntower(d)->getregion());
				a.remove(ptr->getItem());
				b.insert(ptr->getItem());
				ptr=ptr->getNext();
			}
		}
	}
}
void Battle::print(list Alist,list Blist, list Clist,list Dlist,list killed,Castle A,GUI*pGUI)
{
	pGUI->DrawString(15, 510, "Region A:");
	pGUI->DrawString(355, 510, "Region B:");
	pGUI->DrawString(695, 510, "Region C:");
	pGUI->DrawString(1035, 510, "Region D:");
	double towerAhealth=A.returntower(0)->GetHealth();
	double towerBhealth=A.returntower(1)->GetHealth();
	double towerChealth=A.returntower(2)->GetHealth();
	double towerDhealth=A.returntower(3)->GetHealth();
	double Array[4]={towerAhealth,towerBhealth,towerChealth,towerDhealth};
	int count=0;
	for (int i = 0; i < 1360; i += 340)
	{
		pGUI->DrawString(15 + i, 535, "Tower Health - " + to_string(Array[count]));
		count++;
	}

	int ActEnA = Alist.getLength();
	int ActEnB = Blist.getLength();
	int ActEnC = Clist.getLength();
	int ActEnD = Dlist.getLength();
	int KilledEnA = deadregion(A_REG);
	int KilledEnB = deadregion(B_REG);
	int KilledEnC = deadregion(C_REG);
	int KilledEnD = deadregion(D_REG);

	pGUI->DrawString(15, 550, "Active Enemies  -  " + to_string(ActEnA));
	pGUI->DrawString(355, 550, "Active Enemies  -  " + to_string(ActEnB));
	pGUI->DrawString(695, 550, "Active Enemies  -  " + to_string(ActEnC));
	pGUI->DrawString(1035, 550, "Active Enemies  -  " + to_string(ActEnD));

	pGUI->DrawString(15, 565, "Killed Enemies  -  " + to_string(KilledEnA));
	pGUI->DrawString(355, 565, "Killed Enemies  -  " + to_string(KilledEnB));
	pGUI->DrawString(695, 565, "Killed Enemies  -  " + to_string(KilledEnC));
	pGUI->DrawString(1035, 565, "Killed Enemies  -  " + to_string(KilledEnD));
}
int Battle::deadregion(REGION a)
{
	int count=0;
	for(int i=0;i<EnemyCount;i++)
	{
		if(BEnemiesForDraw[i]->getstate()=='k' && BEnemiesForDraw[i]->GetRegion()==a)
		{
			count++;
		}
	}
	return count;
}
void Battle::killregion(REGION a)
{
	for(int i=0;i<EnemyCount;i++)
	{
	   if(BEnemiesForDraw[i]->GetRegion()==a)
	   {
		   BEnemiesForDraw[i]->setstate('k');
	   }
	}
}
void Battle::Attack(list& B,Castle A,list&killed,int timestep,int a)
{
	if(A.returntower(a)->getstate()=='a')
	{
		int count=A.returntower(a)->getN();
		if(B.isEmpty()==false)
		{
		Node*ptr=B.gethead();
		if(ptr!=NULL)
		while(ptr && count>0)
			{
			    if(ptr->getItem()->gethealth()==100 && A.returntower(a)->getDamage(ptr->getItem())>0)
				{
					ptr->getItem()->setTFshot(timestep);
					ptr->getItem()->setFD(ptr->getItem()->getTFshot()-ptr->getItem()->getarrivaltime());
				}
			ptr->getItem()->decreasehealth(A.returntower(a)->getDamage(ptr->getItem()),timestep);
				ptr=ptr->getNext();
				count--;
			}
			B.checkkilled(killed,B);
			B.medic(a);
		}
	}
		if(B.isEmpty()==false && A.returntower(a)->getstate()=='a')
		{
			Node*ptr=B.gethead();
			while(ptr)
			{
				ptr->getItem()->Attack();
				A.returntower(a)->DecrementHealth(ptr->getItem()->getdmg());
				ptr=ptr->getNext();
			}
		}
}
void Battle::Print()
{
	for(int i=0;i<EnemyCount;i++)
	{
		cout<<"Enemy no."<<i<<"Health ="<<BEnemiesForDraw[i]->gethealth()<<" state= "<<BEnemiesForDraw[i]->getstate()<<" ID = "<<BEnemiesForDraw[i]->getid()<<endl;
	}
}
bool Battle::checkkill(REGION a)
{
	int countregion=0;
	int countdead=0;
	for(int i=0;i<EnemyCount;i++)
	{
		if(BEnemiesForDraw[i]->GetRegion()==a)
		{
			countregion++;
			if(BEnemiesForDraw[i]->getstate()=='k')
			{
				countdead++;
			}
		}
	}
	if(countdead==countregion)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Battle::pave(){
	for(int i=0;i<EnemyCount;i++){
		if(BEnemiesForDraw[i]->getstate()=='a'){
		if(BEnemiesForDraw[i]->gettype()=='p'){
			if(BEnemiesForDraw[i]->getdmg()!=0){
			BCastle.pave(BEnemiesForDraw[i]->GetRegion(),BEnemiesForDraw[i]->GetDistance(),BEnemiesForDraw[i]->getfirepower());
			for(int j=0;j<(BEnemiesForDraw[i]->getfirepower());j++){
			BEnemiesForDraw[i]->Move();
			
			}
			}	 
		}}
	}



}
void Battle::outputfile(list killed)
{
	fstream save;
	Node*ptr=killed.gethead();
	save.open("output.txt", ios::out | ios::out | ios::app);
	if(ptr!=NULL)
	{
	while(ptr)
	{
		if(ptr->getItem()->getstate()=='k')
		{   
			
		/*	save << "Killed Enemy no: " << killedcount << "  ";*/
			save << "ID: " << ptr->getItem()->getid() << "  ";
			save << "Type: " << ptr->getItem()->gettype() << "  ";
			save << "KTS" << ptr->getItem()->getKT() << "  ";
			save << "FD " << ptr->getItem()->getFD() << "  ";
			save << "KD " << ptr->getItem()->getKD() << "  ";
			save << "LT " << ptr->getItem()->getLT() << "  " << endl;
		}
		ptr=ptr->getNext();
	}
	save<<" Tower A damage " <<BCastle.gethealth()-BCastle.returntower(0)->GetHealth()<<" Tower B damage " <<BCastle.gethealth()-BCastle.returntower(1 )->GetHealth()<<" Tower C damage " <<BCastle.gethealth()-BCastle.returntower(2)->GetHealth()<<" Tower D damage" <<BCastle.gethealth()-BCastle.returntower(3)->GetHealth()<<endl;
	save<<" Tower A unpaved " <<BCastle.returntower(0)->getunpaved()<<" Tower B unpaved " <<BCastle.returntower(1)->getunpaved()<<" Tower C unpaved " <<BCastle.returntower(2)->getunpaved()<<" Tower D unpaved " <<BCastle.returntower(3)->getunpaved()<<endl;
	if(killed.getLength()==EnemyCount)
	{
		save<<" Game is Win" <<endl<< "Enemy Killed = "<<EnemyCount << endl;
		Node*pes=killed.gethead();
		int sfirstshot=0;
		int skilldelay=0;
		while(pes)
		{
			sfirstshot=sfirstshot+pes->getItem()->getFD();
			skilldelay=skilldelay+pes->getItem()->getKD();
			pes=pes->getNext();
		}
		save<< " Avg First Shot Delay "<<sfirstshot/EnemyCount<<endl;
		save<< " Avg Kill Delay "<<skilldelay/EnemyCount<<endl;
	}
	else
	{
		int countk=0;
		int count=0;
		for(int i=0;i<EnemyCount;i++)
		{
			if(BEnemiesForDraw[i]->getstate()=='k')
			{
				countk++;
			}
			else
			{
				count++;
			}
		}
		save<<" killed enemies= "<<countk<<endl;
		save<<" alive enemies= "<<count<<endl;
		Node*pes=killed.gethead();
		int sfirstshot=0;
		int skilldelay=0;
		while(pes)
		{
			sfirstshot=sfirstshot+pes->getItem()->getFD();
			skilldelay=skilldelay+pes->getItem()->getKD();
			pes=pes->getNext();
		}
		save<< " Avg First Shot Delay "<<sfirstshot/countk<<endl;
		save<< " Avg Kill Delay "<<skilldelay/countk<<endl;
	}

}
	save.close();
}
void list::medic(int timestep)
{
	Enemy*b=NULL;
	Node*ptr=head;
	while(ptr)
	{
		if(ptr->getItem()->gettype()=='q')
		{
			 b=ptr->getItem();
		}
		ptr=ptr->getNext();
	}
	if(b==NULL)
		return;
	Node*pes=head;
	while(pes)
	{
		if(pes->getItem()->GetDistance()==b->GetDistance() && pes->getItem()->gettype()!='q')
		{
			int g=100-pes->getItem()->gethealth();
			if(b->gethealth()<=g)
			{
				b->decreasehealth(g,timestep);
				pes->getItem()->incrementhealth(b->gethealth());
			}
			else
			{
				b->decreasehealth(g,timestep);
				pes->getItem()->incrementhealth(g);
			}
		}
		pes=pes->getNext();
	}
}
void Battle::move(){ 
	for(int i=0;i<EnemyCount;i++){
		if(BEnemiesForDraw[i]->getstate()=='a'){
			if(BEnemiesForDraw[i]->gettype()=='p'){
				if((BEnemiesForDraw[i]->getdmg()==0)){
		if(BCastle.checkpaved(BEnemiesForDraw[i]->GetRegion(),BEnemiesForDraw[i]->GetDistance())){
		BEnemiesForDraw[i]->Move();
		
		}}}
		else if(BCastle.checkpaved(BEnemiesForDraw[i]->GetRegion(),BEnemiesForDraw[i]->GetDistance())&&(BEnemiesForDraw[i]->getdmg()==0)){
		
			BEnemiesForDraw[i]->Move();
		
		}
		}
		

	}
}
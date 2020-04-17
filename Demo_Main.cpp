#include "Battle.h"
#include "GUI\GUI.h"
#include "Enemies\Enemy.h"
#include "Enemies\Paver.h"
#include "Enemies\NFighter.h"
#include "Enemies\SFighter.h"
#include "DS\Node.h"
#include"DS\Queue.h"
#include"../DSProject/List.h"
#include<iostream>
#include"Defs.h"
using namespace std;
#include"Castle\Tower.h"
#include <string>
//01125801580555555555555555555555555555
int main()
{
	
	//
	// THIS IS JUST A DEMO
	// THIS MAIN SHOULD BE CHANGED IN PHASE 1 AND PHASE 2
	//
	

	Battle* pGameBattle = new Battle;

	GUI * pGUI = new GUI;

	pGUI->PrintMessage("This is Just a Demo. Click to Move to the Next Time Step ...");
	
	
	
	
	// Declare some enemies and fill their data
	// In the game, enemies should be loaded from an input file
	// and should be dynamically allocated

	Queue A,B,C,D;
	bool isloaded=false;
	// Drawing the battle enemies
	pGameBattle->DrawEnemies(pGUI);
	list gA;
	list killed;
	list gB;
	list gC;
	list gD;
	 int TimeStep=1;
	/*Tower(REGION a,double health,int firepowers,double reloadperiods,int n)*/
	list *active= new list[4];
	active[0]=gA;
	active[1]=gB;
	active[2]=gC;
	active[3]=gD;
	ActionType b=EMPTY;
	Point p;
	pGUI->PrintMessage("Load the Avengers and Thanos");
	do
	{
		b=pGUI->GetUserAction();
	switch(b)
	{
	case LOAD : pGameBattle->load(A,B,C,D,pGUI);
	             A.sort();
				 B.sort();
				 C.sort();
				 D.sort();
				 cout<<A.getlength()<<endl;
				 cout<<B.getlength()<<endl;
				 cout<<C.getlength()<<endl;
				 cout<<D.getlength()<<endl;
				 isloaded=true;
				 pGUI->PrintMessage("Load Confirmed");
		break;
	case INTERACTIVEMODE: 
			pGUI->PrintMessage("Interactive Mode Selected,Press anywhere to continue");
			pGameBattle->DrawEnemies(pGUI);
		     pGUI->GetPointClicked(p);
			 PlaySound("openfire.wav", NULL,SND_FILENAME|SND_ASYNC);
	while((pGameBattle->GetCastle().returntower(0)->getstate()=='a' || pGameBattle->GetCastle().returntower(1)->getstate()=='a' || pGameBattle->GetCastle().returntower(2)->getstate()=='a' || pGameBattle->GetCastle().returntower(3)->getstate()=='a') && (pGameBattle->checkkill(A_REG)==false || pGameBattle->checkkill(B_REG)==false || pGameBattle->checkkill(C_REG)==false|| pGameBattle->checkkill(D_REG)==false))
	 {
		// Clear for redrawing
		if(isloaded==false)
		{
			pGUI->PrintMessage("mtload ya baba");
			break;
		}
		pGUI->ClearStatusBar();
		pGUI->ClearBattleArea();
		pGUI->DrawCastle();
		pGameBattle->activateenemies(TimeStep);
		A.checkactive(TimeStep,gA);
		B.checkactive(TimeStep,gB);
		C.checkactive(TimeStep,gC);
		D.checkactive(TimeStep,gD);
	    gA.sortbyprio();
		gB.sortbyprio();
		gC.sortbyprio();
		gD.sortbyprio();
		pGameBattle->DrawEnemies(pGUI);
		pGameBattle->print(gA,gB,gC,gD,killed,pGameBattle->GetCastle(),pGUI);
		pGameBattle->Attack(gA,pGameBattle->GetCastle(),killed,TimeStep,0);
		pGameBattle->Attack(gB,pGameBattle->GetCastle(),killed,TimeStep,1);
		pGameBattle->Attack(gC,pGameBattle->GetCastle(),killed,TimeStep,2);
		pGameBattle->Attack(gD,pGameBattle->GetCastle(),killed,TimeStep,3);	
		pGameBattle->pave();
		pGameBattle->move();
		if(pGameBattle->GetCastle().returntower(0)->getstate()=='k' && pGameBattle->GetCastle().returntower(1)->getstate()=='k' && pGameBattle->GetCastle().returntower(2)->getstate()=='k' && pGameBattle->GetCastle().returntower(3)->getstate()=='k' && pGameBattle->checkkill(A_REG) && pGameBattle->checkkill(B_REG) && pGameBattle->checkkill(C_REG) && pGameBattle->checkkill(D_REG))
	{
		pGUI->PrintMessage("Avengers Won");
		break;
	}
	else if(pGameBattle->GetCastle().returntower(0)->getstate()=='k' && pGameBattle->GetCastle().returntower(1)->getstate()=='k' && pGameBattle->GetCastle().returntower(2)->getstate()=='k' && pGameBattle->GetCastle().returntower(3)->getstate()=='k')
	{
		pGUI->PrintMessage("Avengers Won");
		break;
	}
	else if(pGameBattle->checkkill(A_REG) && pGameBattle->checkkill(B_REG) && pGameBattle->checkkill(C_REG) && pGameBattle->checkkill(D_REG))
	{
		pGUI->PrintMessage("Thanos Won");
		break;
	}
		pGameBattle->Migrate(pGameBattle->GetCastle(),gA,gB,0,1); 
		pGameBattle->Migrate(pGameBattle->GetCastle(),gB,gC,1,2);
		pGameBattle->Migrate(pGameBattle->GetCastle(),gC,gD,2,3);
		pGameBattle->Migrate(pGameBattle->GetCastle(),gD,gA,3,0);
		pGUI->GetPointClicked(p);
		cout<<gD.getlength()<<endl;
		TimeStep++;
	 }
	break;
	    case SILENTMODE: 
			pGUI->PrintMessage("Silent Mode Selected,Press anywhere to continue");
		     pGUI->GetPointClicked(p);
	while((pGameBattle->GetCastle().returntower(0)->getstate()=='a' || pGameBattle->GetCastle().returntower(1)->getstate()=='a' || pGameBattle->GetCastle().returntower(2)->getstate()=='a' || pGameBattle->GetCastle().returntower(3)->getstate()=='a') && (pGameBattle->checkkill(A_REG)==false || pGameBattle->checkkill(B_REG)==false || pGameBattle->checkkill(C_REG)==false|| pGameBattle->checkkill(D_REG)==false))
	{
		if(isloaded==false)
		{
//			A-1.63569
//Tower B-31.4874
//Tower C-9.89693
//Tower D-5.369
			pGUI->PrintMessage("mtload ya baba");
			break;
		}
		// Clear for redrawing
		pGUI->ClearStatusBar();
		pGUI->ClearBattleArea();
		pGUI->DrawCastle();
		pGameBattle->activateenemies(TimeStep);
		A.checkactive(TimeStep,gA);
		B.checkactive(TimeStep,gB);
		C.checkactive(TimeStep,gC);
		D.checkactive(TimeStep,gD);
		gA.sortbyprio();
		gB.sortbyprio();
		gC.sortbyprio();
		gD.sortbyprio();
	  	pGameBattle->Attack(gA,pGameBattle->GetCastle(),killed,TimeStep,0);
		pGameBattle->Attack(gB,pGameBattle->GetCastle(),killed,TimeStep,1);
		pGameBattle->Attack(gC,pGameBattle->GetCastle(),killed,TimeStep,2);
		pGameBattle->Attack(gD,pGameBattle->GetCastle(),killed,TimeStep,3);	
		pGameBattle->pave();
		pGameBattle->move();
	if(pGameBattle->GetCastle().returntower(0)->getstate()=='k' && pGameBattle->GetCastle().returntower(1)->getstate()=='k' && pGameBattle->GetCastle().returntower(2)->getstate()=='k' && pGameBattle->GetCastle().returntower(3)->getstate()=='k' && pGameBattle->checkkill(A_REG) && pGameBattle->checkkill(B_REG) && pGameBattle->checkkill(C_REG) && pGameBattle->checkkill(D_REG))
	{
		pGUI->PrintMessage("Avengers Won");
		break;
	}
	else if(pGameBattle->GetCastle().returntower(0)->getstate()=='k' && pGameBattle->GetCastle().returntower(1)->getstate()=='k' && pGameBattle->GetCastle().returntower(2)->getstate()=='k' && pGameBattle->GetCastle().returntower(3)->getstate()=='k')
	{
		pGUI->PrintMessage("Avengers Won");
		break;
	}
	else if(pGameBattle->checkkill(A_REG) && pGameBattle->checkkill(B_REG) && pGameBattle->checkkill(C_REG) && pGameBattle->checkkill(D_REG))
	{
		pGUI->PrintMessage("Thanos Won");
		break;
	}
		pGameBattle->Migrate(pGameBattle->GetCastle(),gA,gB,0,1); 
		pGameBattle->Migrate(pGameBattle->GetCastle(),gB,gC,1,2);
		pGameBattle->Migrate(pGameBattle->GetCastle(),gC,gD,2,3);
		pGameBattle->Migrate(pGameBattle->GetCastle(),gD,gA,3,0);
		
		TimeStep++;
		// Redraw the enemies
	}
	
	break;
		case STEPBYSTEPMODE: 
			pGUI->PrintMessage("StepbyStep Mode Selected,Press anywhere to continue");
			pGameBattle->DrawEnemies(pGUI);
		     pGUI->GetPointClicked(p);
			  PlaySound("openfire.wav", NULL,SND_FILENAME|SND_ASYNC);
		
	while((pGameBattle->GetCastle().returntower(0)->getstate()=='a' || pGameBattle->GetCastle().returntower(1)->getstate()=='a' || pGameBattle->GetCastle().returntower(2)->getstate()=='a' || pGameBattle->GetCastle().returntower(3)->getstate()=='a') && (pGameBattle->checkkill(A_REG)==false || pGameBattle->checkkill(B_REG)==false || pGameBattle->checkkill(C_REG)==false|| pGameBattle->checkkill(D_REG)==false))
	{
		if(isloaded==false)
		{
			pGUI->PrintMessage("mtload ya baba");
			break;
		}
		// Clear for redrawing
		pGUI->ClearStatusBar();
		pGUI->ClearBattleArea();
		pGUI->DrawCastle();
		pGameBattle->activateenemies(TimeStep);
		A.checkactive(TimeStep,gA);
		B.checkactive(TimeStep,gB);
		C.checkactive(TimeStep,gC);
		D.checkactive(TimeStep,gD);
		gA.sortbyprio();
		gB.sortbyprio();
		gC.sortbyprio();
		gD.sortbyprio();
		pGameBattle->DrawEnemies(pGUI);
		pGameBattle->print(gA,gB,gC,gD,killed,pGameBattle->GetCastle(),pGUI);
		pGameBattle->Attack(gA,pGameBattle->GetCastle(),killed,TimeStep,0);
		pGameBattle->Attack(gB,pGameBattle->GetCastle(),killed,TimeStep,1);
		pGameBattle->Attack(gC,pGameBattle->GetCastle(),killed,TimeStep,2);
		pGameBattle->Attack(gD,pGameBattle->GetCastle(),killed,TimeStep,3);		
		pGameBattle->pave();
		pGameBattle->move();
		if(pGameBattle->GetCastle().returntower(0)->getstate()=='k' && pGameBattle->GetCastle().returntower(1)->getstate()=='k' && pGameBattle->GetCastle().returntower(2)->getstate()=='k' && pGameBattle->GetCastle().returntower(3)->getstate()=='k' && pGameBattle->checkkill(A_REG) && pGameBattle->checkkill(B_REG) && pGameBattle->checkkill(C_REG) && pGameBattle->checkkill(D_REG))
	{
		pGUI->PrintMessage("Avengers Won");
		break;
	}
	else if(pGameBattle->GetCastle().returntower(0)->getstate()=='k' && pGameBattle->GetCastle().returntower(1)->getstate()=='k' && pGameBattle->GetCastle().returntower(2)->getstate()=='k' && pGameBattle->GetCastle().returntower(3)->getstate()=='k')
	{
		pGUI->PrintMessage("Avengers Won");
		break;
	}
	else if(pGameBattle->checkkill(A_REG) && pGameBattle->checkkill(B_REG) && pGameBattle->checkkill(C_REG) && pGameBattle->checkkill(D_REG))
	{
		pGUI->PrintMessage("Thanos Won");
		break;
	}
		pGameBattle->Migrate(pGameBattle->GetCastle(),gA,gB,0,1); 
		pGameBattle->Migrate(pGameBattle->GetCastle(),gB,gC,1,2);
		pGameBattle->Migrate(pGameBattle->GetCastle(),gC,gD,2,3);
		pGameBattle->Migrate(pGameBattle->GetCastle(),gD,gA,3,0);

		// Redraw the enemies
		
		Sleep(1000);
		TimeStep++;
	}
				break;
		case EXIT: return 0;
			break;
		case EMPTY: pGUI->PrintMessage("Choose a Simulation Interface");
			break;
	}
	}while(b==EMPTY || b==LOAD || isloaded==false);
	
	// Now a demo to move enemies some time steps
	// TimeStep is a normal integer that is incremented each time by 1
	pGameBattle->DrawEnemies(pGUI);
		pGameBattle->print(gA,gB,gC,gD,killed,pGameBattle->GetCastle(),pGUI);
		killed.sortkilled();
		pGameBattle->outputfile(killed);
	delete pGUI;
	delete pGameBattle;
	system("pause");
	return 0;
}
//SFighter
//2 20 1 1 i 7
//SFighter
//0 20 1 1 i 30
//SFighter
//2 20 1 1 i 4
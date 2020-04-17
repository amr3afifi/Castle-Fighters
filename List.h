#pragma once
#include"DS\Node.h"
#include"Enemies\Enemy.h"
//#include"Battle.h"
//#include"PrecondViolatedExcep.h"
class list
{
	Node* head;
	Node*tail;
	int itemcount;
	Node* getNodeAt(int)const;
	/*Battle pGameBattle;*/
public:
	list();
	~list();
	void sortbyprio();
	void sortsheilded();
	Node*gettail();
	void sethead(Node*f);
	Enemy*& getEntry(int position)const;
	void checkkilled(list& killed,list &active);
	void removekilled();
	/*
	void setEntry(int position, const int &newEntry)
		throw(PrecondViolatedExcep);
	*/
	void insert(Enemy *& newEntry);
	void insertfront( Enemy *& newEntry);
	bool remove(int position);
	bool remove(Enemy*ptr);
	bool isEmpty()const;
	void clear();
	int getLength()const;
	void Printall();
	Node*gethead();
	void sortkilled();
	int getlength();
	int getcountregion(REGION a);
	void sortnormal();
	void medic(int timestep);
};

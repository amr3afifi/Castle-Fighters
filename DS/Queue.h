
/*
This code was copied from "Data Abstraction & Problem Solving with C++,WALLS AND MIRRORS ,SIXTH EDITION"
*/

/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers, a frontPtr pointer for the front of the queue
and a backPtr pointer for the back of the queue.
Note that we have used  exception instead of assertions in function peekFront()*/
#ifndef _QUEUE
#define _QUEUE

#include "Node.h"
#include"List.h"
#include"../Enemies/Enemy.h"
class Queue
{
private :
	
	Node* backPtr;
	Node* frontPtr;
public :
	Queue();
	int getlength();
	bool isEmpty() const ;
	bool enqueue(Enemy*& newEntry);
	void dequeue();
	void checkactive(int c,list &h);
	void sort();
	void Print();

	/** @throw PrecondViolatedExcep if the queue is empty */
	//T peekFront() const throw (PrecondViolatedExcep);
	~Queue();
};
/////////////////////////////////////////////////////////////////////////////////////////
#endif
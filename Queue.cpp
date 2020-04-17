#include"DS\Node.h"
#include"DS\Queue.h"
#include<iostream>
using namespace std;
#include"Enemies\Enemy.h"
Queue::Queue()
{
	backPtr=nullptr;
	frontPtr=nullptr;
}
/////////////////////////////////////////////////////////////////////////////////////////


bool Queue::isEmpty() const
{
	if(frontPtr==nullptr)
		return true;
	else
		return false;
}
void Queue::checkactive(int c,list& h )
{
	if(frontPtr!=NULL)
	{
	Node*e=frontPtr;
	while(e)
	{
	if(e->getItem()->getstate()=='a')
	{
		h.insert(e->getItem());
		dequeue();
	}
	e=e->getNext();
	}
	}
}
void Queue::Print()
{
	Node*ptr=frontPtr;
	while(ptr)
	{
		ptr->getItem()->Print();
		ptr=ptr->getNext();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
Returns the front of this queue. That is, gets the item that was added earliest. The
operation does not change the queue.

Input: None.
Output: The front of the queue.
*/


//template <class T>
//T Queue<T>:: peekFront() const throw (PrecondViolatedExcep)
//{
//	if(isEmpty())
//	{
//		string message="peekFront() called with empty queue";
//		throw (new PrecondViolatedExcep(message));
//	}
//	else
//	{
//		return frontPtr->getItem();
//	}
//
//}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

bool Queue::enqueue( Enemy*& newEntry)
{
	Node* newNodePtr = new Node;
	newNodePtr->setItem(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue was empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	return true ;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/


void Queue::dequeue()
{
	if (!isEmpty())
	{
		// Queue is not empty; remove front
		Node* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{ // Special case: one node in queue
			frontPtr = nullptr ;
			backPtr = nullptr ;
		}
		else
			frontPtr = frontPtr->getNext();
		// Return deleted node to system
	} // end if
} // end dequeue

///////////////////////////////////////////////////////////////////////////////////

void Queue::sort()
{
	Node*ptr=frontPtr;
	Node*after=ptr->getNext();
	while(ptr->getNext())
	{
	while(after)
	{
		if(after->getItem()->getarrivaltime() < ptr->getItem()->getarrivaltime())
		{
			Enemy *data=after->getItem();
			after->setItem(ptr->getItem());
			ptr->setItem(data);
		}
		after=after->getNext();
	}
	ptr=ptr->getNext();
	after=ptr->getNext();
	}
}
int Queue::getlength()
{
	int count=0;
	Node*g=frontPtr;
	while(g)
	{
		count++;
		g=g->getNext();
	}
	return count;
}
Queue::~Queue()
{
}
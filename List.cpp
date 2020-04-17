#include "list.h"
#include"Battle.h"
#include <cassert>
#include<iostream>
using namespace std;


list::list()
	:head(NULL), itemcount(0)
{
}
//SURE
Node* list::getNodeAt(int position)const
{
	assert((position >= 0) && (position < itemcount));
	Node* currPtr = head;
	for (int i = 0; i < position - 1; i++)
		currPtr = currPtr->getNext();
	
	return currPtr;
}
Enemy*& list::getEntry(int position)const
{
	bool ableToGet = (position >= 0) && (position < itemcount);
	if (ableToGet)
	{
		Node* ptr = getNodeAt(position);
		return ptr->getItem();
	}

}
 
/*
void list::setEntry(int position, const int &newEntry)throw(PrecondViolatedExcep)
{
	Node myNode;

	bool able = ((position >= 0) && (position < itemcount));
	if (able)
	{
		myNode = getNodeAt(position);
		myNode.setItem(newEntry);
	}
	string message = "invalid position";
	throw (new PrecondViolatedExcep(message));
}
*/
void list::insert(Enemy *&newEntry)
{
	if(head==NULL)
	{
		head=new Node;
		head->setItem(newEntry);
		tail=head;
		itemcount++;
		return;
	}
	else
	{
		Node*newnode=new Node;
		newnode->setItem(newEntry);
		tail->setNext(newnode);
		tail=newnode;
		itemcount++;
		return;
	}
}
Node* list::gettail()
{
	return tail;
}
bool list::remove(int position)
{
	bool ableToRemove = ((position >= 0) && (position < itemcount));

	if (ableToRemove)
	{
		Node* currPtr = nullptr;

		if (position == 0)
		{
			currPtr=head;
			head = head->getNext();
			currPtr->setNext(nullptr);
		}
		else if(position==getLength()-1)
		{
			currPtr=getNodeAt(position-1);
			currPtr->setNext(NULL);
		}
		else
		{
			currPtr = getNodeAt(position);
			Node* prev = getNodeAt(position - 1);
			Node* ptr = currPtr->getNext();
			prev->setNext(ptr);
		    currPtr->setNext(nullptr);
		}
		itemcount--;

	}

	return ableToRemove;
}
bool list::isEmpty()const
{
	return itemcount==0;
}
void list::clear()
{
	while (!isEmpty())
		remove(0);
}
void list::sethead(Node*f)
{
	head=f;
}
int list::getLength()const
{

	return itemcount;
}
void list::sortbyprio()
{
	if(getLength()!=getlength() && head->getNext()==NULL)
	{
		head=NULL;
		itemcount=0;
		return;
	}
	list s,n;
	Node*ptr=head;
	if(ptr==NULL)
		return;
	while(ptr)
	{
		if(ptr->getItem()->gettype()=='s')
		{
			s.insert(ptr->getItem());
		}
		else
		{
			n.insert(ptr->getItem());
		}
		ptr=ptr->getNext();
	}
	s.sortsheilded();
	n.sortnormal();
	if(s.gethead()!=NULL && n.gethead()!=NULL)
	{
	  s.tail->setNext(n.gethead());
	  s.tail=n.tail;
	  head=s.head;
	  tail=s.tail;
	}
	else if(s.gethead()==NULL && n.gethead()!=NULL)
	{
		head=n.head;
		tail=n.tail;
	}
	else if(s.gethead()!=NULL && n.gethead()==NULL)
	{
		head=s.head;
	  tail=s.tail;
	}
}
void list::Printall()
{
	Node*ptr=head;
	while(ptr)
	{

		ptr->getItem()->Print();
		ptr=ptr->getNext();
	}
}
void list::insertfront( Enemy*& ene)
{
	Node*newnode=new Node;
	newnode->setItem(ene);
	newnode->setNext(head);
	head=newnode;
}
void list::sortsheilded()
{
	if(isEmpty()==false && getLength()>1)
	{
	Node*ptrs=head;
	Node*afters=ptrs->getNext();
	while(ptrs->getNext())
	{
	while(afters)
	{
		if(afters->getItem()->getpriority() > ptrs->getItem()->getpriority())
		{
			Enemy *data=afters->getItem();
			afters->setItem(ptrs->getItem());
			ptrs->setItem(data);
		}
		afters=afters->getNext();
	}
	ptrs=ptrs->getNext();
	afters=ptrs->getNext();
	}
}
}
void list::sortnormal()
{
		if(isEmpty()==false && getLength()>1)
	{
	Node*ptrs=head;
	Node*afters=ptrs->getNext();
	while(ptrs->getNext())
	{
	while(afters)
	{
		if(afters->getItem()->getarrivaltime() < ptrs->getItem()->getarrivaltime())
		{
			Enemy *data=afters->getItem();
			afters->setItem(ptrs->getItem());
			ptrs->setItem(data);
		}
		afters=afters->getNext();
	}
	ptrs=ptrs->getNext();
	afters=ptrs->getNext();
	}
}
}
void list::checkkilled(list& killed,list& active)
{
	Node*ptr=active.head;
	int count=0;
	if(ptr!=NULL)
	{
	while(ptr)
	{
		if(ptr->getItem()->getstate()=='k')
		{ 
			killed.insert(ptr->getItem());
			count++;
		}
		ptr=ptr->getNext();
	}
	for(int i=0;i<count;i++)
	{
	active.removekilled();
	}
	}
}
void list::removekilled()
{
		Node*ptr=head;
	while(ptr)
	{
		if(ptr->getItem()->getstate()=='k')
		{
			remove(ptr->getItem());
		}
		ptr=ptr->getNext();
	}
}
bool list::remove(Enemy*ptrss)
{
	if(!(isEmpty()))
	{
		if(head->getItem()==ptrss)
		{
			head=head->getNext();
			if(head==NULL)
			{
				tail==NULL;
			}
			itemcount--;
			return true;
		}
		else{
	Node*batman=head;
	Node*after=batman->getNext();
	while(after)
	{
		if(after->getItem()==ptrss)
		{
		   batman->setNext(after->getNext());
			after->setNext(NULL);
			after=batman->getNext();
			itemcount--;
			return true;
		}
		after=after->getNext();
		batman=batman->getNext();
	}
		}
	return false;
}
}
int list:: getlength()
{
	int count=0;
	Node*ptr=head;
	while(ptr)
	{
		count++;
		ptr=ptr->getNext();
	}
	return count;
}
int list::getcountregion(REGION a)
{
	Node*ptr=head;
	int count=0;
	while(ptr)
	{
		if(ptr->getItem()->getstate()=='k' && ptr->getItem()->GetRegion()==a)
		{
			count++;
		}
		ptr=ptr->getNext();
	}
	return count;
}
Node* list::gethead()
{
	return head;
}
void list:: sortkilled()
{
	if(isEmpty()==false && getLength()>1)
	{
	Node*ptrs=head;
	Node*afters=ptrs->getNext();
	while(ptrs->getNext())
	{
	while(afters)
	{
		if(afters->getItem()->getKT() < ptrs->getItem()->getKT())
		{
			Enemy *data=afters->getItem();
			afters->setItem(ptrs->getItem());
			ptrs->setItem(data);
		}
		afters=afters->getNext();
	}
	ptrs=ptrs->getNext();
	afters=ptrs->getNext();
	}
	Node*ptrss=head;
	Node*afterss=ptrss->getNext();
	while(ptrss->getNext())
	{
	while(afterss)
	{
		if(afterss->getItem()->getKT() == ptrss->getItem()->getKT() && afterss->getItem()->getFD() < ptrss->getItem()->getFD() )
		{
			Enemy *data=afterss->getItem();
			afterss->setItem(ptrss->getItem());
			ptrss->setItem(data);
		}
		afterss=afterss->getNext();
	}
	ptrss=ptrss->getNext();
	afterss=ptrss->getNext();
	}
	}
}
list::~list()
{
}

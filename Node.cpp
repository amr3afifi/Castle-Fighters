#include"Enemies\Enemy.h"
#include"../DSProject/DS/Node.h"
Node::Node()
{
	next=NULL;
}
void Node::setItem(  Enemy*& anItem)
{
	data = anItem;
} 

void Node::setNext(Node* nextNodePtr)
{
	next = nextNodePtr;
} 

Enemy*& Node::getItem() 
{
	return data;
} 
Node* Node::getNext() const
{
	return next;
} 

double Node::getprio() const
{
	return priority;
}
Node::~Node()
{
}
#pragma once
#include"../Enemies/Enemy.h"
#ifndef _NODE
#define _NODE
class Node
{
private :
Enemy * data; // A data item
double priority;
Node* next; // Pointer to next node
public :
Node();
void setItem(  Enemy*& anItem);
void setNext(Node* nextNodePtr);
Enemy*& getItem() ;
Node* getNext() const ;
double getprio() const;
~Node();
}; // end Node
#endif
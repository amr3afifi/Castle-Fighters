/*
This is a program that implements the stack abstract data type using an array.
*/

/*
Note that we have used Assertions in function peek():
Assertions are in the form of a boolean expression that should be true at a specifi c point in the program. If the
assertion is false, the assert function halts execution of the program. Assertions can be used to validate
method preconditions before trying to execute the body of a function or method.
To use assert in a program, you fi rst must include its header fi le:
#include <cassert>
To call the assert function, you provide a boolean condition as its argument:
assert( someBooleanCondition );
*/

#include <cassert>

// Define a template class that contains an array of 100 element named "array"
// and an integer named "top".
template <class T,int STACK_SIZE=100>
class Stack
{
	T elements[STACK_SIZE];
	int top;
public:
	Stack();
	bool push(T x);
	bool pop();
	T peek() const;
	bool isFull();
	bool isEmpty() const;
	~Stack();
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Stack()
The constructor of the Stack class.

*/

template <class T,int STACK_SIZE>
Stack<T,STACK_SIZE>::Stack()
{
	top = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: isEmpty

Checks whether a stack is empty
*/
template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>:: isEmpty() const
{
	if (top == -1) return true;
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: isFull
Checks whether a stack is full
*/
template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>::isFull()
{
	if (top == STACK_SIZE-1) return true;
	return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////

//function push
/*
Function: push
Pushes an element onto a stack.

Parameters:
	x - The element to be pushed.

*/
template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>::push(T x)
{
	if (isFull()) return false; // check if the stack is full, then we can't push the element x

	top++;
	elements[top] = x;
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: pop
Removes the top of this stack. That is, it removes the item that was added most recently.

Returns:
	The popped element.
*/

template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>::pop()
{
	if(!isEmpty())
	{
		top--;
		return true;
	}
	return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
get the top of the stack without removing it from the stack

Returns:
	The top of the stack.
*/

template <class T,int STACK_SIZE>
T Stack<T,STACK_SIZE>::peek() const
{
	assert (!isEmpty()); // Enforce precondition
	return elements[top];
} 


///////////////////////////////////////////////////////////////////////////////////////////////
template <class T,int STACK_SIZE>
Stack<T,STACK_SIZE>:: ~Stack()
{
}







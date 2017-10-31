#include "stack.h"

/*
 * Node Constructor
 */
Node::Node(long d)
{
    data = d;
    next = NULL;
}

/*
 * Node Destructor
 */
Node::~Node()
{
    //Nothing to deconstruct (NO DYNAMIC MEM)
}

/*
 * Stack Constructor
 */
Stack::Stack()
{
    head = NULL;
    tail = NULL;
    n_elem = 0;
    top = 0;
}

/*
 * Stack Destructor
 */
Stack::~Stack() //Needs to be updated 
{
    if(head != NULL && tail != NULL)
    {
        this->pop();
    }
}

/*
 * Similar to the prepend function of a LL, add a new node to the front of the stack
 */
void Stack::push(long d)
{
	// TODO
    Node *prependNode = new Node(d);
    if(head == NULL && tail == NULL)
    {
        head = prependNode;
        tail = prependNode;
    }
    else
    {
        prependNode -> next = head;
        head = prependNode;
    }
    n_elem++;
}

/*
 * Similar to the remove first function of a LL, remove the first elem of the stack and return its data
 */
long Stack::pop()
{
	//TODO
    long headData = head -> data;
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *p = head -> next;
        delete head;
        p = head;
         
    }
    n_elem--;
	return headData;
}

/*
 * Check to see if the stack is empty and return true if it is 
 */
bool Stack::isEmpty()
{
    if(n_elem == 0)
    {
        retrun true;
    }
    else
    {
        return false;
    }
}
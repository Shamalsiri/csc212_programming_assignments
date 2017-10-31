#include "stack.h"

/*
 * Node Constructor
 */
Node::Node(int d)
{
    data =d;
    next = NULL;
    //prev = NULL;
}

/*
 * Node Destructor
 */
Node::~Node()
{
    //Nothing to deconstruct (NO DYNAMIC MEM)
}

/*
 * LL Constructor
 */
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    n_elem = 0;
}

/*
 * LL Destructor
 */
LinkedList::~LinkedList()
{
    if(head != NULL && tail != NULL)
    {
        this->clear();
    }
}

/*
 * Stack Constructor
 */
Stack::Stack()
{
    top = 0;   
}

/*
 * Stack Destructor
 */
Stack::~Stack()
{
    // Don't think there anything to Deconstruct here 
}

/*
 * The insertAt function receives an index, and a value and inserts it at that index in the list
 */
void LinkedList::insertAt(unsigned int index, int d)
{
	// TODO
    Node *p = head;
    int count = 0;
    while(count < index-1)
    {
        p = p->next;
        count++;
    }
    Node *q = p->next;
    Node *insertNode = new Node(d);
    
    p->next = insertNode;
    insertNode ->next =q;
}

/*
 * The removeAt function receives an index, and removes the element at that index
 */
int LinkedList::removeAt(unsigned int index)
{
	// TODO
    Node *p = head;
    int count = 0;
    while(count < index-1)
    {
        p = p->next;
        count++;
    }
    int pData = p->data;
    Node *q = p->next;
    Node *r = q->next;
    
    delete q;
    p->next = r;
    
    return pData;
}

/*
 * The find function receives an integer, and returns if it is in the list
 */
bool LinkedList::find(int d)
{
	// TODO
    Node * p= head;
    while(p != tail)
    {
        if(p->data == d)
        {
            return true;
        }
        p = p->next;          
    }
    if(tail ->data == d)
    {
        return true;
    }
    else
        return false;
}

/*
 * The append function receives an integer,
 * and inserts it onto the list, at the back
 */
void LinkedList::append(int d)
{
	// TODO
    Node *appendNode = new Node(d);
    if(head == NULL && tail == NULL)
    {
        head = appendNode;
        tail = appendNode;
    }
    else
    {
        tail -> next = appendNode;
        tail = appendNode;
    }
}

/*
 * The prepend funtion receives an integer, and inserts it onto the list, at the beginning
 */
void LinkedList::prepend(int d)
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
}

/*
 * The remove last function removes the last element from the list and returns its data
 */
int LinkedList::removeLast()
{
	// TODO
    int tailData = tail -> data;
    if (head != tail)
    {
        Node *p = head;
        while(p->next != tail)
        {
            p = p -> next;
        }
        
        delete tail;
        p = tail;       
    }
    else
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    
    return tailData;
}

/*
 * The remove first function removes the first element from the list 
 * and returns its data
 */
int LinkedList::removeFirst()
{
	//TODO
    int headData = head -> data;
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
	return headData;
}

/*
 * Returns the size of the linked list
 */
unsigned int LinkedList::getSize()
{ 
	// TODO
    if(head == NULL && tail == NULL)
    {
        return 0;
    }
    else if ( head == tail)
    {
        return 1;
    }
    else
    {
        unsigned int size = 0;
        Node *p = head;
        while(p != tail)
        {
            p = p -> next;
            size++;
        }
        return size;
    }
    
}

/*
 * Clears all data from the list
 */
void LinkedList::clear()
{
	//TODO
    while(head != NULL && tail != NULL)
    {
        this ->removeFirst();
    }
}

void push(long val)
{
    if()
}
#ifndef __STACK_H__
#define __STACK_H__

#ifndef NULL
#define NULL 0x00
#endif

class Node 
{
    private:
        Node* next;
        //Node* prev;
        int data;
        
    public:
        Node(int d);
        ~Node();
    
    friend class LinkedList;
    friend class Stack;
};

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        unsigned int n_elem;
        
    public
        LinkedList();
        ~LinkedList();
        
        void insertAt(unsigned int index, int d);
		int removeAt(unsigned int index);

		bool find(int d);
		void append(int d);
		void prepend(int d);
		int removeLast();
		int removeFirst();
		unsigned int getSize();
		void clear();

};

class Stack
{
    private:
        int top;
    public:
        Stack();
        ~Stack();
        
        long int pop();
        void push(long val);
        bool isEmpty();
}
#endif
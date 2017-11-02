#include "stack.h"

using namespace std;

void infix2postflix(const char *infix, char *postfix)
{
    Stack i2fStack;
        
    char mult = '*';
    char div  = '/';
    char carr = '^';
    char add  = '+';
    char sub  = '-';
    char left = '(';
    char right= ')';
    
    int infixSize ; //need the size of the array
    
    for(int i=0; i<infixSize; i++)
    {
        if((infix[i] != mult)||(infix[i] != div)||(infix[i] != carr)||
           (infix[i] != add )||(infix[i] != sub)||(infix[i] != left)||
           (infix[i] != right))
        {
            cout<<infix[i];
        }
        
        else if(infix[i] == left)
        {
            i2fStack.push(left - '0');
        }
        
        else if(infix[i] == carr)
        {
            i2fStack.push(carr - '0');
        }
        
        else if(infix[i] == mult)
        {
            if(!i2fStack.isEmpty() && i2fStack.head->data == div)
            {
                int value = i2fStack.pop();
                cout<< value + '0';
                
            }
            
            i2fStack.push(mult - '0');
        }
        
        else if(infix[i] == div)
        {
            if(!i2fStack.isEmpty() && i2fStack.head->data == mult)
            {
                int value = i2fStack.pop();
                cout<< value + '0';
                
            }
            i2fStack.push(div - '0');
        }
        
        else if((infix[i] == add)
        {
            if(!i2fStack.isEmpty() && i2fStack.head->data == sub)
            {
                int value = i2fStack.pop();
                cout<< value + '0';
            }
            
        }
        
        else if (infix[i] == sub)
        {
            if(!i2fStack.isEmpty() && i2fStack.head->data == add)
            {
                int value = i2fStack.pop();
                cout<< value + '0';
            }
        }
                
        else if(infix[i] == right)
        {
            int value;
            while(i2fStack.head->data != left - '0')
            {
                value = i2fStack.pop();
                cout<< value + '0';
            }
            if(i2fStack.head->data == left - '0')
            {
                value = i2fStack.pop();
            }
        }
    }  
    
}

long int eval_postfix(const char *postfix)
{
    
}
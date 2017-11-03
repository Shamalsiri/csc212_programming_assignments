#include <iostream>
#include  "string.h"
#include "stack.h"

using namespace std;

void infix2postfix(const char *infix, char *postfix)
{
    Stack *i2fStack = new Stack();
    
    char mult = '*';
    char div  = '/';
    char carr = '^';
    char add  = '+';
    char sub  = '-';
    char left = '(';
    char right= ')';
    
    int infixSize = (int)strlen(infix); //need the size of the array
    int pFCount = 0;
    cout<<infixSize;
    
    for(int i = 0; i < infixSize; i++) // regular numbers
    {
        if((infix[i] != mult)&&(infix[i] != div)&&(infix[i] != carr)&&
           (infix[i] != add )&&(infix[i] != sub)&&(infix[i] != left)&&
           (infix[i] != right))
        {
            postfix[pFCount] = infix[i];
            pFCount++;
            cout<<infix[i]<<endl;
        }
        
        else if(infix[i] == left) //Left Paranthesis
        {
            i2fStack->push(left - '0');
        }
        
        else if(infix[i] == carr) //Carrot
        {
            i2fStack->push(carr - '0');
        }
        
        else if(infix[i] == mult) // Multiplication
        {
            if(!i2fStack->isEmpty() && i2fStack->peek() == div - '0')
            {
                long value = i2fStack->pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                cout<< value + '0';
                
            }
            
            i2fStack->push(mult - '0');
        }
        
        else if(infix[i] == div) //Division
        {
            if(!i2fStack->isEmpty() && i2fStack->peek() == mult - '0')
            {
                long value = i2fStack->pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                cout<< value + '0';
                
            }
            
            i2fStack->push(div - '0');
        }
        
        else if(infix[i] == add) // Addition
        {
            if(!i2fStack->isEmpty() && i2fStack->peek() == sub - '0')
            {
                long value = i2fStack->pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                cout<< value + '0';
            }
            
            i2fStack->push(add - '0');
            
        }
        
        else if (infix[i] == sub) //Substraction
        {
            if(!i2fStack->isEmpty() && i2fStack->peek() == add -'0')
            {
                long value = i2fStack->pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                cout<< value + '0';
            }
            
            i2fStack->push(sub - '0');
        }
        
        else if(infix[i] == right) //Write Parathesis
        {
            long value;
            while(i2fStack->peek() != left - '0')
            {
                value = i2fStack->pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                cout<< value + '0';
            }
            
            if(i2fStack->peek() == left - '0')
            {
                value = i2fStack->pop();
            }
        }
    }
    
    for(int j = pFCount; j < infixSize; j++)
    {
        long value = i2fStack->pop();
        char remains = value + '0';
        postfix[j] = remains;
        cout<<remains<<endl;
    }

}

long int eval_postfix(const char *postfix)
{
    return 0;
}
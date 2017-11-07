#include <iostream>
#include "string.h"
#include "stack.h"
#include <cmath>

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
    
    for(int i = 0; i < infixSize; i++) // regular numbers
    {
        if((infix[i] == '-') && (infix[i+1] != ' '))
        {
            postfix[pFCount] = '-';
            pFCount++;
        }
        
        if((infix[i] != mult) && (infix[i] != div) && (infix[i] != carr) &&
           (infix[i] != add ) && (infix[i] != sub) && (infix[i] != left) &&
           (infix[i] != right) && (infix[i] != ' '))
        {
            postfix[pFCount] = infix[i];
            pFCount++;
            if(infix[i + 1] == ' ')
            {
                postfix[pFCount] = ' ';
                pFCount++;
            }
            
        }
        
        else if (infix[i] == ' ')
        {
            //Do nothing 
        }
        else if(infix[i] == left) //Left Paranthesis
        {
            i2fStack -> push(left - '0');
        }
        
        else if(infix[i] == carr) //Carrot
        {
            i2fStack->push(carr - '0');
        }
        
        else if(infix[i] == mult) // Multiplication
        {
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == div - '0')
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' ';
                pFCount++;
                
            }
            
            i2fStack -> push(mult - '0');
        }
        
        else if(infix[i] == div) //Division
        {
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == mult - '0')
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' ';
                pFCount++;
                
            }
            
            i2fStack -> push(div - '0');
        }
        
        else if(infix[i] == add) // Addition
        {
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == sub - '0')
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' ';
                pFCount++;
            }
            
            i2fStack -> push(add - '0');
            
        }
        
        else if ((infix[i] == sub) && (infix[i+1] == ' ')) //Substraction
        {
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == add - '0')
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' ';
                pFCount++;
            }
            
            i2fStack -> push(sub - '0');
        }
        
        else if(infix[i] == right) //Right Parathesis
        {
            long value;
            while(i2fStack -> peek() != left - '0')
            {
                value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' ';
                pFCount++;
            }
            
            if(i2fStack -> peek() == left - '0')
            {
                value = i2fStack -> pop();
            }
        }
    }
    
    for(int j = 0; j < i2fStack -> getSize(); j++) //Adding the rest of the stack to the array 
    {           
            long value = i2fStack -> pop();
            char remains = value + '0';
            postfix[pFCount] = remains;
            pFCount++;
            postfix[pFCount] = ' ';
            pFCount++;
        //cout<<remains<<endl;
    }
    postfix[pFCount]='\0';

}

long int eval_postfix(const char *postfix)
{
    Stack* postFixEval = new Stack;
    long length = strlen(postfix);
    bool isNeg = false;
    int number = 0; // could be long
    int digit;
    int finResult = 0;
    
    char mult = '*';
    char div  = '/';
    char carr = '^';
    char add  = '+';
    char sub  = '-';
    
    for(int i =0; i< length; i++)
    {
        int j = i;
        //cout<<"updated"<<endl;
        if((postfix[i] == '-') && (postfix[i+1] != ' '))
        {
            isNeg = true;
        }
        while((postfix[j] != ' ') && postfix[j] != '+')
        {
            //cout<<postfix[j]<<endl;
            
            digit = (postfix[j] - '0');
            //cout<<"dig: "<<digit<<endl;
            number = (number*10) + digit;
            //Create number using digits; number =0 , (number*10) + new digit; - done
            //if needed push the number to stack - done
            //check to see if the number is negative; - done? // havent tested it out
            j++;
        }
        if(isNeg)
        {
            number = number * -1;
            isNeg = false;
        }
        cout<<"num: "<<number<<endl;
        postFixEval->push(number);
        //cout<<endl<<"J :"<<j<<endl;
        i = j;
        //cout<<"I :"<<i<<endl;
        number = 0;
        if(((postfix[i] == mult) || (postfix[i] == div) || (postfix[i] == carr) ||
           (postfix[i] == add )|| (postfix[i] == sub)) && (postfix[i+1] == ' '))
        {
            long right = postFixEval -> pop();
            long left  = postFixEval -> pop();
            long result;
            if(postfix[i] == mult)
            {
                result = left * right;
                postFixEval -> push(result);
            }
            
            else if(postfix[i] == div)
            {
                result = floor(double(left)/right);
                postFixEval -> push(result);
            }
            
            else if(postfix[i] == carr)
            {
                result = pow(left, right);
                postFixEval -> push(result);
            }
            
            else if(postfix[i] == add)
            {
                cout<<"here"<<endl;
                cout<<left<<" "<<right<<endl;
                result = left - right;
                cout<<"result"<<result<<endl;
                postFixEval -> push(result);
            }
            
            else if(postfix[i] == sub)
            {
                result = left - right;
                postFixEval -> push(result);     
            }
        }
    }
    int stackSize = postFixEval -> getSize();
    cout<<stackSize<<endl;
    if(stackSize == 1)
    {
        finResult = postFixEval -> pop();
    }
    cout<<"fin: "<<finResult<<endl;
    return finResult; 
}
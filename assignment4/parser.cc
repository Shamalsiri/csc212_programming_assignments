//Shamal Siriwardana
//CSC 212
//Programming Assignment 4
//11/08/2017

#include <iostream>
#include "string.h"
#include "stack.h"
#include <cmath>

using namespace std;

void infix2postfix(const char *infix, char *postfix)
{
    //Local Variable
    
    Stack *i2fStack = new Stack();
    
    char mult = '*';
    char div  = '/';
    char carr = '^';
    char add  = '+';
    char sub  = '-';
    char left = '(';
    char right= ')';
    
    int infixSize = (int)strlen(infix); //need the size of the array
    int pFCount = 0; // postfix (array) counter
    
    for(int i = 0; i < infixSize; i++) 
    {
        if((infix[i] == '-') && (infix[i + 1] != ' ')) //Check for negative numbers 
        {
            postfix[pFCount] = '-';
            pFCount++;
        }
        
        if((postfix[j] > '/') && (postfix[j] < ':')) //Regular numbers
        {
            postfix[pFCount] = infix[i];
            pFCount++;
            if(infix[i + 1] == ' ') //Check to see if more than 1 digit
            {
                postfix[pFCount] = ' ';
                pFCount++;
            }
            
        }
        
        else if (infix[i] == ' ') //Nothing to do when its a space
        {
            //Do nothing 
        }
        else if(infix[i] == left) //Left Paranthesis
        {
            i2fStack -> push(left - '0');
        }
        
        else if(infix[i] == carr) //Carrot
        {
            i2fStack -> push(carr - '0');
        }
        
        else if(infix[i] == mult) // Multiplication
        {
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == div - '0') //Check to see if the top of the Stack is a /
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
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == mult - '0') //Check to see if the top of the Stack is a *
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
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == sub - '0') //Check to see if the top of the Stack is a -
            {
                long value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' ';
                pFCount++;
            }
            i2fStack -> push(add - '0');
        }
        
        else if ((infix[i] == sub) && (infix[i + 1] == ' ')) //Substraction
        {
            if(!i2fStack -> isEmpty() && i2fStack -> peek() == add - '0') //Check to see if the top of the Stack is a +
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
            while(i2fStack -> peek() != left - '0') // Add the operator to the end of the String when the Right Parathesis 
            {
                value = i2fStack -> pop();
                postfix[pFCount] = value + '0';
                pFCount++;
                postfix[pFCount] = ' ';
                pFCount++;
            }
            
            if(i2fStack -> peek() == left - '0') // Make sure the left Paranthesis is removed from the Stack
            {
                value = i2fStack -> pop();
            }
        }
    }
    
    int size = i2fStack -> getSize();
    for(int j = 0; j < size; j++) //Adding the rest of the operators on the stack to the string
    {           
            long value = i2fStack -> pop();
            char remains = value + '0';
            postfix[pFCount] = remains;
            pFCount++;
            postfix[pFCount] = ' ';
            pFCount++;
    }
    
    postfix[pFCount] = '\0'; //Ending the String

}

long int eval_postfix(const char *postfix)
{
    //local variables 
    Stack* postFixEval = new  Stack();
    int postFixSize = (int)strlen(postfix);
    bool isNeg = false;
    long int number = 0;
    int j;
    int digit;
    long left, right;
    
    for(int i = 0; i < postFixSize; i++)
    {
        j = i;
        if((postfix[i] == '-') && (postfix[i + 1] != ' ')) //Check to see if the Number is Negative 
        {
            isNeg = true;
        }
        
        while((postfix[j] > '/') && (postfix[j] < ':')) //Calculate numbers (one's more than 1 digit)
        {
            digit = postfix[i] - '0';
            number = (number * 10) + digit;
            j++;
            i = j;
        }
        
        if(isNeg) //If Negaitve, make sure the number is negative 
        {
            number = number * -1;
        }
        
        
        if((postfix[i] == ' ') && (postfix[i - 1] > '/') && (postfix[i - 1] < ':')) //Add the number to the Stack and reset to default
        {
            postFixEval -> push(number);
            isNeg = false;
            number = 0;
        }
        
        else if((postfix[i] == '*') && (postfix[i + 1] == ' ')) //Multiply when needed
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = left * right;
            postFixEval -> push(number);
            number = 0;
        }
        
        else if ((postfix[i] == '^') && (postfix[i + 1] == ' ')) //Find the exponetial value when needed
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = pow(left, right);
            postFixEval -> push(number);
            number = 0;
        }
        
        else if ((postfix[i] == '/') && (postfix[i + 1] == ' ')) //Divide when needed
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = floor(double (left) / right);
            postFixEval -> push(number);
            number = 0;
        }
        
        else if ((postfix[i] == '+') && (postfix[i + 1] == ' ')) //Add when needed
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = left + right;
            postFixEval -> push(number);
            number = 0;
            
        }
        
        else if ((postfix[i] == '-') && (postfix[i + 1] == ' ')) //Subract when needed
        {
            right = postFixEval -> pop();
            left  = postFixEval -> pop();
            number = left - right;
            postFixEval -> push(number);
            number = 0;
        }
             
    }
    number = postFixEval -> pop(); //Get the final answer of the Evaluation 
    return number;
}
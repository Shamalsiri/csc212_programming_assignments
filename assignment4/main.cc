#include<iostream>
#include "stack.h"
#include "math.h"

using namespace std;

void infix2postfix(const char *infix, char *postfix);
long int eval_postfix(const char *postfix);//suppose to be eval_postfix


int main(int argc, const char * argv[])
{
    //const char A[] = "( 4 + 8 ) * ( 6 - 5 ) / ( ( 3 - 2 ) * ( 2 + 2 ) )";
    //const char A[] = "( -300 + 23 ) * ( 43 - -21 ) / ( 84 + 7 )";
    const char A[] = "1 + 2 - 3 * 4 / 5 ^ 6 ";
    int capacity = (int)strlen(A);
    char B[capacity+1];
    infix2postfix(A, B);
    cout<<B<<endl;
    
    //int size = (int)strlen(B);
    //cout<<size<<endl;
    //const char check[] = "33 12 + 12 4 -9 * / - ";
    
    long int chec = eval_postfix(B);
    cout<<chec<<endl;
    return 0;
}

#include<iostream>
#include "stack.h"

using namespace std;

void infix2postfix(const char *infix, char *postfix);

int main(int argc, const char * argv[])
{
    const char A[] = {'(','4','+','8',')','*','(','6','-','5',')','/','(','(','3','-','2',')','*','(','2','+','2',')',')'};
    int capacity = (int)strlen(A);
    char B[capacity+1];
    cout<<A<<endl;
    infix2postfix(A, B);
    cout<<endl<<capacity<<endl;
    for(int i =0; i < capacity + 1 ; i++)
    {
        cout<<B[i];
    }
    cout<<endl;
    return 0;
}
#include<iostream>
#include "stack.h"

using namespace std;

int main()
{
    const char A[] = {'1','+','2','*','3'};
    char B[6];
    infix2postflix(const char *A, char *B);
    cout<<endl;
    for(int i =0; i < 6; i++)
    {
        cout<<B[i];
    }
    return 0;
}
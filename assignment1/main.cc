#include "functions.h"
#include<string.h>
#include<cstring>
#include <cstdint>

using namespace std;

int main()
{
    //Q1
    int a = 4;
    int b = 8;
    int *ptr1 = &a;
    int *ptr2 = &b;
    q1_swap(ptr1, ptr2);
    cout<< "1. results : "<< *ptr1 << " " << *ptr2<<endl;
    
    //Q2
    int result = q2_positive_divisors(21);
    cout<<"2. results: "<<result<<endl;
    
    //Q3
    char str[] = "Hello";
    char *arr_ptr = &str[0];
    unsigned int result3 = q3_string_hash(arr_ptr);
    cout<<"3. result: "<<result3<<endl;
    
    //Q4
    double x[] = {1,2,3,4,5,6};
    double y[] = {1,2,3,4,5,6};
    double *xPtr = &x[0];
    double *yPtr = &y[0];
    unsigned long result4 = q4_diameter(6, xPtr, yPtr);
    cout<<"4. result: "<<result4<<endl;

    //Q5
    unsigned int result5 = q5_rotate(0, 2, 'R');
    cout<<"5. result: "<<result5<<endl;
    
    //Q6
    int result6 = q6_circular_prime(197);
    cout<<"6. result: "<<result6<<endl;
    
    //Q7
    char hex[] = {"7C2"};
    char *hexPtr = &hex[0];
    unsigned long int result7 = q7_any2dec(hexPtr,15);
    cout<<"7. result: "<<result7<<endl;
    
    //Q8
    char num[1000];
    char *numPtr = &num[0];
    q8_dec2any(342576, numPtr, 16);
    cout<<"8.result "<<num<<endl;
    
    return 0;
}

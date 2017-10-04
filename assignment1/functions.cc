//Shamal V Siriwardana
//ID: 100531147

#include "functions.h"
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

// Suplementry Function
// Takes an unsigned int n and return the number of digits
int numDigits(unsigned int n)
{
    int count = 0;
    if (n > 0)
    {
        while (n != 0)
        {
            n = n / 10;
            count++;
        }
    }
    return count;
}

//----------------------------------
//            Solutions
//----------------------------------

// Take two int pointers and swap their values
void q1_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Takes an unsigned long int a and check if a and a + 1 
// have the same number of divisors
int q2_positive_divisors( unsigned long int a)
{
    int aPlus1 = a + 1;
    int aDivisorCounter = 0;
    int aPlus1DivisorCounter = 0;
    for(int i = 1; i <= a; i++)
    {
        if(a % i == 0)
        {
            aDivisorCounter++;
        }
        if(aPlus1 % i == 0)
        {
            aPlus1DivisorCounter++;
        }
    }
    aPlus1DivisorCounter++;
    if(aDivisorCounter == aPlus1DivisorCounter)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Takes a string/char array and return the hash value
// hash value = The sum of ascii values of each of the charater in the string
unsigned long int q3_string_hash(const char *str)
{
    
    int length = 0;//sizeof(str);//strlen(str);
    while(str[length] != '\0')
    {
        length++;
    }
    unsigned long int stringHash = 0;
    //cout<< "length: "<< length << endl;
    for (int i = 0; i < length; i ++)
    {
        int asciiValue = int(str[i]);
        //cout<<"ascii value: "<<asciiValue<<endl;
        stringHash += asciiValue;
    }
    return stringHash;
}

// Take an array of x coordinate, an array of y cordinates and the size of the array 
// and check for the largest distance between any 2 points
unsigned long q4_diameter(unsigned int n, const double *x, const double *y)
{
    if(n == 0)
    {
        return 0;
    }
    unsigned long largestDist = 0;
    int indexOfOrignPoint;
    int indexOfEndPoint;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            double diffX = x[j] - x[i];
            double diffY = y[j] - y[i];
            unsigned long dist = sqrt( pow (diffX,2) + pow (diffY,2) );
            if (largestDist < dist)
            {
                largestDist = dist;
                indexOfOrignPoint = i;
                indexOfEndPoint = j;
            }
        }       
    }
    return largestDist;
}

// Take an unsigned in n, unsigned int r and a char d either 'r' or 'l' and rotate n
// by r positions in the specified direction by d
unsigned int q5_rotate(unsigned int n, unsigned int r, char d)
{
    if (n == 0)
    {
        return n;
    }
    if(r == 0 || (r % 7) == 0)
    {
        return n;
    }
    else
    {
        int numOfDigits = numDigits(n);
        int newR;
        // Simplifying the r value if it's larger than the number of digits
        if ( r > numOfDigits)
        {
            int multiple = r / numOfDigits;
            newR = r - (numOfDigits * multiple);
        }
        else
        {
            newR = r;
        }
        
        // n is broken into individual digits and stored in an array
        int intArray[numOfDigits];
        for(int j = numOfDigits - 1; j >= 0; j--) 
        {
            intArray[j] = n % 10;
            n= n / 10;  
        }

        int tempArray[numOfDigits];
        int tACount = 0;
        int lengthMinR = numOfDigits - newR;
        int iACount = 0;

        // If the direction is right, the following code will run
        if (d == 'R' || d == 'r')
        {
            int frstDgtPositn = numOfDigits - lengthMinR;
            for(int i = lengthMinR; i<numOfDigits; i++)
            {
                tempArray[tACount] = intArray[i];
                tACount++;
            }
            for(int k = frstDgtPositn; k < numOfDigits; k++)
            {
                tempArray[k] = intArray[iACount];
                iACount++;
            }
        }

        // If the direction is left, the following code will run
        else if (d == 'L' || d == 'l')
        {
            for(int i = newR; i < numOfDigits; i++)
            {
                tempArray[tACount] = intArray[i];
                tACount++;
            }
            for(int k = lengthMinR; k < numOfDigits; k++)
            {
                tempArray[k] = intArray[iACount];
                iACount++;
            }
        }

        // The follwoing code take the array of the rotated numbers and
        // create the int
        unsigned int finalResult = 0;
        for(int i = 0; i < numOfDigits; i++)
        {
            int temp2 = tempArray[i];
            if (temp2 != 0)
            {
                while(temp2 > 0)
                {
                    finalResult = finalResult * 10;
                    temp2 = temp2 / 10;
                }
                finalResult = finalResult + tempArray[i];
            }
            else
                finalResult = finalResult * 10;
        }
        return finalResult;
    }
}

// Take a unsigned int a and if it and all it's digit rotations are prime
int q6_circular_prime(unsigned int a)
{
    // Check is a is 1 or 0
    if(a == 1 || a == 0)
    {
        return 0;
    }
    // Call numDigits to get the length of the int
    int numOfDigits = numDigits(a);
    
    for(int i = 0; i<numOfDigits; i++)
    {
        // Call q5_rotate to rotate the digits
        unsigned int number = q5_rotate(a, i, 'R');
        for(int j = 2; j < number; j++)
        {
            if((number % j) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Take a string/ char array with a Hex values stored and a int b 
// and conver the string from Hex to Decimal given Base b
unsigned long int q7_any2dec(const char *num, int b)
{
    unsigned long int decimalVal = 0;
    char hex[ ] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int hexVals[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    //int exponent = strlen(num) - 1;
    int exponent = 0;
    while(num[exponent] != '\0')
    {
        exponent++;
    }
    //cout<<"exponent "<<exponent<<endl;
    int length = exponent;
    for(int i = 0; i <= length; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if(num[i] == hex[j])
            {
                decimalVal += (hexVals[j] * floor(pow(b,exponent-1)));
                exponent--;
            }
        }
    }
    return decimalVal;
}

// Take an int d, a pointer to a char array/string and int b and 
// convert d into Hex given b and store in the string 
void q8_dec2any(unsigned int d, char *num, int b)
{
    int nHex[10000];
    int count = 0;
    char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int hexVals[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int numIndex = 0;
    if (d == 0)
    {
        num[0] = '0';
    }
    else
    {
        while(d != 0)
        {
            int random = d % b;
            nHex[count]=random;
            d = d / b;
            count++;    
        }
        for(int i = count - 1; i>=0; i--)
        {
            for (int j = 0; j<b; j++)
            {
                if(nHex[i] == hexVals[j])
                {
                   num[numIndex] = hex[j];
                   numIndex++;
                }
            }
        }
    }
}


/*int main()
{   
    int a = 4;
    int b = 8;
    int *ptr1 = &a;
    int *ptr2 = &b;
    q1_swap(ptr1, ptr2);
    cout<<"Orignal numbers in order: 4 8"<<endl;
    cout<< "1. results : "<< *ptr1 << " " << *ptr2<<endl;
    
    int result = q2_positive_divisors(21);
    cout<<"Orignal number to check: 21"<<endl;
    cout<<"2. results: "<<result<<endl;
    
    char str[] = "Hello";
    char *arr_ptr = &str[0];
    unsigned int result3 = q3_string_hash(arr_ptr);
    cout<<"Orignal String: 'Hello' Expected value : 500"<<endl;
    cout<<"3. result: "<<result3<<endl;
    
    
    double x[] = {1,2,3,4,5,6};
    double y[] = {1,2,3,4,5,6};
    double *xPtr = &x[0];
    double *yPtr = &y[0];
    unsigned long result4 = q4_diameter(6, xPtr, yPtr);
    cout<<"Coordinates sent: (1,1), (2,2), (3,3), (4,4), (5,5), (6,6)"<<endl;
    cout<<"4. result: "<<result4<<endl;

    unsigned int result5 = q5_rotate(0, 2, 'R');
    cout<<"original num: "<<0<<" rotation: "<<2<<"Direction: R"<<endl;
    cout<<"5. result: "<<result5<<endl;
    
    int result6 = q6_circular_prime(197);
    cout<<"Orignal number to check: 197"<<endl;
    cout<<"6. result: "<<result6<<endl;
    
    char hex[] = {"7C2"};
    char *hexPtr = &hex[0];
    unsigned long int result7 = q7_any2dec(hexPtr,15);
    cout<<"Hex value to check 'AF' Base: 1 Expected: 175"<<endl;
    cout<<"7. result: "<<result7<<endl;
    
    char num[1000];
    char *numPtr = &num[0];
    q8_dec2any(342576, numPtr, 16);
    cout<<"Orignal number to check: 342576 Base: 16 Expected: 53A30"<<endl;
    cout<<"8.result "<<num<<endl;

    return 0;
}*/
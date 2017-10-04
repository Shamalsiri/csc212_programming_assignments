
#include "functions.h"
#include<iostream>
#include<string.h>

using namespace std;

unsigned int q1_mode(const int *A, unsigned int n)
{
    return 0;
}

//done
unsigned int q2_unique(const int *A, unsigned int n)
{
    int uniqueCount =0;
    for(int i =0; i<n; i++)
    {
        bool unique = true;
        for(int j = 0; j<n ;j++)
        {
            if(i!=j && A[i] == A[j])
            {
                unique = false;
            }
        }
        if(unique)
        {
            uniqueCount++;
        }
    }
    return uniqueCount;
    
}

//done
bool q3_is_sorted(const int *A, unsigned int n)
{
    int largest = A[n-1];
    for(int i = n-2; i >=0; i--)
    {
        if(largest<A[i])
        {
            return false;
        }
        else
        {
            largest = A[i];
        }
    }
    return true;
}

//done
unsigned int q4_insertion_sort(int *A, unsigned int n)
{
    int j;
    int temp;
    int swapCount = 0;
    
    for(int i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        while((temp < A[j]) && (j >= 0))
        {
            A[j + 1] = A[j];
            swapCount++;
            j--;
        }
            A[j + 1] = temp;           
    }  
    return swapCount;
}

unsigned int q5_selection_sort(int *A, unsigned int n)
{
  
    return 0;
}

//done
bool q6_palindrome(const char *str, unsigned int len)
{
    bool result;
    int length = (int) strlen(str)-len;
    if((str[0] == '\0') || (length ==1))
        return true;
    if(len<((strlen(str)/2)+1))
        return true;
    if(str[length]==str[len-1])
        result = q6_palindrome(str, len-1);
    else
        result = false;
    return result;
}

//done
void q7_reverse(char*str, unsigned int len)
{
    int length = strlen(str);
    char temp = str[len-1];
    if(len != length/2)
    {
        str[len-1] = str[length - len];
        str[length - len] = temp;
        q7_reverse(str, len-1);
    }
    cout<<str<<endl;
}

void q8_print_reversed_letters(const char *str)
{
    int size = sizeof(str);
    char subs[size-2];
    memcpy(subs, str, size-2);
    if (size > 0)
    {
        if(((int)str[size-1]>96) && (int)str[size -1 ] < 123)
        {
            cout<<str[size-1];
            q8_print_reversed_letters(subs);    
        }
        else
        {
            q8_print_reversed_letters(subs);
        }
    }
}
//done
unsigned long int q9_suffix_sum(unsigned int n, unsigned int s)
{
    unsigned int some = (n - s) + 1;
    if(s == 1)
    {
        return some;
    }
    else
    {
        return some + q9_suffix_sum(n, s - 1);
    }
}

//done
unsigned int q10_sum_digits(unsigned int num)
{
    if((num < 10) && (num % 2 == 0))
    {
        return num;
    }
    else
    {
        int digit = num % 10;
        
        if(digit % 2 == 0)
        {
            return digit + q10_sum_digits(num/10);
        }
        else
        {
            return q10_sum_digits(num/10);
        }
    }
}

bool q11_r_bin_search(const int *A, unsigned int n, int k)
{
    return true;
}

//done
bool q12_sorted(const int *A, unsigned int n)
{
    if(n <= 0)
    {
        return false;
    }
    if(n == 1)
        return true;
    else if (A[n-2] < A[n-1])
    {
        return false;
    }
    return q12_sorted(A, n-1);
}
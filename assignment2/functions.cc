//Shamal Siriwardana
//URI ID: 100531147

#include "functions.h"
#include<iostream>
#include<string.h>

using namespace std;

//done
unsigned int q1_mode(const int *A, unsigned int n)
{
    int temp[n];
    for(int i = 0; i < n; i++)
    {
        temp[i] = 0;
        for(int j = 0; j <= i; j++)
        {
            if(A[i] == A[j])
            {
                temp[i]++;
            }
        }
    }
    int highest = n - 1;
    for(int k = n - 2; k >= 0; k--)
    {
        if(temp[highest] < temp[k])
        {
            highest = k;
        }
    }
    return highest;
}

//done
unsigned int q2_unique(const int *A, unsigned int n)
{
    int temp[n];
    for(int q =0; q<n; q++)
    {
        temp[q] = A[q];
    }
    int uniqueCount = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(i != j && temp[i] == temp[j])
            {
                temp[j] = 1001;
            }
        }
    }
    
    for(int k =0; k<n; k++)
    {
        if(temp[k] != 1001)
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

//done
unsigned int q5_selection_sort(int *A, unsigned int n)
{
    int minIndex;
    for(int i = 0; i< n ; i++)
    {
        minIndex = i;
        for(int j = i+1; j< n; j++)
        {
            if(A[minIndex] > A[j])
            {
                minIndex = j;
        
            }
        }
        
        unsigned int temp = A[minIndex];
        A[minIndex] = A[i];
        A[i] = temp;
        
    }
    return n-1;
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


void q7_reverse(char *str, unsigned int len)
{
    if(&str-len != &str)
    {
        cout<<"1"<<endl;
        q7_reverse(str+1,  len -1);
    }
    
    
}

//done
void q8_print_reversed_letters(const char *str)
{   
    if(*str == '\0')
    {
        return;
    }
    q8_print_reversed_letters(str + 1);
    if(islower(*str))
    {
        cout<<*str;
    }
}

//done
unsigned long int q9_suffix_sum(unsigned int n, unsigned int s)
{
    unsigned int startpo = (n - s) + 1;
    if(s == 1)
    {
        return startpo;
    }
    else
    {
        return startpo + q9_suffix_sum(n, s - 1);
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
    
    int highMinLow = (&A[n-1] - A);
    int mid = highMinLow/2;
    if(n < 1)
    {
        return false;
    }
    if(A[mid] ==  k)
    { 
        return true;
    }
    else if(A[mid] > k)
    {
        if(*(A + mid + 2) == A[n - 1])
        {
            return true;
        }  
        return q11_r_bin_search(A + mid + 1, n - mid, k);
        
    }
    else if(A[mid] < k)
    {
        return q11_r_bin_search(A, mid, k);
    }
    else
    {
        return false;
    }
    
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

//done
void q13_draw_triangle(unsigned int a, unsigned int b, unsigned int c)
{
    if(a <= b)
    {
        for (int j = 0; j < a; j++)
        {
            cout<<"+";
        }
        cout<<endl;
        q13_draw_triangle(a + c, b, c); 
        for(int i = 0; i< a; i++)
        {
            cout<<"+";
        }
        cout<<endl;
    }

}

void q14_print_pattern(unsigned int len, unsigned int col)
{
    for(int i = 0; i < col; i++)
    {
        cout<<" ";
    }
    cout<<"|"<<endl;
    
}

unsigned int q15_reverse_words(char *str, unsigned int idx)
{
    int length = strlen(str);
    
    cout<< length <<endl;
    
    return length;
}

#include "functions.h"
#include<string.h>
#include<cstring>
#include <cstdint>

using namespace std;
int main()
{
    //Q1
    
    
    //Q2 -- done
    int B[] = {9,8,7,6,5,4,3,2,1};
    unsigned int result2 = q2_unique(B,9);
    cout<<"q2 :"<<result2<<endl;
    
    //Q3 -- done
    int C[] = {9,8,7,6,5,4,3,2,1};
    bool result3 = q3_is_sorted(C,9);
    cout<<"q3 :"<<result3<<endl;
    
    //Q4 -- done
    int D[] = {9,8,7,6,1,4,3,2,1};
    int result4 = q4_insertion_sort(D,9);
    cout<<"q4 :"<<result4<<endl;

    //Q5
        
    //Q6 -- done
    char F[] = "mom";
    bool result6 = q6_palindrome(F, 4);
    cout<<"q6 :"<<result6<<endl;
    
    //Q7 -- done
    char G[] = "SHAMALCAROLYN!";
    q7_reverse(G,14);

    //Q8 
    const char H[] = "csc-212 IS olleh";
    //int size = sizeof(H);
    //char subs[size-2];
    //memcpy(subs, H, size-2);
    //cout<<subs<<endl;
    q8_print_reversed_letters(H);
    
    //Q9 -- done
    unsigned long int  result9 = q9_suffix_sum(100,2);
    cout<<"q9 :"<<result9<<endl;
     
    //Q10 -- done
    unsigned int result10 = q10_sum_digits(10224);
    cout<<"q10: "<<result10<<endl;
    
    //Q12 -- done
    const int L[] = {6,5,4,3,2,1};
    bool result12 = q12_sorted(L, 1);
    cout<<"q12:"<<result12<<endl;
    
    
    
    return 0;
}
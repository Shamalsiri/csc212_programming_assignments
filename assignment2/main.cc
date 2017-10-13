#include "functions.h"
#include<string.h>
#include<cstring>
#include <cstdint>

using namespace std;
int main()
{
    
    //Q1 -- done
    const int A[]= {9,3,2,1,15,9,8,10,9};
    unsigned int result1 = q1_mode(A,9);
    cout<<"q1 :"<<result1<<endl;
 
    //Q2 -- done
    int B[] = {9,8,7,6,5,4,3,2,1};
    unsigned int result2 = q2_unique(B,9);
    cout<<"q2 :"<<result2<<endl
    
    //Q3 -- done
    int C[] = {9,8,7,6,5,4,3,2,1};
    bool result3 = q3_is_sorted(C,9);
    cout<<"q3 :"<<result3<<endl;
    
    //Q4 -- done
    int D[] = {9,8,7,6,1,4,3,2,1};
    int result4 = q4_insertion_sort(D,9);
    cout<<"q4 :"<<result4<<endl;

    //Q5 -- done
    int E[] = {3,2,1};//{34,17,2,23,45,9,35,1}; //{15,22,35,15,8,100,13,1,55,70};
    int result5 = q5_selection_sort(E, 3);
    cout<<"q5 :"<<result5<<endl;
        
    //Q6 -- done
    char F[] = "mom";
    bool result6 = q6_palindrome(F, 4);
    cout<<"q6 :"<<result6<<endl;

    //Q7 
    char G[] = "SHAMAL CAROLYN!";
    q7_reverse(G,14);

    //Q8 -- done
    const char H[] = "csc-212 IS olleh";
    q8_print_reversed_letters(H);
    cout<<endl;
   
    //Q9 -- done
    unsigned long int  result9 = q9_suffix_sum(100,2);
    cout<<"q9 :"<<result9<<endl;
     
    //Q10 -- done
    unsigned int result10 = q10_sum_digits(10224);
    cout<<"q10: "<<result10<<endl;

    //q11 
    const int I[] ={25,23,19,16,15,12,7,6,3,1};
    bool result11 = q11_r_bin_search(I, 10, 1);
    cout<<"q11:"<<result11<<endl;

    //Q12 -- done
    const int L[] = {6,5,4,3,2,1};
    bool result12 = q12_sorted(L, 1);
    cout<<"q12:"<<result12<<endl;

    //Q13 -- done
    q13_draw_triangle(4,7,1);   
    
    //Q14 
    q14_print_pattern(8,0);
    
    //Q15
    char str[]={"Hello  world hits"};
    unsigned int result15 = q15_reverse_words(str, 0);
    cout<<"q15:"<<result15<<endl;
    
    
  
    return 0;
    
   
    
}
# Programing Assignment 2

## Question 1
Create a function `q1_mode` that finds the index of the value that occurs more often in an array. The input to your function is an array of integers `A` and the number of elements in the array 0 < `n` ≤ 1000. Assuming `v` is the most frequent element in the array, your function will return the index `i` of the last occurrence of `v` in `A`. Ties should always be broken by returning the rightmost index. You can assume that -500 ≤ `A[i]` ≤ 500, for 0 ≤ i < n.

    unsigned int q1_mode(const int *A, unsigned int n);

## Question 2

Create a function `q2_unique` that returns the number of unique elements in the array. The input to your function is an array of integers `A` and the number of elements in the array 0 < `n` ≤ 1000. You can assume that -500 ≤ `A[i]` ≤ 500,n  for 0 ≤ `i` < `n`.

    unsigned int q2_unique(const int *A, unsigned int n);
    
## Question 3

Create a function `q3_is_sorted` that checks whether an array is sorted in non-decreasing order. The input to your function is an array of integers `A` and the number of elements in the array 0 < `n` ≤ 1000. Your function myst run in linear time and will return `true` if A is sorted and `false` otherwise.

    bool q3_is_sorted(const int *A, unsigned int n);
    
## Question 4

Create a function `q4_insertion_sort` that implements the insertion sort algorithm. The input to your function is an arrray of integers `A` and the number of elements in the array 0 < `n` ≤ 1000. Your function will write in `A` the input sequence sorted in non-decreasing order. Your function will also return the minimum number of exchanges (swaps) needed to sort the input sequence. 

    unsigned int q4_insertion_sort(int *A, unsigned int n);

## Question 5

Create a function `q5_selection_sort` that implements the selection sort algorithm. The input to your fucntions is an array of intergers `A` and the number of elements in the aray 0 < `n` ≤ 1000. Your function will write in `A` the input sequence sorted in non-decreasing order. your function will also return the minimum number of  exchanges (swaps) needed to sort the unput sequence. 

    unsigned int q5_selection_sort(int *A, unsigned int n);

## Question 6

Write a recursive function `q6_palindrome` that will return `true` if an input string `str` of length 0 ≤ `len` ≤ 1000 is a palindrome and `false` otherwise. The empty string is a palindrom and a string constituted only by a single character is a palindrome. 

    bool q6_palindrome(const char *str, unsigned int len);

## Question 7

Write a recursive function `q7_reverse` that will reverse (in-place) a sequence of characters of lenght 0 ≤ `len` ≤ 1000.

    void q7_reverse(char *str, unsigned int len);

## Question 8

Write a recursive function `q8_printreversed_letters` that takes a string `str` as input and output to the standard output the lowe- case letters in `str` in reverse order. For example, if the innput is "csc-212 IS olleh" your function should pring "hellocsc" to the stdout.

    void q8_print_reversed_letters(const char *str);

## Question 9

Write a recursive fucntion `q9_sufix_sum` that, given positve integers 1 ≤ `n` ≤ 10000 and 1 ≤ `s` ≤ n as input, will return the sum of the last `s` elements in the sequence from 1 to `n` (inclusive).

    unsigned long int q9_suffix_sum(unsigned int n, unsigned int s);

 ## Question 10

Write a recursive function `q10_sum_digits` that, given a positve integer `num` > 0 as input, will return the sum of all digits in `num` that are divisible by 2. 

    unsigned int q10_sum_digits(unsigned int num);

## Question 11

 Write a recursive runction `q11_r_bin_search` that will return `true` if an element `k` is found in an array of integers `A` and `false` otherwise. The input to your function is an array of integers `A`, the numebr of elements in the array 0 < `n` ≤ 10000, and the value of `k`. Assume that elements in `A` are sorted in non-increasing order. Your algothum must rub in )(log n) time.
 
    bool q11_r_bin_search(const int *A, unsigned int n, int k);

## Question 12

Write a recurisve function `q12_sorted` that returns `true` if the sequence of `n` > 0 integers in `A` is sorted in non-increasing order and `false` otherwise.

    bool q12_sorted(const int *A, unsigned int n);

## Question 13

Write a recursive function `q13_draw_triangle` that, takes positive integers a,b, and c as input, where 0 < a ≤ b and 0 < c. Your function will print some lines to the `stdout`. Each line can only contain the character `'+'`. The first line will contain `a` characters, the next `a + c` characters, the next `a + c + c` characters, and so on, as long as each line contains at most `b` characters. Then the pattern is repeated backwards. For example, calling  `q13_draw_triangle(4,7,1)` will output: 

    ++++
    +++++
    ++++++
    +++++++
    +++++++
    ++++++
    +++++
    ++++
<span style="color:white"> . </span>

    void q13_draw_triangle(unsigned int a, unsigned int b, unsigned int c);

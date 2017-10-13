#ifndef __FUNCTIONS__H__
#define __FUNCTIONS__H__

#include<iostream>

using namespace std;

unsigned int q1_mode(const int *A, unsigned int n);
unsigned int q2_unique(const int *A, unsigned int n);
bool q3_is_sorted(const int *A, unsigned int n);
unsigned int q4_insertion_sort(int *A, unsigned int n);
unsigned int q5_selection_sort(int *A, unsigned int n);
bool q6_palindrome(const char *str, unsigned int len);
void q7_reverse(char *str, unsigned int len);
void q8_print_reversed_letters(const char *str);
unsigned long int q9_suffix_sum(unsigned int n, unsigned int s);
unsigned int q10_sum_digits(unsigned int num);
bool q11_r_bin_search(const int *A, unsigned int n, int k);
bool q12_sorted(const int *A, unsigned int n);
void q13_draw_triangle(unsigned int a, unsigned int b, unsigned int c);
void q14_print_pattern(unsigned int len, unsigned int col);
unsigned int q15_reverse_words(char *str, unsigned int idx);

#endif
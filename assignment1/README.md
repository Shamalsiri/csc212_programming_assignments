# Programming Assignment 1

The problem set below is meant to get you started with writing source code in C/C++.

This assignment is to be completed individually. You are not allowed to share your source code with anybody else. The assignment is worth a total of
100 points. If you have any questions, visit us during office hours and/or post those questions on Piazza using the appropriate folder tag.

## Question 1

Create a function `q1_swap` that takes 2 pointers to integers `a` and `b` as input arguments. Your function does not need to return anything, but should swap the values pointed by `a` and `b` in memory.

`void q1_swap(int *a, int *b);`

## Question 2

Create a function `q2_positive_divisors` that takes an integer `a` as input, such that 1 < `a` < 10<sup>10</sup> and checks whether`a` and `a+1` have the same number of positive divisors. For example 21 has 4 positive divisors {1,3,7,21} and 22 has 4 positive divisors {1,2,11,22}. Your function will return `1` if `a` and `a+1` have the same number of positive divisors and `0` otherwise.

`int q2_positive_divisors(unsigned long int a);`

## Question 3

Create a function `q3_string_hash` that takes a string (character array) `str` as an input parameter and returns its hash value. The hash value for this problem is defined as the sum of all characters in the string, in fact, the sum of their ascii values.

`unsigned long int q3_string_hash(const char *str);`

## Question 4

Create a function `q4_diameter` that, given a finite set `P` of 2D points, calculates the floor of the largest (euclidean) distance between any two points of `P`. The input to your function is the number of points `n > 0`, an array of `x` coordinates, and an array of `y` coordinates for each of the points (if `n = 0`, diameter is `0`)

`unsigned long q4_diameter(unsigned int n, const double *x, const double *y);`

## Question 5

Create a function `q5_rotate` that takes unsigned 0 ≤ `n` < 2<sup>32</sup> or 0 ≤ `r` < 2<sup>32</sup> and a character `d` as input and return other integer which rotate a rotation of `r` by `n` positions to the right if `d = 'r'` or to the left if `d = ' l'`. For example, for n = 24579 and `r = 2` and `d = 'r'`, your function should return 79245. (cannot transform an integer to string using built-in function)

`unsigned int q5_rotate(unsigned int n, unsigned int r, char d);`

## Question 6

A number is called a circular prime if all rotations of the digits are themselves a prime. For example, the number 197 is a circular prime because all rotations of its digits: {197, 971, 719} are primes. Write a function `q6_circular_prime` that will take an integer `a`, such that 0 ≤ `a` < 10<sup>9</sup>, as input and return `1` if `a` is a cicular prime and `0` otherwise. (cannot transform an integer to string using built-in functions)

`int q6_circular_prime(unsigned int a);`

## Question 7

In the hexadecimal number system (base 16),  numbers are represented using 16 different digits: {0, 1, 2, 3, 4, 5, 6, 8, 9, A, B, C, D, E, F}. The hexadecimal number `AF` when written in the decimal number system equals 10 ⋅ 16<sup>1</sup> + 15 ⋅ 16<sup>0</sup> = 175. Likewise, in a number system in base 11,  numbers are represented using 11 different digits: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A}. Write a function `q7_anydec` that returns the decimal number that corresponds to the input number `num` (with all letters being upper-case) in a given base `b` 1 < b ≤ 16. (cannot use any built-in function)

`unsigned long int q7_any2dec(const char *num, int b);`

## Question 8

In a similar way, write a function `q8_dec2any` that takes as inputs an unsigned integer 0 ≤ d < 2<sup>32</sup>, a base 1 < b ≤ 16, and an output argument `num`. Your function should return in num the representation of the decimal number `d` in base `b`. Assume that memory has already been allocated for the string `num`, with a maximum capacity of 10000 characters. The returned string must not contain any leading ‘0’s. For example for the decimal `d = 342576` and `b = 16` your function should return the string `"53A30"` (letters must be capitalized). (cannot use any built-in function)

`void q8_dec2any(unsigned int d, char *num, int b);`

## Submission and Grading

You will submit a single file named `functions.cc`.  If you eventually need to create additional functions, those should also be included in this file. You are required to use comments in all your functions and use proper coding style and indentation, otherwise points will be deducted.

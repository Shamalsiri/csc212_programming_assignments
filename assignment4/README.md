# Programming Assignment 4

## Arithmetic Expressions

An arithmetic expression is defined as a sequence of tokens delimited by whitespaces. Tokens can be operators, numbers, and left/right parentheses. For the purposes of this assignment, the following operators are considered:

* `-` subtraction and `+` addition
* `*` multiplication and `/` division (performs integer division)
* `^` exponentiation (exponent will always be >= 0)

The list above shows operators in order of precedence from lower to higher. Operators with the same precedence occurring in an expression should be evaluated from left to right (left associativity), with the exception of `^` which is right-associative. For example `5 - 2 + 3` should evaluate to `6` and `2 ^ 3 ^ 2` should evaluate to `512`.

Each number in an arithmetic expression is an integer number that may contain multiple digits and may be positive or negative. For example, ` 3 345 -129 0 +321 -1 ` are all valid numbers.

In this assignment, you can assume that all arithmetic expressions (infix and postfix) must have 0 leading and trailing whitespaces. Furthermore, all tokens in an expression must be separated by exactly 1 whitespace.```

***Infix Notation*** is the usual way to write arithmetic expressions in which every operator appears between two operands. More formally, an infix expression is recursively defined as follows:

```
1. any number is a valid infix expression
2. if E is an infix expression, then '( E )' is an infix expression
3. if E1 and E2 are infix expressions, and OP is an operator, then 'E1 OP E2' is an infix expression
```

***Postfix Notation*** is a way to write arithmetic expressions in which every operator follows its operands in the expression. More formally, a postfix expression is recursively defined as follows:

```
1. any number is a valid postfix expression
2. if P1 and P2 are postfix expressions, and OP is an operator, then 'P1 P2 OP' is a postfix expression
```

Parentheses are not necessary in postfix expressions because the order of operations is given by the order of operands and operators (from left to right). The table below shows several examples of equivalent infix and postfix arithmetic expressions.

| Infix Expression          | Postfix expression    | Result |
|---------------------------|-----------------------|--------|
| 1 + 2                     | 1 2 +                 | 3      |
| -10 + 20 * ( 30 / 2 )     | -10 20 30 2 / * +     | 290    |
| ( 5 + 3 ) * 12 / 3        | 5 3 + 12 * 3 /        | 32     |
| 33 + 12 - 12 / ( 4 * -9 ) | 33 12 + 12 4 -9 * / - | 46     |
| 1 + 2 - 3 * 4 / 5 ^ 6     | 1 2 + 3 4 * 5 6 ^ / - | 3      |


---
Note that, in this assignment, we define an integer division as a floor division. That explains why in the table above `12/-36` is evaluated to `-1`, as `[-0.333333] = -1`.

---

## Question 1: Implementing a Stack (20 points)

You will design and implement a class for a Stack of (long) integers with ***at least*** the standard public methods `push`, `pop`, `isEmpty` (refer to the class shown below). Your stack must be implemented in the files `stack.h` and `stack.cc`. You may choose to implement any underlying data structure, however, you ***cannot use a built-in container***. Some good candidates would be a singly linked list, a doubly linked list, or an array.

```
class Stack {

        private:
            // include here all your data members and/or private methods

        public:
            // public methods to be implemented in your Stack class
            Stack();
            ~Stack();

            void push(long int);
            long int pop();
            bool isEmpty();

    };
```

## Question 2: Transforming Infix to Postfix notation (40 points)

You will implement a function named `infix2postfix` that will perform a conversion of arithmetic expressions from infix notation to postfix notation. Your function will take an input argument `infix` (the infix expression) and write the equivalent expression in postfix notation to the output parameter `postfix`. hat memory has already been allocated for both arguments. The amount of memory available for `postfix` is exactly `n + 1`, in which `n` is the number of characters in `infix`. You can also assume that all infix expressions are syntactically correct.

    void infix2postfix(const char *infix, char *postfix);
    
The algorithm for transforming an infix expression into a postfix expression can be implemented using a stack of operators/parentheses. Start with an initially empty stack. Scan tokens from left to right and follow the rules below:

1. if left parenthesis, push it onto stack
2. if operator:
    * pop and write to the output string all consecutive operators that are either:
        * operators of higher precedence; or
        * left-associative operators of equal precedence
    * push the operator onto the stack
3. if right parenthesis, pop and write to the output string, all operators until a left parenthesis is popped off the stack
4. if number, it may be immediately written to the output string
5. if end of the string, pop and write to the output string, all operators until the stack is empty


## Question 3: Evaluating a postfix expression (40 points)

You will implement a function named `eval_postfix` that will evaluate an arithmetic expression in postfix notation. Your function will take an input argument `postfix` (the postfix expression) and return the value corresponding to the input expression. You can also assume that all postfix expressions are syntactically correct.

    long int eval_postfix(const char *postfix);

The algorithm for evaluating a postfix expression can be implemented using a stack of numbers. Start with an initially empty stack. Scan tokens from left to right and follow the rules below:

1. if number, push it onto the stack
2. if operator, pop two numbers (operands) from the stack, evaluate the operator on those numbers and push the result back to the stack
3. if end of the string, pop the number from the stack and return it

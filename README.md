# ONP-calculator
## Academic project for subject: Algorytmy i struktury danych
Stack and queue are implemented by me as a part of the task.
### Description of the task:

Write an integer calculator. Use the postfix notation to handle precedence of operators, functions and parentheses.

### Input:
n -number of formulas
n formulas, each in the form given below.
Each formula is a valid expression in an infix notation with functions and ends with a dot ('.'). Each token is separated by some whitespace characters. Each operand is a positive integer (although the result of an operation might be negative). Each operator is a single character and every function name consists only of capital letters.
The following operations are available, in the ascending order of priority:

a + b, a - b ;
a * b, a / b -all operations are made on integers, hence the results of division are rounded down (standard C '/' operator). You cannot divide by 0 (see the Output section);
IF(a, b, c) -if a>0 return b, otherwise c,
N a -unary negation, i.e. -a,
MIN( a1, a2, ... ), MAX(a1, a2, ...) -functions MIN and MAX do not have a restriction on the number of parameters;
( ... ) -parentheses.
### Output for each formula:
the formula in the postfix notation;
before executing each operation print the operator or function and the content of the stack;
the final result;
if you encounter a division by 0, print "ERROR" and move to the next expression.
### Additional remarks and hints:
Each instance of MINi and MAXi function has a specified number of arguments, i, in the postfix notation (see the example output)
Do not store the given expressions (i.e. in the infix notation), only the latest token should be sufficient. Consequently, you should count the arguments of MIN and MAX during the conversion. Additional instances of data structures might be required.
You may assume that all values will be withing range of int. Note that each token is separate.
Using the type string and data structures from libraries is forbidden.
For the full amount of points, a stack based on a list is required. In the case of a stack implemented using an array, the amount of points is scaled by 0.75.
This does not mean that stacks are the only permitted data structures. You can use additonal data structures to solve encountered difficulties beyond the basic algorithms from the lecture.
Remember to clean up any unused memory. Memory leaks will be penalized.
Examples can be found below the Polish version of the instruction.

### Example input:
```
4
MIN ( 100 , MAX ( 1 , 34 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) .
2 + MIN ( 100 , MAX ( 1 , 6 * 5 + 2 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) * 3 .
N 400 + ( 11 - ( 3 * 2 ) ) / 2 + N N 200 .
IF ( ( 6 + 8 ) , ( 4 / 2 ) , MIN ( 8 , 2 , 1 , 0 , 3 ) ) * 2 * 6 / N ( 3 ) .
```

### Example output:
```
100  1  34  2  MAX3  80  66  36  35  77  MIN4  50  60  MIN6
MAX3 2 34 1 100
MIN4 77 35 36 66 80 34 100
MIN6 60 50 35 80 34 100
34

2  100  1  6  5  *  2  +  2  MAX3  80  66  36  35  77  MIN4  50  60  MIN6  3  *  +
* 5 6 1 100 2
+ 2 30 1 100 2
MAX3 2 32 1 100 2
MIN4 77 35 36 66 80 32 100 2
MIN6 60 50 35 80 32 100 2
* 3 32 2
+ 96 2
98

400  N  11  3  2  *  -  2  /  +  200  N  N  +
N 400
* 2 3 11 -400
- 6 11 -400
/ 2 5 -400
+ 2 -400
N 200 -398
N -200 -398
+ 200 -398
-198

6  8  +  4  2  /  8  2  1  0  3  MIN5  IF  2  *  6  *  3  N  /
+ 8 6
/ 2 4 14
MIN5 3 0 1 2 8 2 14
IF 0 2 14
* 2 2
* 6 4
N 3 24
/ -3 24
-8
```
## All you see is for academic purposes and future job recruitment stage.

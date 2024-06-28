#include "sample-library/Multiply.h"
#define INTEGER int
// demo for #define and #if
// #define parses the code and replaces instances of the first word with the second
// #if can be used to include or exlcude lines of code based on a condition

#if 1
INTEGER Multiply(int a, int b) 
{
    INTEGER result = a * b;
    return result;

    //OR directly return a*b instead of creating a redundant intermediate variable;
}
#endif
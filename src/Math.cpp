#include <iostream>
//Replaces the declaration of Log since it is what the header file is
#include "header/Log.h"

#define INTEGER int

//Compiler differenciates
int Multiply(int a, int b) {
    int result = a * b;
    return result;
}

//Compuler automatically sees result = 10;
int Multiply2() {
    int result = 5 * 2;
    return result;
}

//Compiler calling another function
int Multiply3(int a, int b) {
    Log("Multiply");
    return a * b;
}

//Preprocessor examples (#if 1 = true, 0 = false)
#if 1
INTEGER MultiplyExample(int a, int b) {
    INTEGER result = a * b;
    return result;
#include "header/EndBrace.h"
#endif
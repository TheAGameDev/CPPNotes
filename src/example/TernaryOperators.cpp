#include "header/Headers.h"

//ternary operators are a substitute for if statements to clean up your code when assigning a value
//the example shows what the code would look like as an if statement vs a ternary operator
//ternary operators are slightly faster than running an if statement
void ternaryOperatorsExample() {
    int level = 1;
    int speed = 2;
    if (level > 5)
        speed = 10;
    else
        speed = 5;
    speed = level > 5 ? 10 : 5;
}
#include "header/Headers.h"

static void PrintSum(int a, int b) {
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

//because "++" is a post incriment operator, the return result will be 0 + 1 (In VS, it returns 1 + 0 however) (Also can change based on DEBUG/RELEASE mode)
//making "++" a pre incriment operator will instead result in 1 + 2 (2 + 2 in VS)
//the C++ library does not say what should happen for this type of behavior, therefore it is compiler dependant
//Therefore this code would be considered unreliable
void argumentEvaluationExample() {
    int value = 0;
    int value2 = 0;
    PrintSum(value++, value++);
    PrintSum(++value2, ++value2);
}
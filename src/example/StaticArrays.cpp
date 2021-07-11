#include "header/Headers.h"

//advantage of having a static array over a normal array is that you can get the size of a static array
//you can also access the iterator with a static array
//both array types are stored in the stack and use memory in the same way
void staticArrayExample() {
    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 1;
    int dataOld[5];
    dataOld[0] = 2;
    dataOld[4] = 1;
}
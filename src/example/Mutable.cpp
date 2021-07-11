#include "header/Headers.h"

//Mutable can also be used to change variables inside a lambda
//Would be in an instance where the lambda is by value and not by reference (not using "&")
void mutableExample() {
    int x = 8;
    auto f = [=]() mutable {
        x++;
        std::cout << x << std::endl;
    };
    f();
}

#include "header/Headers.h"

//unions are simply a type of type punning
//a union can only have 1 member
//in a union, the second member occupies the same space as the first member
void unionExample() {
    struct Union {
        union {
            float a;
            int b;
        };
    };
    Union u;
    u.a = 2.0F;
    std::cout << u.a << ", " << u.b << std::endl;
}

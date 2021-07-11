#include "header/Headers.h"

//type punning is basically access the raw memory and circumventing the use of types
//by converting the memory of an int to a double, it takes unfreed memory to make enough room for a double (can cause crashes and break your program, DANGEROUS CODE)
void typePunningExample() {
    int a = 50;
    double value = *(double*)&a;
    std::cout << value << std::endl;
}

struct EntityM {
    int x, y;
};

//type punning allows you to access the memory directly to retrieve data or set one set of data to something else
//in this case, you grab the memory address of the entity and print the x and y values off of the memory address
void typePunningExample2() {
    EntityM e = { 5, 8 };
    int* position = (int*)&e;
    std::cout << position[0] << ", " << position[1] << std::endl;
}

//this example takes the value of "y" from entity using a "char*", and assigns it to a variable (with the use of type punning)
//probably should never use code like this in a real world application, purely an example
void typePunningExample3() {
    EntityM e = { 5, 8 };
    int y = *(int*)((char*)&e + 4);
    std::cout << y << std::endl;
}
#include "header/Headers.h"

struct EntityB {
    static int x, y;

    //Prints x and y values
    void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

int EntityB::x;
int EntityB::y;

//static variables in a class are changed across all instances of the class
//"EntityB::x" would be the proper way of referencing static variables in classes
//static methods connot access static varaibles
void staticClassExample() {
    EntityB e;
    EntityB::x = 2;
    EntityB::y = 3;
    EntityB e1;
    EntityB::x = 5;
    EntityB::y = 8;
    e.Print();
    e1.Print();
}

//static variables are changed across multiple calls to the method (why this example is called 3 times)
void staticLocalExample() {
    static int i = 0;
    i++;
    LOG(i);
}

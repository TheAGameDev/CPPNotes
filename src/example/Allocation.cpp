#include "header/Headers.h"

struct Vector3B {
    float x, y, z;
};

//Stack vs Heap
void allocationExample() {
    int value = 5;
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    Vector3B vector;

    int* hvalue = new int;
    *hvalue = 5;
    int* harray = new int[5];
    harray[0] = 1;
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;
    Vector3B* hvector = new Vector3B();

    delete hvalue;
    delete[] harray;
    delete hvector;
}
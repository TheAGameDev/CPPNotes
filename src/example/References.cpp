#include "header/Headers.h"

static void increment(int value) {
    value++;
}

static void increment2(int* value) {
    (*value)++;
}

static void increment3(int& value) {
    value++;
}

//ampersand is in declaration for a reference, unlike an existing variable where it would get the memory address
//"ref" isn't another variable or a second variable
//ref changes the original variable and will still result with a == 2;
void referencesExample() {
    int a = 5;
    int& ref = a;
    ref = 2;
    LOG(a);
}

//by accessing the memory address of "a", we can directly change the value with the increment function without a reference being used
void referencesExample2() {
    int a = 5;
    increment2(&a);
    LOG(a);
}

//passing "a" through the increment3 function will modify the value directly by using a reference as a perameter
//this will result in a == 6 without the use of pointers
void referencesExample3() {
    int a = 5;
    increment3(a);
    LOG(a);
}

//By setting the reference to "b", it sets the original value of "a" to "b"
//the value of "a" will therefore equal 8
void referencesExample4() {
    int a = 5;
    int b = 8;
    int& ref = a;
    ref = b;
    LOG(a);
}

//By dereferenceing the pointer when setting the value, we can the first value of the pointer equal one thing and have another value of the same pointer be equal to another
void referencesExample5() {
    int a = 5;
    int b = 8;
    int* ref = &a;
    *ref = 2;
    ref = &b;
    *ref = 1;
    LOG(a);
    LOG(b);
}
#include "header/Headers.h"

//pointer points to a location of memory
//void pointer gets memory address of "var", "ptr" equals the memory address of "var"
//if "void*" is switched to "int*" instead for example, it still results in the same memory address
//types determine the amount of bytes of memory used, voids can be anything
//* after the type = pointer, * before variable of a pointer = number at pointer's memory address
void pointerExample() {
    int var = 8;
    int* ptr = &var;
    *ptr = 10;
    LOG(var);
}

//the "8" allocates 8 bytes of memory for the char
//memset uses pointer, value, size of memory (bytes)
//** = pointer of a pointer because a pointer itself is a variable
//memory stored in brackets is heap memory, and can be deleted when finished with it
//delete to get rid of unused heap memory
void pointerExample2() {
    char* buffer = new char[8];
    memset(buffer, 0, 8);
    char** ptr = &buffer;
    delete[] buffer;
    LOG(ptr);
}
#include "header/Headers.h"

//When the function gets called, R values will be used to create a L value
//You can only take a reference of a L value and not an R value
void SetValue(int value) {
}

//"i" and "a" are both considered L values
//"10" is an R value as its considered a temporary value
//L values are values that have memory storage
//By using const, you can have a reference of an R value (compiler makes temp variable to convert to L value)
void lRValuesExample() {
    int i = 10;
    int a = i;
    SetValue(i);
    SetValue(10);
    const int& b = 10;
}

static void PrintName2(const std::string& name) {
    std::cout << "[LValue] " << name << std::endl;
}

static void PrintName2(std::string&& name) {
    std::cout << "[RValue] " << name << std::endl;
}

//By using 2 "&&" it becomes an R value reference
//By using 1 "&" it becomes an L value reference
void lRValuesExample2() {
    std::string first = "A";
    std::string last = "Game";
    std::string full = first + last;

    PrintName2(first);
    PrintName2(first + last);
}
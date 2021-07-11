#include "header/Headers.h"

//every function gets compiled into CPU instructions
static void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

//By using the function without calling it, we get the memory address of those CPU instructions
//the type of "auto" is actually "void(*function)()" in this case
//instead of "auto" we could also use "typedef" or "using" to assign the function to a variable
void functionPointersExample() {
    auto function = HelloWorld;
    function();
    function();
}

static void PrintValue(int value) {
    std::cout << "Value: " << value << std::endl;
}

static void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) {
    for (int value : values)
        func(value);
}

//By using function pointers, we are allowed to pass a function as a perameter
//In this case, it applies the function to each element inside the std::vector
//It can also work with a lambda
void functionPointersExample2() {
    std::vector<int> values = { 1, 5, 4, 2, 3 };
    ForEach(values, PrintValue);
    ForEach(values, [](int value) {
        std::cout << "Lambda Value: " << value << std::endl;
    });
}

#include "header/Headers.h"

static void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) {
    for (int value : values)
        func(value);
}

//lambdas are a way to define a function without having to create a new function
//lamddas are a good way of running code that you want to run in the future
//you start off a lambda with "[]" which is used for captures
//captures are used to tell how you want to push variables in the lambda ("=" by value, "&" by reference)
//the example below uses lambdas to find a certain value in an iterator or to replace the purpose of an existing function
void lambdaExample() {
    std::vector<int> values = { 1, 5, 4, 2, 3 };
    auto it = std::find_if(values.begin(), values.end(), [](int value) {
        return value > 3;
    });
    std::cout << *it << std::endl;
    int a = 5;
    auto lambda = [=](int value) {
        std::cout << "Lambda Value: " << a << std::endl;
    };
    ForEach(values, lambda);
}

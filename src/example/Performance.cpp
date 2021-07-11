#include "header/Headers.h"

std::vector<std::future<void>> s_Futures;

static void Sync(int sizeIn) {
    int value = 0;
    for (int i = 0; i < sizeIn; i++) {
        value += (i + value);
    }
    std::cout << value << "\n";
}

//Will show how to take advantage of multiple cores
//With multi-threading, resources can't be modified across multiple threads at a time
//using "std::async" will put a task of a function to be done on another thread
void performanceExample() {
    s_Futures.push_back(std::async(std::launch::async, Sync, 50));
}

static void PrintName(std::string_view name) {
    std::cout << name << std::endl;
}

//strings allocate on the heap rather than the stack, so it can be performance taxing in large amounts
//std::string_view can help grab a string or parts of a string without allocating memory (includes chars)
//std::string can be replaced with const char* to remove all allocations on static strings
void stringPerformanceExample() {
    const char* name = ("AGame Player");
#if 0
    std::string first = name.substr(0, 5);
    std::string last = name.substr(6, 11);
#else
    std::string_view first(name, 5);
    std::string_view last(name + 6, 10); //10 is changed to 7 with the change to a const char*
#endif
    PrintName(first);
    PrintName(last);
}

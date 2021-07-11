#include "header/Headers.h"

//Strings heap allocate a lot of memory, thus being seen as not ideal for C++ programming
//C++ introduced small strings which are stack allocated rather than heap allocated (StringSize: 15- on the stack, 16+ on the heap)
//heap allocations may still happen in debug mode, but not in release mode (dependant on IDE)
void smallStringOptimizationExample() {
    std::string name = "AGame";
}
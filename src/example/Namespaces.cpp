#include "header/Headers.h"

//Example of a namespace
namespace agame {
    void Print(const char* text) {
        std::cout << text << std::endl;
    }
}

//Using "std::" will help determine which functions are from the "std" library vs other libraries and your own
//Primary purpose of namespaces is to avoid naming conflicts
void namespaceExample() {
    agame::Print(":>");
}
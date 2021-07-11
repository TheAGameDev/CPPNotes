#include "header/Headers.h"

//The Macro will replace every word of "WAIT" with "std::cin.get()"
#define WAIT std::cin.get()

//if you use a backslash when defining a macro, it will skip to the next line (allows for whole blocks of code to be replaced as a result)
void macroExample() {
    WAIT;
    LOG("Waited Successfully!");
}
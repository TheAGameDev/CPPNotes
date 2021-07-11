#include "header/Headers.h"

//An "if" statement will check a bool to see if it is true and run code from stored memory if so
//memory within if statements are always stored, therefore it may be unappealing to programs where memory is vital
//oftenly used with pointers to check if they are null ("if(ptr)" checks if pointer is not nullptr)
//"else if" used if the first if statement returns false
void ifExample() {
    int x = 5;
    bool comparisonResult = x == 5;
    if (comparisonResult) {
        Log("Hello World");
    }
    else if (x == 6) {
        Log("Hallo World");
    }
}
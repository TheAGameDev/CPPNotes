#include "header/Headers.h"

//the values of enums are stored as integers
//Enums can be stored as other values such as an "unsigned char" as seen below
//enums just give a name to certain values
enum EnumEx : unsigned char {
    A = 5, B, C
};

int a = 0;
int b = 1;
int c = 2;

//Enum values can replace the use of integers
void enumExample() {
    int value = B;
    if (value == B) {
        b = value;
    }
}
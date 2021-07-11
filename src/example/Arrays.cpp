#include "header/Headers.h"

//By creating array of 5, you allocate enough bytes of memory for 5 int elements
//Arrays start with 0
//"example[0]" sets the int of index 0 to 2
//the last index in this example would be the number "4" as the size was set to "5"
//by having an index larger than 4, you would get a memory excess error
//by accessing the memory adress of the array and dereferencing the index you want to change, you can also change the element of an array that way as well (Sets the element of index 3 in this case to 6)
void arrayExample() {
    int example[5];
    int* ptr = example;
    example[0] = 2;
    example[4] = 4;
    for (int i = 0; i < 5; i++)
        example[i] = 3;
    *(ptr + 2) = 6;
}

//By deleting the "another" array, we remove excess memory stored for the array after it's use
//cant get the size of an array with a function
//"count" is an example of how you could retrieve the size of the array in bytes (Only works with stack allocated arrays and not heap arrays)898
void arrayExample2() {
    int example[5];
    for (int i = 0; i < 5; i++)
        example[i] = 3;
    int* another = new int[5];
    for (int i = 0; i < 5; i++)
        another[i] = 3;
    delete[] another;
    int count = sizeof(example) / sizeof(int);
    LOG(count);
}
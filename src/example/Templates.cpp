#include "header/Headers.h"

//Prints int message to console
static void Print(int value) {
    std::cout << value << std::endl;
}

//Prints string message to console
static void Print(std::string value) {
    std::cout << value << std::endl;
}

//Prints float message to console
static void Print(float value) {
    std::cout << value << std::endl;
}

//T is a substityte for the type and therefore can accept any type
//the function is created every time it is called (with the type substitute)
template<typename T>
static void PrintT(T value) {
    std::cout << value << std::endl;
}

//If you want to have a message of any variable, you either need multiple functions or a template
//for every input type to print, a new function is required unless you have a template
//When built you can see that they both return the same outputs
void templateExample() {
    Print(5);
    Print("Hello");
    Print(5.5F);
    PrintT(5);
    PrintT("Hello");
    PrintT(5.5F);
}

//Calling PrintT except you define the type used
void templateExample2() {
    PrintT<int>(5);
    PrintT<std::string>("Hello");
    PrintT<float>(5.5F);
}

//creates a new Array class when called with the defined int parameter "N"
//Allows an array to be created of the type "T" as a second template perameter
template<typename T, int N>
class ArrayA {
private:
    T m_Array[N];
public:
    int getSize() const { return N; }
};

//Creates an array class with the int of 5 replacing "N"
//sets int as the typename
void templateExample3() {
    ArrayA<int, 5> array{};
    PrintT(array.getSize());
}
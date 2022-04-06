//C++ Notes created from The Cherno's videos and online courses (XCode/Visual Studio)
#include "header/Headers.h"
int ext = 2;

//Functions are declared when used
//Cannot have 2 functions of the same return type, name, and perameters or will result in linker error
//If declared function does not exist in another file, it will result in a linker error
int Multiply3(int a, int b);
void LogExt();

//Static = will only be used in this cpp file
//static code will only be looked for inside this cpp file from the linker
//static is like having "private:" in a class
static int Number(int n) {
    Log("Number");
    return n;
}

//TODO: Examples
void pointerExample();
void pointerExample2();
void ifExample();
void referencesExample();
void referencesExample2();
void referencesExample3();
void referencesExample4();
void referencesExample5();
void playerClassExample();
void playerClassExample2();
void logClassExample();
void staticClassExample();
void staticLocalExample();
void enumExample();
void constructorExample();
void destructorExample();
void inheritanceExample();
void virtualFunctionsExample();
void interfaceExample();
void arrayExample();
void arrayExample2();
void stringExample();
void stringExample2();
void stringLiteralExample();
void mutableExample();
void initializerListExample();
void ternaryOperatorsExample();
void createObjectsExample();
void newExample();
void implicitExample();
void explicitExample();
void operatorExample();
void objectLifetimeExample();
void objectLifetimeExample2();
void smartPointersExample();
void smartPointersExample2();
void copyExample();
void copyExample2();
void copyExample3();
void arrowExample();
void arrowExample2();
void vectorExample();
void vectorExample2();
void templateExample();
void templateExample2();
void templateExample3();
void allocationExample();
void macroExample();
void autoExample();
void staticArrayExample();
void functionPointersExample();
void functionPointersExample2();
void lambdaExample();
void namespaceExample();
void threadExample();
void timingExample();
void multidimensionalArrayExample();
void multidimensionalArrayExample2();
void sortingExample();
void typePunningExample();
void typePunningExample2();
void typePunningExample3();
void unionExample();
void virtualDestructorExample();
void castingExample();
void castingExample2();
void dynamicCastExample();
void benchmarkingExample();
void benchmarkingExample2();
void structuredBindingsExample();
void structuredBindingsExample2();
void optionalDataExample();
void multipleDataTypesInSingleVariableExample();
void storeAnyDataInSingleVariableExample();
void performanceExample();
void stringPerformanceExample();
void visualBenchmarkingExample(); //TODO: Update Example to demonstrate with VS
void singletonsExample();
void smallStringOptimizationExample();
void memoryAllocationExample();
void lRValuesExample();
void lRValuesExample2();
void argumentEvaluationExample();
void moveSemanticsExample();
void moveSemanticsExample2();
void dataStructuresExample();
void dataStructuresExample2();
void dataStructuresExample3();
void iteratorExample();
void iteratorExample2();
void mapsExamples();

int main() {
    Log("Type the example to load: ");
    std::string name;
    std::cin >> name;
    Log("-------------------------");
    if (name == "Math") { // Math
        std::cout << Multiply3(5, 8) << std::endl;
        std::cout << Number(1) << std::endl;
    } else if (name == "Pointer") { //Pointers
        pointerExample();
    } else if (name == "Pointer2") {
        pointerExample2();
    } else if (name == "If") { //If
        ifExample();
    } else if (name == "References") { //References
        referencesExample();
    } else if (name == "References2") {
        referencesExample2();
    } else if (name == "References3") {
        referencesExample3();
    } else if (name == "References4") {
        referencesExample4();
    } else if (name == "References5") {
        referencesExample5();
    } else if (name == "PlayerClass") { //Classes
        playerClassExample();
    } else if (name == "PlayerClass2") {
        playerClassExample2();
    } else if (name == "LogClass") {
        logClassExample();
    } else if (name == "StaticClass") { //Static
        staticClassExample();
    } else if (name == "StaticLocal") {
        staticLocalExample();
    } else if (name == "Enum") { //Enums
        enumExample();
    } else if (name == "Constructor") { //Constructor & Destructor
        constructorExample();
    } else if (name == "Destructor") {
        destructorExample();
    } else if (name == "Inheritance") { //Inhertance
        inheritanceExample();
    } else if (name == "VirtualFunction") { //VirtualFunctions
        virtualFunctionsExample();
    } else if (name == "Interface") { //Interface
        interfaceExample();
    } else if (name == "Array") { //Arrays
        arrayExample();
    } else if (name == "Array2") {
        arrayExample2();
    } else if (name == "String") { //Strings
        stringExample();
    } else if (name == "String2") {
        stringExample2();
    } else if (name == "StringLiteral") {
        stringLiteralExample();
    } else if (name == "Mutable") { //Mutable
        mutableExample();
    } else if (name == "InitializerList") { //InitializerLists
        initializerListExample();
    } else if (name == "TernaryOperator") { //TernaryOperators
        ternaryOperatorsExample();
    } else if (name == "CreateObjects") { //Objects
        createObjectsExample();
    } else if (name == "New") { //New
        newExample();
    } else if (name == "Implicit") { //Implicit & Explicit
        implicitExample();
    } else if (name == "Explicit") {
        explicitExample();
    } else if (name == "Operator") { //Operators
        operatorExample();
    } else if (name == "ObjectLifetime") { //Object Lifetime
        objectLifetimeExample();
    } else if (name == "ObjectLifetime2") {
        objectLifetimeExample2();
    } else if (name == "SmartPointers") { //Smart Pointers
        smartPointersExample();
    } else if (name == "SmartPointers2") {
        smartPointersExample2();
    } else if (name == "Copy") { //Copy
        copyExample();
    } else if (name == "Copy2") {
        copyExample2();
    } else if (name == "Copy3") {
        copyExample3();
    } else if (name == "Arrow") { //Arrows
        arrowExample();
    } else if (name == "Arrow2") {
        arrowExample2();
    } else if (name == "Vector") { //Vectors
        vectorExample();
    } else if (name == "Vector2") {
        vectorExample2();
    } else if (name == "Template") { //Templates
        templateExample();
    } else if (name == "Template2") {
        templateExample2();
    } else if (name == "Template3") {
        templateExample3();
    } else if (name == "Allocation") { //Allocation
        allocationExample();
    } else if (name == "Macro") { //Macros
        macroExample();
    } else if (name == "Auto") { //Auto
        autoExample();
    } else if (name == "StaticArray") { //Static Arrays
        staticArrayExample();
    } else if (name == "FunctionPointers") { //Function Pointers
        functionPointersExample();
    } else if (name == "FunctionPointers2") {
        functionPointersExample2();
    } else if (name == "Lambda") { //Lambdas
        lambdaExample();
    } else if (name == "Namespace") { //Namespaces
        namespaceExample();
    } else if (name == "Thread") { //Threads
        threadExample();
    } else if (name == "Timing") { //Timing
        timingExample();
    } else if (name == "MultidimensionalArray") { //Multi-dimensional Arrays
        multidimensionalArrayExample();
    } else if (name == "MultidimensionalArray2") {
        multidimensionalArrayExample2();
    } else if (name == "Sorting") { //Sorting
        sortingExample();
    } else if (name == "TypePunning") { //Type Punning
        typePunningExample();
    } else if (name == "TypePunning2") {
        typePunningExample2();
    } else if (name == "TypePunning3") {
        typePunningExample3();
    } else if (name == "Union") { //Unions
        unionExample();
    } else if (name == "VirtualDestructor") { //Virtual Destructors
        virtualDestructorExample();
    } else if (name == "Casting") { //Casting
        castingExample();
    } else if (name == "Casting2") {
        castingExample2();
    } else if (name == "DynamicCast") {
        dynamicCastExample();
    } else if (name == "Benchmarking") { //Benchmarking
        benchmarkingExample();
    } else if (name == "Benchmarking2") {
        benchmarkingExample2();
    } else if (name == "StructuredBindings") { //Structured Bindings
        structuredBindingsExample();
    } else if (name == "StructuredBindings2") {
        structuredBindingsExample2();
    } else if (name == "Optional") { //Optional
        optionalDataExample();
    } else if (name == "MultipleDataTypesInSingleVariable") { //Data Types Single Variable
        multipleDataTypesInSingleVariableExample();
    } else if (name == "StoreAnyDataInSingleVariable") {
        storeAnyDataInSingleVariableExample();
    } else if (name == "Performance") { //Performance
        performanceExample();
    } else if (name == "StringPerformance") {
        stringPerformanceExample();
    } else if (name == "VisualBenchmarking") { //Visual Benchmarking
        visualBenchmarkingExample();
    } else if (name == "Singletons") { //Singletons
        singletonsExample();
    } else if (name == "SmallStringOptimization") { //Small String Optimization
        smallStringOptimizationExample();
    } else if (name == "MemoryAllocation") { //Memory Allocation
        memoryAllocationExample();
    } else if (name == "lRValues") { //LValues & RValues
        lRValuesExample();
    } else if (name == "lRValues2") {
        lRValuesExample2();
    } else if (name == "ArgumentEvaluation") { //Argument Evaluation Order
        argumentEvaluationExample();
    } else if (name == "MoveSemantics") { //Move Semantics
        moveSemanticsExample();
    } else if (name == "MoveSemantics2") {
        moveSemanticsExample2();
    } else if (name == "DataStructures") { //Data Structures
        dataStructuresExample();
    } else if (name == "DataStructures2") {
        dataStructuresExample2();
    } else if (name == "DataStructures3") {
        dataStructuresExample3();
    } else if (name == "Iterator") { //Iterators
        iteratorExample();
    } else if (name == "Iterator2") {
        iteratorExample2();
    } else if (name == "Maps") { //Maps
        mapsExamples(); //Grouped Examples together since it was simple.
    } else {
        Log("No example with that name!");
    }
    Log("-------------------------");
    std::cin.get();
}

/*
 TODO: EXTRA NOTES
 ::Visibility
 - public = accessable everywhere
 - protected = only this class and sub classes
 - private = only this class
 ::Strings
 - each character takes 1 byte of memory (if it is not modified to be wider)
 - same as const char arrays
 - strings allocate memory on the heap
 ::Const
 - const is used as a rule to say the variable will not be changed later in the code
 - cannot be modified past declaration of the variable
 - you can break a const promise by assigning the variable to memory on the heap
 - if const is used after the pointer, you cant assign the variable to be something else, but change the value it represents
 - if used on a method, it cannot change any variables in the class
 - const methods can only be called in a const instance of a class
 ::Mutable
 - mutable variables can be modified within a const method (the exception to the const rule)
 - mutable would be used for situations such as having a variable to mark how many times a const method is called
 ::Multiple Return Types
 - Structs can contain multiple variables and can be useful when trying to return multiple variables in a function
 - You can also return an array, though it is not as optimal as returning a struct
 ::Continuous Integration
 - Continuous Integration is making sure a build is able to work on all platforms
 - Jenkins is a good tool for experimenting with continuous integration
 ::Static Analysis
 - Static Analyzers find errors in your programs that may be not noticed by the naked eye
 - PVS studio is a recommended static analyzer
 ::Safety In C++
 - Things like smart pointers exist in C++ because they are to help you make your life easier, they are not required or replacements of the old C style tools
 - The news tools are used to simply automate the deletion of memory
 - Real applications tend to use smart pointers more often, but raw pointers aern't never used
 ::Memory Allocation
 - using things that require "new" is heap allocated, therefore should be deleted when finished with
 - stack is auto allocated memory, and the heap is manual allocated memory
 - stack memory disappear as soon as the variable goes out of scope (at the end of the method for example)
 - heap memory will only disappear if you manually delete it when it is no longer needed
 - stack memory is small (about 1M) and therefore allocating on the heap may be needed for large objects
 - allocating on the heap takes longer
 - allocated memory on the heap you have to free up
 ::Bitwise Operators
 - & operator subtracts/masks bits
 - | operator combines bits
 - << operator shifts bits by amount specified. (a <<= 1; 0101(5) -> 1010(10)) (doubles amount == 2x^n == <<n)
 - >> operator shifts bits by amount specified. (a >>= 1; 0101(5) -> 0101(2(forgets decimal place))) (halves amount == 1/2^n == >>n)
 - Compiler will automatically turn 5 x 16 into 5 << 4; (Usually code is written as 5x16 rather than 5<<4 cause it is easier to read)
 */

 /*
  TODO: C++ Data Types
  char						1byte			-127 to 127 or 0 to 255
  unsigned char				1byte			0 to 255
  signed char				1byte			-127 to 127
  int						4bytes			-2147483648 to 2147483647
  unsigned int				4bytes			0 to 4294967295
  signed int				4bytes			-2147483648 to 2147483647
  short int					2bytes			-32768 to 32767
  unsigned short int		2bytes			0 to 65,535
  signed short int			2bytes			-32768 to 32767
  long int					8bytes			-2,147,483,648 to 2,147,483,647
  signed long int			8bytes			same as long int
  unsigned long int			8bytes			0 to 4,294,967,295
  long long int				8bytes			-(2^63) to (2^63)-1
  unsigned long long int	8bytes			0 to 18,446,744,073,709,551,615
  float						4bytes
  double					8bytes
  long double				12bytes
  wchar_t					2 or 4 bytes	1 wide character

  "sizeOf()" can be used to determine the size of a data type as well
  */
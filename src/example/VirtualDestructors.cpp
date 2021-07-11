#include "header/Headers.h"

class BaseA {
public:
    BaseA() {
        std::cout << "BaseA Constructor\n";
    }

    virtual ~BaseA() {
        std::cout << "BaseA Destructor\n";
    }
};

class DerivedA : public BaseA {
public:
    DerivedA() {
        std::cout << "DerivedA Constructor\n";
    }

    ~DerivedA() {
        std::cout << "DerivedA Destructor\n";
    }
};

class DerivedB : public BaseA {
public:
    DerivedB() {
        std::cout << "DerivedB Constructor\n";
    }

    ~DerivedB() {
        std::cout << "DerivedB Destructor\n";
    }
};

//because of inheritence, both constructors/destructors are called with the class "Derived"
//if a "Base" type is assigned as a "Derived" class, then the destructor for "Derived" is never called (problematic because it can cause memory leaks)
//By changing the "Base" destructor to "virtual", it will then call both destructors correctly
void virtualDestructorExample() {
    BaseA* base = new BaseA();
    delete base;
    std::cout << "-------------------------\n";
    DerivedA* derived = new DerivedA();
    delete derived;
    std::cout << "-------------------------\n";
    BaseA* poly = new DerivedA();
    delete poly;
}
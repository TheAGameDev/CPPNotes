#include "header/Headers.h"

//the "this" keyword grabs the current instance of the class
//the "this" keyword can be used to grab a variable as the same name as a perameter in the class
class Entity1A {
public:
    int x, y;

    Entity1A(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int GetX() const {
        const Entity1A* e = this;
        return e->x;
    }
};

class Entity2A {
public:
    Entity2A() {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity2A() {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print() {
        std::cout << this << std::endl;
    }
};

//Invalid code, the array is deleted at the end of the function, therefore the pointer that is returned will no longer point to the array at the end of the function
int* CreateArray() {
    int array[50];
    return array;
}

//The Entity is destoyed at the end of the scope (unless it is created on the heap instead)
void objectLifetimeExample() {
    {
        Entity2A* e = new Entity2A();
    }
}

//An example of what a scope pointer does
class ScopedPtrA {
private:
    Entity2A* m_Ptr;
public:
    ScopedPtrA(Entity2A* ptr) : m_Ptr(ptr) {
    }

    ~ScopedPtrA() {
        delete m_Ptr;
    }
};

//A scoped pointer will automatically delete a heap allocated obj at the end of a scope
void objectLifetimeExample2() {
    {
        ScopedPtrA e(new Entity2A());
    }
}

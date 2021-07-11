#include "header/Headers.h"

class EntityL {
public:
    void Print() const {
        std::cout << "Hello!" << std::endl;
    }
};

class ScopedPtrB {
private:
    EntityL* m_Obj;
public:
    ScopedPtrB(EntityL* entity) : m_Obj(entity) {
    }

    ~ScopedPtrB() {
        delete m_Obj;
    }

    EntityL* operator->() {
        return m_Obj;
    }
};

//the arrow operator dereferences "ptr" then calls "Print()" from the instance of the class
void arrowExample() {
    EntityL e;
    e.Print();
    EntityL* ptr = &e;
    ptr->Print();
}

//By changing the arrow operator output in a scoped pointer, we can have scoped pointer delete the object at the end of the scope while still being able to access the obj variables within the scope
void arrowExample2() {
    ScopedPtrB entity = new EntityL;
    entity->Print();
}

struct Vector3A {
    float x, y, z;
};

//uses the arrow operator to get the offset of a certain value in memory
//does not work with every compiler??
/*void arrowExample3() {
    int offset = (int)&((Vector3A*)nullptr)->x;
    std::cout << offset << std::endl;
}*/

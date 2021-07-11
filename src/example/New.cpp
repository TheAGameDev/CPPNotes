#include "header/Headers.h"

class EntityI {
private:
    std::string m_Name;
    int x, y, z;
public:
    EntityI() : m_Name("Unknown"), x(0), y(0), z(0) {
    }

    EntityI(const std::string& name) {
        m_Name = name;
    }

    const std::string& GetName() const {
        return m_Name;
    }
};

//by using "new", it will allocate and request so many bytes of data that the type will take (ex new int = 4 bytes of memory allocated)
//by calling a singe class on the heap (entity in this case), you will allocate memory and call the constructor
//"(EntityI*)malloc(sizeof(EntityI))" will allocate the memory for an entity without calling it's constructor ("free()" would be used in place of delete in this situation)
//you MUST use delete when you use the new keyword. If new is called with square brackets, delete must be called with sqaure brackets
//if you use new with "()" ex: "new()", the memory address supplied in the () will be used
void newExample() {
    int a = 2;
    int* b = new int[50];
    EntityI* entity = new EntityI();
    delete[] b;
    delete entity;
}
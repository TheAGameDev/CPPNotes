#include "header/Headers.h"

class EntityH {
private:
    std::string m_Name;
    int x, y, z;
public:
    EntityH() : m_Name("Unknown"), x(0), y(0), z(0) {
    }

    EntityH(const std::string& name) {
        m_Name = name;
    }

    const std::string& GetName() const {
        return m_Name;
    }
};

//2 ways to create objects, on the stack, or on the heap
//creating it on the stack -> "EntityH e();"
//creating it on the heap -> "EntityH* entity = new EntityH()"
//heap would only be used if: 1) the object lives on past the function its made in, 2) free space on the stack
//"delete entity" frees up memory (yes it is manual)
//if you use the "new" keyword to create it, then you will need the "delete" keyword to destroy it
//since "entity" was created inside of "e", it will be deleted when "e" is deleted
void createObjectsExample() {
    EntityH* e;
    {
        EntityH* entity = new EntityH("AGame");
        e = entity;
        std::cout << entity->GetName() << std::endl;
    }
    delete e;
}
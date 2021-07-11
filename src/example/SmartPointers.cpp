#include "header/Headers.h"

class EntityK {
public:
    EntityK() {
        std::cout << "Created Entity!" << std::endl;
    }

    ~EntityK() {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print() {
        std::cout << this << std::endl;
    }
};

//smart pointers require "#include <memory>"
//unique pointers are made so that when an obj goes out of scope, it will get destroyed
//unique pointers should only be used once, otherwise a second unique pointer will point to freed up memory
//unique pointers are explicit constructors
//When creating an entity with a unique pointer, you will want to use "std::make_unique<EntityK>()" due to exception safety (prevents memory leaks)
void smartPointersExample() {
    {
        std::unique_ptr<EntityK> entity = std::make_unique<EntityK>();
        entity->Print();
    }
}

//shared pointers use a reference counter to see when it should free up the memory
//by using "std::make_shared<EntityK>()" to create the entity, it will only need to allocate memory for the entity once instead of twice (saves memory and performance)
//the "sharedEntity" won't die at the end of the scope because "e0" still holds a reference to it
//when assigning a weak_ptr to a shared_ptr, it wont increase the ref count of the shared_ptr (useful when your storing a list of entities (like a reference to them))
//weak pointers can be used to ask if an object is still valid
void smartPointersExample2() {
    std::shared_ptr<EntityK> e0;
    {
        std::shared_ptr<EntityK> sharedEntity = std::make_shared<EntityK>();
        std::weak_ptr<EntityK> weakEntity = sharedEntity;
        e0 = sharedEntity;
    }
}
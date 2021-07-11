#include "header/Headers.h"

//if a virtual method is set to 0, then the method becomes similar to an abstract method in java
//class cant be instantiated, but subclasses can set the method to return something else and therefore be instantiated
//interface is simply just a class
class PrintableA {
public:
    virtual std::string getClassName() = 0;
};

//the supertype's method must be set as virtual for this to work
//with EntityE class having PrintableA as a supertype, it requires the methods of the interface to exist in this subclass
class EntityE : public PrintableA {
public:
    virtual std::string getName() {
        return "Entity";
    }

    std::string getClassName() override {
        return "Entity";
    }
};

class PlayerC : public EntityE {
private:
    std::string m_Name;
public:
    PlayerC(const std::string& name)
        : m_Name(name) {

    }

    std::string getName() override {
        return m_Name;
    }

    std::string getClassName() override {
        return "Player";
    }
};

//the name of "entity" will result in "Entity" rather than "AGame" even though this instance of Entity is a Player
//If a variable is declared as a supertype of a class, then it will use the supertype's methods over the subclass unless the supertype method is set as virtual
//an alternative or a secondary precaution you can take is by adding "override" to the child class method
//Be aware the usage of virtual or overriden functions creates a V-table which can take up more memory
void virtualFunctionsExample() {
    EntityE* e = new EntityE();
    std::cout << e->getName() << std::endl;
    PlayerC* p = new PlayerC("AGame");
    std::cout << p->getName() << std::endl;
    EntityE* entity = p;
    std::cout << entity->getName() << std::endl;
}

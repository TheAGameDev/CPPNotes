#include "header/Headers.h"

class PrintableB {
public:
    virtual std::string getClassName() = 0;
};

static class EntityF : public PrintableB {
public:
    virtual std::string getName() {
        return "Entity";
    }

    std::string getClassName() override {
        return "Entity";
    }
};

static class PlayerD : public EntityF {
private:
    std::string m_Name;
public:
    PlayerD(const std::string& name)
        : m_Name(name) {

    }

    std::string getName() override {
        return m_Name;
    }

    std::string getClassName() override {
        return "Player";
    }
};

//Prints the name of the class
static void PrintClass(PrintableB* obj) {
    std::cout << obj->getClassName() << std::endl;
}

//aka pure virtual functions
void interfaceExample() {
    EntityF* e = new EntityF();
    PlayerD* p = new PlayerD("AGame");
    PrintClass(e);
    PrintClass(p);
}

#include "header/Headers.h"

class EntityJ {
private:
    std::string m_Name;
    int m_Age;
public:
    EntityJ(const std::string& name) : m_Name(name), m_Age(-1) {
    }

    explicit EntityJ(int age) : m_Name("Unknown"), m_Age(age) {
    }
};

//C++ is aware that there is a constructor for the class that takes an integer, so therefore a int can be used in-place of an entity
//A string is a convertion of a const char array, therefore it does not work unless wrapped
//implicit example
void implicitExample() {
    EntityJ a = std::string("AGame");
    //Entity b = 19;
}

//by adding explicit in front of a constructor, implicit conversions are disabled
//explicit really only used when your purposely trying to avoid implicit conversions to happen by accident
void explicitExample() {
    EntityJ a = std::string("AGame");
    EntityJ b(19);
}

#include "header/Headers.h"

//initializer lists require a colon to start before the code of the method
//initializer lists allow constructors to assign variables values upon creation before the code
//You will want to initialize your members in order as some compilers will result in an error
//by assigning variables in the code of the instructor instead of initializer lists, you will create the object twice and therefore is memory and performance inefficient
class EntityG {
private:
    std::string m_Name;
    int x, y, z;
public:
    EntityG() : m_Name("Unknown"), x(0), y(0), z(0) {
    }

    EntityG(const std::string& name) {
        m_Name = name;
    }

    const std::string& GetName() const {
        return m_Name;
    }
};

//initializer lists are mainly used if a fixed value is required (the value can be supplied)
void initializerListExample() {
    EntityG e0;
    std::cout << e0.GetName() << std::endl;
    EntityG e1("AGame");
    std::cout << e1.GetName() << std::endl;
}

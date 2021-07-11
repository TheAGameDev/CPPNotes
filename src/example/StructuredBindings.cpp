#include "header/Headers.h"

//tuples are a way of returning multiple return types
static std::tuple<std::string, int> CreatePerson() {
    return { "AGame", 19 };
}

//help handle multiple return values better (C++ 17)
//tuples aern't very clean with code, therefore you may use a struct to replace them
//ties are a bit cleaner, but they are still not very desirable compared to structs
void structuredBindingsExample() {
    auto person = CreatePerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);

    std::string name2;
    int age2;
    std::tie(name2, age2) = CreatePerson();
}

void structuredBindingsExample2() {
    auto [name, age] = CreatePerson();
    std::cout << name << ", " << age << std::endl;
}
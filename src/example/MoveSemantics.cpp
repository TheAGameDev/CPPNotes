#include "header/Headers.h"

//A move constructor is created like "StringB(StringB&& other) noexcept {}"
class StringB {
public:
    StringB() = default;
    StringB(const char* string) {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    StringB(const StringB& other) {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    StringB(StringB&& other) noexcept {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    ~StringB() {
        printf("Destroyed!\n");
        delete m_Data;
    }

    void Print() {
        for (uint32_t i = 0; i < m_Size; i++)
            printf("%c", m_Data[i]);
        printf("\n");
    }

    //overrides the "=" operator to work like the move constructor
    //World have to avoid errors of assigning to itself
    StringB& operator=(StringB&& other) noexcept {
        printf("Moved!\n");
        if (this != &other) {
            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }
        return *this;
    }
private:
    char* m_Data;
    uint32_t m_Size;
};

//variable must be cast to a R value reference for the move constructor to be called "m_Name((StringB&&)name)"
class EntityO {
public:
    EntityO(const StringB& name) : m_Name(name) {
    }
    EntityO(StringB&& name) : m_Name((StringB&&)name) {
    }

    void PrintName() {
        m_Name.Print();
    }
private:
    StringB m_Name;
};

//Allows you to move an object into a function without copying it (prevents excess heap allocation)
//For this to work we still need a way of copying the StringB into the "m_Name" variable (copy constructor)
//for move semantics to work EntityO needs a constructor of an R value reference instead of a const L value reference
//A move constructor requires you to also make the "other" variables as nullptr/0 (heap/stack allocated)
void moveSemanticsExample() {
    EntityO entity("AGame");
    entity.PrintName();
    std::cin.get();
}

//When assigning a new variable to an existing one, it copies the string rather than move it
//By casting "string" to "(StringB&&)", the variable will become a string temporary and thus use the move constructor
//"std::move" can replace "(StringB&&)"
void moveSemanticsExample2() {
    StringB string = "Hello";
    StringB dest = std::move(string);

    StringB apple = "Apple";
    StringB dest2;

    apple.Print();
    dest2.Print();

    dest2 = std::move(apple);

    apple.Print();
    dest2.Print();
}
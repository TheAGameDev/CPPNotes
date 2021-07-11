#include "header/Headers.h"

struct Vector2B {
    float x, y;

    Vector2B(float xIn, float yIn) : x(xIn), y(yIn) {
    }

    Vector2B Add(const Vector2B& other) const {
        return operator+(other);
    }

    Vector2B operator+(const Vector2B& other) const {
        return Vector2B(x + other.x, y + other.y);
    }

    Vector2B Multiply(const Vector2B& other) const {
        return Vector2B(x * other.x, y * other.y);
    }

    Vector2B operator*(const Vector2B& other) const {
        return Multiply(other);
    }

    bool operator==(const Vector2B& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2B& other) const {
        return !(*this == other);
    }
};

//By assigning "b" as "a", we are copying "a" to create "b"
//this works with classes as well
//by changing values of the copied variable/class, you do not change the original value
void copyExample() {
    int a = 2;
    int b = a;
    Vector2B a1 = { 2, 3 };
    Vector2B b1 = a1;
    b1.x = 5;
}

//by assigning the variables on the heap instead of the stack, you create 2 pointers leading to the same memory
//therefore by changing the x value of "b", then you also change the x value of "a"
void copyExample2() {
    Vector2B* a = new Vector2B(0, 0);
    Vector2B* b = a;
    b->x = 2;
}

//by listing a method/class as a friend, you are able to access private methods of this class inside those methods/classes
//null termination character must be kept in mind when get the size of a string
//you can prevent copying of a class by making the copy constructor equal "delete"
class StringA {
private:
    char* m_Buffer;
    size_t m_Size;
public:
    StringA(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    StringA(const StringA& other) : m_Size(other.m_Size) {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~StringA() {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const StringA& string);
};

std::ostream& operator<<(std::ostream& stream, const StringA& string) {
    stream << string.m_Buffer;
    return stream;
}

//You want to pass a reference, otherwise you copy the "StringA" class needlessly taking up more memory/performance
//always pass your objects by const reference
void PrintString(const StringA& string) {
    std::cout << string << std::endl;
}

//this will lead to crash since the same buffer is trying to be deleted twice ("string" and "second" share the same buffer since it was just copied)
//above comment can be proved by changing the second character on only the "second" variable
//every time you copy a "String" class, you use up memory on the heap
void copyExample3() {
    StringA string = "AGame";
    StringA second = string;

    second[1] = 'L';

    PrintString(string);
    PrintString(second);
}

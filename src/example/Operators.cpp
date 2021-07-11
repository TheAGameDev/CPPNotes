#include "header/Headers.h"

//By using "operator", you can define what an operator does to this class
//if you wanted to, you could just define the operator to do what Multiply does in this case
//Add in this case add can just call the operator like a function and it will work as well (other way is recommended)
//By adding an "==" && "!=" overload, you can compare two instances of your class together
struct Vector2A {
    float x, y;

    Vector2A(float xIn, float yIn) : x(xIn), y(yIn) {
    }

    Vector2A Add(const Vector2A& other) const {
        return operator+(other);
    }

    Vector2A operator+(const Vector2A& other) const {
        return Vector2A(x + other.x, y + other.y);
    }

    Vector2A Multiply(const Vector2A& other) const {
        return Vector2A(x * other.x, y * other.y);
    }

    Vector2A operator*(const Vector2A& other) const {
        return Multiply(other);
    }

    bool operator==(const Vector2A& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2A& other) const {
        return !(*this == other);
    }
};

//by overloading the leftshift operator ("<<"), we add functionality to tell it how to read the class
//similar to "ToString" in Java or C#
std::ostream& operator<<(std::ostream& stream, const Vector2A& other) {
    stream << other.x << ", " << other.y;
    return stream;
}

//Instead of having messy code like for "result", you can use operator overloading
//"result2" uses operator overloading to make code look neater
void operatorExample() {
    Vector2A position(4.0F, 4.0F);
    Vector2A speed(0.5F, 1.5F);
    Vector2A powerup(1.1F, 1.1F);
    Vector2A result = position.Add(speed.Multiply(powerup));
    Vector2A result2 = position + speed * powerup;
    std::cout << result2 << std::endl;
}

#include "header/Headers.h"

class BaseB {
public:
    BaseB() {
        std::cout << "BaseB Constructor\n";
    }

    virtual ~BaseB() {
        std::cout << "BaseB Destructor\n";
    }
};

class DerivedC : public BaseB {
public:
    DerivedC() {
        std::cout << "DerivedC Constructor\n";
    }

    ~DerivedC() {
        std::cout << "DerivedC Destructor\n";
    }
};

class DerivedD : public BaseB {
public:
    DerivedD() {
        std::cout << "DerivedD Constructor\n";
    }

    ~DerivedD() {
        std::cout << "DerivedD Destructor\n";
    }
};

//By casting to an int, it rounds the double to be treated as an integer
//Static cast is a c++ style cast, thus making "a" and "s" return the same values
void castingExample() {
    double value = 5.25;
    double a = (int)(value + 5.3);

    double s = static_cast<int>(value + 5.3);

    std::cout << a << std::endl;
}

//dynamic cast will check if 1 class is an instance of another (checks if "base" is an instance of "Derived2")
//const casts are used to removed const from an existing obj
//reinterpret casts are used for type punning (look at type punning examples)
void castingExample2() {
    DerivedC* derived = new DerivedC();
    BaseB* base = derived;
    DerivedD* d2 = dynamic_cast<DerivedD*>(base);
}

//class requires a virtual function to become polymorphic
class EntityN {
public:
    virtual void PrintName() {
    }
};

class PlayerE : public EntityN {
};

class EnemyA : public EntityN {
};

//dynamic casts come at a performance cost
//dynamic casts are specifically used along the inheritence hierarchy
//an instance of "EntityN" can be set as a "PlayerE", but a "PlayerE" instance can't be set as "EntityN"
//"PlayerE* p = (PlayerE*)e1" is dangerous as e1 is an instance of Enemy, can cause memory leaks and crashes
//dynamic cast would only work in this instance if the base class is polymorphic
//The dynamic cast would only work if a Player is cast instead of an Enemy
//dynamic casting in C++ is similar to "instanceof" in java
void dynamicCastExample() {
    PlayerE* player = new PlayerE();
    EntityN* actuallyPlayer = player;
    EntityN* actuallyEnemy = new EnemyA();

    PlayerE* p0 = dynamic_cast<PlayerE*>(actuallyEnemy);
    PlayerE* p1 = dynamic_cast<PlayerE*>(actuallyPlayer);
}
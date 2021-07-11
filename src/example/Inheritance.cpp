#include "header/Headers.h"

class EntityD {
public:
    float x, y;

    //moves entity by x and y values given
    void Move(float xa, float ya) {
        x += xa;
        y += ya;
    }
};

//By stating PlayerB is an extension of EntityD, everything declared in EntityD is now accessable in PlayerB
class PlayerB : public EntityD {
public:
    const char* Name;

    //Prints entity name
    void printName() {
        std::cout << Name << std::endl;
    }
};

//An instance of player is also an instance of entity, therefore you have access to the code of an entity within a player class
void inheritanceExample() {
    std::cout << sizeof(EntityD) << std::endl;
    std::cout << sizeof(PlayerB) << std::endl;
    PlayerB player;
    player.Move(5, 5);
    player.x = 2;
    player.printName();
}

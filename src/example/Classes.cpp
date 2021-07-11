#include "header/Headers.h"

//what code for a player looks like without object oriented programming
//with multiple players, multiple variables per player may not be ideal and therefore want a class
void playerClassExample() {
    int playerX0, playerY0;
    int playerSpeed0 = 2;
    int playerX1, playerY1;
    int playerSpeed1 = 2;
}

//what code for a player looks like with object oriented programming
//only requires variables to be made once
//variables created as a class type is considered an object
//by default a class is private, meaning variables in that class can only be accessed within that class
//adding "public:" allows the varaibles to modified and visible outside of the class
//By changing the class to a struct, the default is public instead of private (struct also is backwards compatible with C language)(Structs also used to just store data instead of massive functionality like classes)
class PlayerA {
public:
    int x, y;
    int speed;

    //the function can be inside of the player class, therefore be available when the PlayerA class is called regardless of position
    //player object doesn't need to be passed if inside of the player class
    //varaibles dont need to be public if only being called from methods within the class
    //x, y, and speed will be that of the current object's variables
    void move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
};

//the use of "&" is so that the instance of the PlayerA class can be modified
//+= adds and sets the player x to xa (same with the y variable)
//multiplying with the speed allows the player to move the value of speed times more on the x and y axis
//the function can be outside of the player class, but before it is called
/*void move(Player& player, int xa, int ya) {
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}*/

//the variable of player is an instance of the PlayerA class
//variables per player can be unique without having to make them seperate varaibles
void playerClassExample2() {
    PlayerA player;
    player.x = 2;
    player.y = 2;
    player.speed = 5;
    player.move(1, -1);
}

//"m_" usually used to write private variables that are a member of a class
class CLog {
public:
    //With an enum, we can replace the use of the 3 variables below
    enum Level {
        ERROR = 0, WARN, INFO
    };

    const int logLevelError = 0;
    const int logLevelWarn = 1;
    const int logLevelInfo = 2;
private:
    int m_logLevel = logLevelInfo;
public:
    //Have log level to set what messages should be displayed
    void setLevel(int level) {
        m_logLevel = level;
    }

    //Writes a error level message
    void error(const char* message) {
        if (m_logLevel >= logLevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    //Writes a warning level message
    void warn(const char* message) {
        if (m_logLevel >= logLevelWarn)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    //Writes a info level message
    void info(const char* message) {
        if (m_logLevel >= logLevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

//Sets log levels that you want displayed in console
void logClassExample() {
    CLog log;
    log.setLevel(log.logLevelError);
    log.error("Hello!");
    log.warn("Hello!");
    log.info("Hello!");
}

//Static variables in a class require them to be defined outside of the class (struct in this case)
struct EntityA {
    static int x, y;

    //Prints x and y values
    void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

int EntityA::x;
int EntityA::y;
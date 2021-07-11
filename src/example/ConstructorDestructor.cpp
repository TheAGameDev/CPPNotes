#include "header/Headers.h"

class EntityC {
public:
    float x, y;

    //Constructors are automatically called when the object is created
    //The "init" method is therefore useless
    EntityC() {
        x = 0.0F;
        y = 0.0F;
        std::cout << "Created Entity!" << std::endl;
    }

    //You can have multiple constructors as long as the peramaters are different between them
    //perameters can be applied to constructors as a requirement for the creation of the class
    EntityC(float xIn, float yIn) {
        x = xIn;
        y = yIn;
    }

    //Destructors begin with a "~" to mark them seperate from constructors
    //Destructors are triggered at the removal of the class instance instead of it's creation
    ~EntityC() {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    //Used as a constructor for EntityC (call before you use the class)
    void init() {
        x = 0.0F;
        y = 0.0F;
    }

    //Prints x and y values
    void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

//Constructor will result in an error since the value of "x" for "e" was never set
void constructorExample() {
    EntityC e(10.0F, 5.0F);
    std::cout << e.x << std::endl;
    e.Print();
}

void destructorExample() {
    EntityC e;
    e.Print();
}
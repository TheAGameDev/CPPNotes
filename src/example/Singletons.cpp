#include "header/Headers.h"

//"static Random Instance;" will perform the same as an outside variable without as much code being used
class Random {
public:
    Random(const Random&) = delete;

    static Random& Get() {
        static Random Instance;
        return Instance;
    }

    static float Float() {
        return Get().IFloat();
    }
private:
    float m_RandomGenerator = 0.5F;

    float IFloat() {
        return m_RandomGenerator;
    }

    Random() {
    }
};

//A singleton is a class where you intend to only have a single instance of that class
//With only 1 instance, a singleton doesn't really need to be a class...
//Would really only be used globally (such as a random number generator, a renderer, etc...)
//Singleton classes can ultimately behave like namespaces
//In this example, we use a singleton to produce a random number generator for a float (never have to instanciate another version of this random and will perform the same which means less memory used)
void singletonsExample() {
    float number = Random::Float();
    std::cout << number << std::endl;
}

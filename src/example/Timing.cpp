#include "header/Headers.h"

struct TimerA {
    std::chrono::time_point<std::chrono::steady_clock> start, end;

    TimerA() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~TimerA() {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        float ms = duration.count() * 1000.0F;
        std::cout << "Timer took " << ms << "ms" << std::endl;
    }
};

//By remove "std::endl" and adding "\n" to the string, we can increase the speed of the function
static void Function() {
    TimerA timer;
    for (int i = 0; i < 100; i++)
        std::cout << "Hello\n";
}

//The commented out code below can be replaced by the timer struct above
//The "std::chrono" library handles all timing based actions
void timingExample() {
    using namespace std::literals::chrono_literals;
    /*
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    float ms = duration.count() * 1000.0F;
    std::cout << ms << "ms" << std::endl;
     */
    Function();
}
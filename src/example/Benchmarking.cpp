#include "header/Headers.h"

class TimerB {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
public:
    TimerB() {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~TimerB() {
        Stop();
    }

    void Stop() {
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimePoint).time_since_epoch().count();
        auto duration = end - start;
        double ms = duration * 0.001;
        std::cout << duration << "us (" << ms << "ms)\n";
    }
};

//Benchmarking is measuring performance, and to do that you have to measure how long something takes
//by making a timer class, you can measure how long something takes by wrapping it within a scope
//the compiler has already figured out what the result will be of the code, and therefore it won't actually measure how long the code takes to run
void benchmarkingExample() {
    int value = 0;
    {
        TimerB timer;
        for (int i = 0; i < 1000000; i++) {
            value += 2;
        }
    }
    std::cout << value << std::endl;
}

void benchmarkingExample2() {
    struct SimpleVector2A {
        float x, y;
    };
    std::cout << "Make Shared\n";
    {
        auto sharedPtrs = new std::array<std::shared_ptr<SimpleVector2A>, 1000>();
        TimerB timer;
        for (int i = 0; i < sharedPtrs->size(); i++) {
            (*sharedPtrs)[i] = std::make_shared<SimpleVector2A>();
        }
        delete sharedPtrs;
    }
    std::cout << "New Shared\n";
    {
        auto sharedPtrs = new std::array<std::shared_ptr<SimpleVector2A>, 1000>();
        TimerB timer2;
        for (int i = 0; i < sharedPtrs->size(); i++) {
            (*sharedPtrs)[i] = std::shared_ptr<SimpleVector2A>(new SimpleVector2A());
        }
        delete sharedPtrs;
    }
    std::cout << "Make Unique\n";
    {
        auto uniquePtrs = new std::array<std::unique_ptr<SimpleVector2A>, 1000>();
        TimerB timer3;
        for (int i = 0; i < uniquePtrs->size(); i++) {
            (*uniquePtrs)[i] = std::make_unique<SimpleVector2A>();
        }
        delete uniquePtrs;
    }
}
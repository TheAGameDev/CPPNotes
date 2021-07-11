#include "header/Headers.h"

static bool s_Finished = false;

//"std::literals::chrono_literals" allows for measurements of time to be used in your application
//"std::this_thread" gives commands to the current thread
//you'll have to use "using namespace" if the namespace includes special operators
static void DoWork() {
    using namespace std::literals::chrono_literals;
    while (!s_Finished) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

//"Join()" waits for the thread to be finished before continuing
//We want to log "Working..." to the console, until the enter key is hit (which allows the thread to finish)
void threadExample() {
    std::thread worker(DoWork);
    std::cin.get();
    s_Finished = true;
    worker.join();
    std::cout << "Finished." << std::endl;
}

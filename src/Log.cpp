#include <iostream>
//extern will make the linker look elsewhere for the variable's declaration
extern int ext;

//Initialization Log
void InitLog() {
    std::cout << "Initialized-Log" << std::endl;
}

//Logs the message
void Log(const char* message) {
    std::cout << message << std::endl;
}

//prints "ext"
void LogExt() {
    std::cout << ext << std::endl;
}
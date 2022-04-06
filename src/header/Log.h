//Pragma once = be included only once in the source file
//Helps avoid redefining the same thing twice
#pragma once

//Method cannot be used multiple times if inside a header file unless it is static
//Recommended to be only used in 1 translation unit, therefore only use declaration of the log function
/*static void Log(const char* message) {
    std::cout << message << std::endl;
}*/

//Inline works too
//Using inline will replace Log call with "std::cout << 'Argument Result' << std::endl;"
/*inline void Log(const char* message) {
    std::cout << message << std::endl;
}*/

//Declaration of Log used in the header file
void Log(const char* message);
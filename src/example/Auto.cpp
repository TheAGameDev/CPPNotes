#include "header/Headers.h"

//the "auto" type automatically works out what type based on what is returned
//instead of writing "std::vector<std::string>::iterator" as the type, you can just replace it with auto to make code look cleaner
void autoExample() {
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");
    for (auto it = strings.begin(); it != strings.end(); it++) {
        std::cout << *it << std::endl;
    }
}
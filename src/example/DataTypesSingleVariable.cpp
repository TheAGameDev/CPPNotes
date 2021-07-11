#include "header/Headers.h"

//"std::variant" allows you to create a variable with multiple types
//if you assign a variant to something it can't be, then it results in the variable being unusable
//using "std::get<std::string>(data)" allows you to retrieve the string value within the "std::variant"
//variants are not simply a type safe data of a union
void multipleDataTypesInSingleVariableExample() {
    std::variant<std::string, int> data;
    data = 2;
    std::cout << std::get<int>(data) << "\n";
    data = "AGame";
    std::cout << std::get<std::string>(data) << "\n";

    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(std::string) << "\n";
    std::cout << sizeof(data) << "\n";
}

//an "std::any" variable can be set to any type of data
//"std::any_cast" will cast an "std::any" variable to be a certain type
//"std::variant" is type safe, while "std::any" is not and become confusing
//"std::any" stores small types like a "std::variant" and large types with void pointers
//"std::any" will dynamically allocate memory, which is not good for performance (worrying for using large data types)
//"std::any" is not recommended when "std::variant" is a safer function choice, and if you do need every data type, then you may want to reconsider the program you are creating
void storeAnyDataInSingleVariableExample() {
    std::any data;
    data = 2;
    data = "ALame";
    data = std::string("AGame");

    std::string& string = std::any_cast<std::string&>(data);
}

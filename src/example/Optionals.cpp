#include "header/Headers.h"

//std::optional is optional on weather or not the data is present
static std::optional<std::string> ReadFileAsString(const std::string& filePath) {
    std::ifstream stream(filePath);
    if (stream) {
        std::string result;
        //read file
        stream.close();
        return result;
    }
    return {};
}

//"data.has_value()" would also work as "data" in the if statement
//"data.value_or()" would set a default if the return type is null
//"data.txt" won't work in xcode without the absolute path, but can work in vs solution sandbox
void optionalDataExample() {
    std::optional<std::string> data = ReadFileAsString("$(PROJECT_DIR)/Tutorial/data.txt");
    std::string value = data.value_or("Not Present");
    std::cout << value << std::endl;
    if (data) {
        std::cout << "File read successfully!\n";
    }
    else {
        std::cout << "File could not be opened!\n";
    }
}
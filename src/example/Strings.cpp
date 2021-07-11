#include "header/Headers.h"

//"const" is usually used in-front of "char" because char is immutable and therefore cannot be extended and made bigger (unlike a string)
//leave it as const unless you are modifying the string
//Strings are a collection of characters
//this method is not recommended
void stringExample() {
    const char* name = "AGame";
    char name2[6] = { 'A', 'G', 'a', 'm', 'e', 0 };
    std::cout << name2 << std::endl;
    name2[1] = 'L';
    std::cout << name2 << std::endl;
}

//strings require "#include <string>" to print to the console
//strings are const char arrays
//by adding += to an existing string, you can append 2 strings together
void stringExample2() {
    std::string name = "AGame";
    name += " tutorial";
    std::cout << name << std::endl;
}

//sterlin tells you how long name is
//"\0" signifies the end of a string when it is being read
//name can also be written as -> (const char name[7] = "AGa\0me")
//wide chars require a "L" before the name
//char16_t require a "u" before the name
//char32_t require a "u" before the name
//the letters can also be applied to strings to change what type of char arrays they consist of
//an R allows strings to be used over multiple lines, but requires them to be surrounded by "()" (add \n for a new line"
void stringLiteralExample() {
    const char* name = "AGa\0me"; //1 byte
    const wchar_t* name2 = L"AGa\0me"; //2 byte

    const char16_t* name3 = u"AGa\0me"; //2 byte
    const char32_t* name4 = U"AGa\0me"; //4 byte

    const char* name5 = R"(Line1\n
    Line2\n
    Line3\n
    Line4)";
    std::cout << strlen(name) << std::endl;
}
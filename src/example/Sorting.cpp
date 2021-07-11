#include "header/Headers.h"

//By default, values will be sorted in ascending order
//otherwise it can take in a function to do the sorting
void sortingExample() {
    std::vector<int> values = { 3, 5, 1, 4, 2 };
    std::sort(values.begin(), values.end(), std::greater<int>());
    for (int value : values)
        std::cout << value << std::endl;
}

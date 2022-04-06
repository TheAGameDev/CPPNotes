//Pragma once = be included only once in the source file
//Helps avoid redefining the same thing twice
#pragma once
//includes with "" are for everything, <> are for compiler include paths
//recommend "" for relative paths and <> otherwise
#include <iostream>
#include "Log.h"
//needed when calling std::string
#include <string>
//includes extra c++ functions
#include <stdlib.h>
//required to use smart pointers
#include <memory>
//required to use "std::vector"
#include <vector>
//required to use "std::array"
#include <array>
//required to use "std::function"
#include <functional>
//required to use "std::thread"
#include <thread>
//used for timing
#include <chrono>
//had algorithms such as "std::sort"
#include <algorithm>
//required for streaming files
#include <fstream>
//required for "std::optional"
#include <optional>
//required for "std::variant"
#include <variant>
//required for "std::any"
#include <any>
//required for "std::asnyc"
#include <future>
//mathematics library used in C
#include <cmath>
//unsorted map, like a java hashmap
#include <unordered_map>
//sorted map
#include <map>

#define PR_DEBUG 1
//Macro replaces whatever is in "x" to where "x" is in the code
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif
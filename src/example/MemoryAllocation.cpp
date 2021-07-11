#include "header/Headers.h"

struct AllocationMetrics {
    std::uint32_t totalAllocated = 0;
    std::uint32_t totalFreed = 0;

    std::uint32_t CurrentUsage() {
        return totalAllocated - totalFreed;
    }
};
static AllocationMetrics s_AllocationMetrics;

static void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

struct Object {
    int x, y, z;
};

//Ignore warnings for Example sake
void* operator new(std::size_t size) {
    s_AllocationMetrics.totalAllocated += size;
    return std::malloc(size);
}

void operator delete(void* memory, std::size_t size) {
    s_AllocationMetrics.totalFreed += size;
    std::free(memory);
}

//By overriding the "new" operator, we can see how much memory we are allocating
//the override will still work with smart pointers
//having a struct and a print function is also another way of monitoring your memory usage
void memoryAllocationExample() {
    PrintMemoryUsage();
    std::string string = "TheAGamePlayer :> :.>";
    PrintMemoryUsage();
    {
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();
}
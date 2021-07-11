#include "header/Headers.h"

struct VertexA {
    float x, y, z;

    VertexA(float xIn, float yIn, float zIn) : x(xIn), y(yIn), z(zIn) {
    }

    VertexA(const VertexA& vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const VertexA& vertex) {
    std::cout << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

//"std::vector" unlike traditional arrays, does not have a set size when created (like an array list)
//"std::vector" is referred to as "dynamic arrays" as they are not a mathematical vector
//It is more optimal to store "VertexA" objects rather than "VertexA" pointers in the vector
//for loops can be used either way and will return the same result
//be careful to pass it by reference when using it in a function
void vectorExample() {
    std::vector<VertexA> verticies;
    verticies.push_back({ 1, 2, 3 });
    verticies.push_back({ 4, 5, 6 });
    for (int i = 0; i < verticies.size(); i++)
        std::cout << verticies[i] << std::endl;
    for (const VertexA& v : verticies)
        std::cout << v << std::endl;
    verticies.clear();
}

//By using the "reserve" method, we can optimize code by allocating enough memory as we create the vector
//"reserve" also reduces the amount of copies created by half
//by using "emplace_back" instead of "push_back", you can create a new obj in the vector instead of creating a copy of an already existing "Vertex" obj
//this will now bring the amount of copies down to 0 with both optimizations
void vectorExample2() {
    std::vector<VertexA> verticies;
    verticies.reserve(3);
    verticies.emplace_back(1, 2, 3);
    verticies.emplace_back(4, 5, 6);
    verticies.emplace_back(7, 8, 9);
}

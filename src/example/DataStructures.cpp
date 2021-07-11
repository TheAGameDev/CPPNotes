#include "header/Headers.h"

//If you allocating memory for a single scope, then it'll be better to use a stack allocated array
//benefit of using a std::array instead is that you can check the size and get an interator to the array
void dataStructuresExample() {
    int array[5];
    int* heaparray = new int[5];
    delete[] heaparray;

    std::array<int, 10> collection;
    collection.size();
}

//alloca is a function that allows you to allocate memory on the stack
//with alloca, the compiler doesn't know how big the size will be and will lack compiler optimizations
//by adding "constexpr" we can specify that the function can be evaluated at compile time
//Overriding "[]" will allow us to grab the index of the ArrayB class
template<typename T, size_t S>
class ArrayB {
public:
    constexpr int Size() const {
        return S;
    }

    //Using "T" here will make a copy rather than pass a reference (you wan "T&")
    T& operator[](size_t index) {
        return m_Data[index];
    }
    const T& operator[](size_t index) const {
        return m_Data[index];
    }

    T* Data() {
        return m_Data;
    }
    const T* Data() const {
        return m_Data;
    }
private:
    T m_Data[S];
};

//Can't fit "size" variable into a "<>" unless we make it a "constexpr"
void dataStructuresExample2() {
    int size = 5;
    ArrayB<int, 5> data;
    data.Size();

    static_assert(data.Size() < 10, "Size is too large!");

    const auto& arrayReference = data;
    for (int i = 0; i < data.Size(); i++) {
        data[i] = 2;
    }
}

//VectorIterator is used in "iteratorExample2()", look below to find it
template<typename Vector>
class VectorIteratorA {
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
public:
    VectorIteratorA(PointerType ptr) : m_Ptr(ptr) {
    }

    VectorIteratorA& operator++() {
        m_Ptr++;
        return *this;
    }
    VectorIteratorA& operator++(int) {
        VectorIteratorA iterator = *this;
        ++(*this);
        return iterator;
    }
    VectorIteratorA& operator--() {
        m_Ptr--;
        return *this;
    }
    VectorIteratorA& operator--(int) {
        VectorIteratorA iterator = *this;
        --(*this);
        return iterator;
    }
    ReferenceType operator[](int index) {
        return *(m_Ptr + index);
    }
    PointerType operator->() {
        return m_Ptr;
    }
    ReferenceType operator*() {
        return *m_Ptr;
    }
    bool operator==(const VectorIteratorA& other) {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const VectorIteratorA& other) {
        return !(*this == other);
    }
private:
    PointerType m_Ptr;
};

template<typename T>
class VectorA {
public:
    using ValueType = T;
    using Iterator = VectorIteratorA<VectorA<T>>;
public:
    VectorA() {
        ReAlloc(2);
    }

    ~VectorA() {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    //Added "std::move" to avoid copying
    void PushBack(const T& value) {
        if (m_Size >= m_Capacity) {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T&& value) {
        if (m_Size >= m_Capacity) {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        m_Data[m_Size] = std::move(value);
        m_Size++;
    }

    //variadic template example
    template<typename... Args>
    T& EmplaceBack(Args&&... args) {
        if (m_Size >= m_Capacity) {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void PopBack() {
        if (m_Size > 0) {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear() {
        for (size_t i = 0; i < m_Size; i++) {
            m_Data[i].~T();
        }
        m_Size = 0;
    }

    T& operator[](int index) {
        if (index >= m_Size) {
            //assert
        }
        return m_Data[index];
    }
    const T& operator[](int index) const {
        if (index >= m_Size) {
            //assert
        }
        return m_Data[index];
    }

    size_t size() const {
        return m_Size;
    }

    Iterator begin() {
        return Iterator(m_Data);
    }

    Iterator end() {
        return Iterator(m_Data + m_Size);
    }
private:
    //Added "std::move" to avoid copying
    void ReAlloc(size_t newCapacity) {
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));
        if (newCapacity < m_Size) {
            m_Size = newCapacity;
        }
        for (size_t i = 0; i < m_Size; i++) {
            new (&newBlock[i]) T(std::move(m_Data[i]));
        }
        for (size_t i = 0; i < m_Size; i++) {
            m_Data[i].~T();
        }
        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

struct Vec3A {
    int x, y, z;
    Vec3A() : x(0), y(0), z(0) {
    }
    Vec3A(int xIn, int yIn, int zIn) : x(xIn), y(yIn), z(zIn) {
    }
};

template<typename T>
static void PrintVector(const VectorA<T>& vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << std::endl;
    }
    std::cout << "------------------------------\n";
}

static void PrintVector2(const VectorA<Vec3A>& vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    }
    std::cout << "------------------------------\n";
}

//How to create a vector class that functions like std::vector
void dataStructuresExample3() {
    VectorA<std::string> vector;
    vector.PushBack("A");
    vector.PushBack("Game");
    vector.PushBack("Vector");
    PrintVector(vector);
    VectorA<Vec3A> vector2;
    vector2.EmplaceBack(1, 2, 3);
    vector2.EmplaceBack(4, 5, 6);
    PrintVector2(vector2);
    vector2.PopBack();
    PrintVector2(vector2);
    vector2.Clear();
    PrintVector2(vector2);
}
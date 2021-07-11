#include "header/Headers.h"

template<typename Vector>
class VectorIteratorB {
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
public:
    VectorIteratorB(PointerType ptr) : m_Ptr(ptr) {
    }

    VectorIteratorB& operator++() {
        m_Ptr++;
        return *this;
    }
    VectorIteratorB& operator++(int) {
        VectorIteratorB iterator = *this;
        ++(*this);
        return iterator;
    }
    VectorIteratorB& operator--() {
        m_Ptr--;
        return *this;
    }
    VectorIteratorB& operator--(int) {
        VectorIteratorB iterator = *this;
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
    bool operator==(const VectorIteratorB& other) {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const VectorIteratorB& other) {
        return !(*this == other);
    }
private:
    PointerType m_Ptr;
};

template<typename T>
class VectorB {
public:
    using ValueType = T;
    using Iterator = VectorIteratorB<VectorB<T>>;
public:
    VectorB() {
        ReAlloc(2);
    }

    ~VectorB() {
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

//iterators are used to iterate over a set of data (std::vector, std::array, etc...)
//for loops are a common way of iterating through values
//a range-based for loop replaces the use of iterators in a for loop (unless you want to manipulate a specific variable in the loop)
//structured bindings can also be used in a range-based for loop
void iteratorExample() {
    std::vector<int> values = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << std::endl;
    }
    for (int value : values) {
        std::cout << value << std::endl;
    }
    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::unordered_map<std::string, int> map;
    map["AGame"] = 5;
    map["C++"] = 2;
    for (std::unordered_map<std::string, int>::const_iterator it = map.begin(); it != map.end(); it++) {
        auto& key = it->first;
        auto& value = it->second;
        std::cout << key << " = " << value << std::endl;
    }
    for (auto kv : map) {
        auto& key = kv.first;
        auto& value = kv.second;
        std::cout << key << " = " << value << std::endl;
    }
    for (auto [key, value] : map) {
        std::cout << key << " = " << value << std::endl;
    }
}

//recreates the iterator of std::vector
//swap "std::vector<int>::iterator" with "Vector<int>::Iterator"
void iteratorExample2() {
    VectorB<int> values;
    values.EmplaceBack(1);
    values.EmplaceBack(2);
    values.EmplaceBack(3);
    values.EmplaceBack(4);
    values.EmplaceBack(5);
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << std::endl;
    }
    for (int value : values) {
        std::cout << value << std::endl;
    }
    for (VectorB<int>::Iterator it = values.begin(); it != values.end(); it++) {
        std::cout << *it << std::endl;
    }
}
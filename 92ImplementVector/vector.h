#pragma once
#include <cstddef>


template<typename T>
class Vector{
public:
    Vector(){
        ReAlloc(2);      
    }
    void PushBack(const T& value){
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);  // 1.5 times bigger (50% increase

        m_Data[m_Size] = value;
        m_Size++;
    }
    void PushBack(T&& value){
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);  // 1.5 times bigger (50% increase

        m_Data[m_Size] = std::move(value);
        m_Size++;
    }
    template<typename... Args>
    T& EmplaceBack(Args&&... args){
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);  // 1.5 times bigger (50% increase

        // m_Data[m_Size] = T(std::forward<Args>(args)...);  // it will call move constructor
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);  // placement new, it will call constructor

        return m_Data[m_Size++];
    }
    void PopBack(){
        if (m_Size > 0){
            m_Size--;
            m_Data[m_Size].~T();
        }
    }
    void Clear(){
        for (size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }
        m_Size = 0;
    }
    size_t Size() const {
        return m_Size;
    }
    const T& operator[](size_t index) const {
        return m_Data[index];
    }
    T& operator[](size_t index) {
        return m_Data[index];
    }
    ~Vector(){
        delete[] m_Data;  // It may delete twice
    }
private:
    void ReAlloc(size_t newCapacity){
        // allocate new block of memory
        T* newBlock = new T[newCapacity];  // not initialized yet

        // if new capacity is less than current size, reallocation only copy elements up to the new capacity
        if (newCapacity < m_Size)  
            m_Size = newCapacity;

        // copy or move old elements into new block
        for (size_t i = 0; i < m_Size; i++)
            newBlock[i] = std::move(m_Data[i]);  // call copy constructor ( there is a bug here, new block are not initialized yet)
        
        // delete old block
        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;  // how much allocated
};
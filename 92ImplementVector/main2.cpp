// g++ -g -o main2 main2.cpp --std=c++11

#include <iostream>
#include <string>

#include "vector2.h"
struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int* a;
    Vector3(){a = new int[5];};
    Vector3(float scalar):x(scalar),y(scalar),z(scalar){a = new int[5];};
    Vector3(float x, float y, float z):x(x),y(y),z(z){a = new int[5];};
    Vector3(const Vector3& other) = delete;
    Vector3(Vector3&& other):x(other.x),y(other.y),z(other.z){
        std::cout << "Move" << std::endl;
        a = other.a;
        other.a = nullptr;
    }
    Vector3& operator=(const Vector3& other) = delete;

    Vector3& operator=(Vector3&& other){
        std::cout << "Move" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        a = other.a;
        other.a = nullptr;
        return *this;
    }
    ~Vector3(){
        delete[] a;
        std::cout << "Destroy" << std::endl;
    }
};

template<typename T>
void PrintVector(const Vector<T>& vector){
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i] << std::endl;
}

template<>
void PrintVector(const Vector<Vector3>& vector){
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i].x << "," << vector[i].y << "," << vector[i].z << std::endl;
}


int main(int argc, char const *argv[])
{
    {
        Vector<Vector3> vector;
        vector.EmplaceBack(1.0f);
        vector.EmplaceBack(1.0f, 2.0f, 3.0f);
        vector.PopBack();
        PrintVector(vector);
    }
    return 0;
}

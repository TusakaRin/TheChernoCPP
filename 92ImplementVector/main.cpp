// g++ -g -o main main.cpp --std=c++11

#include <iostream>
#include <string>

#include "vector.h"
struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    Vector3(){};
    Vector3(float scalar):x(scalar),y(scalar),z(scalar){};
    Vector3(float x, float y, float z):x(x),y(y),z(z){};
    Vector3(const Vector3& other):x(other.x),y(other.y),z(other.z){
        std::cout << "Copy" << std::endl;
    }
    Vector3(Vector3&& other):x(other.x),y(other.y),z(other.z){
        std::cout << "Move" << std::endl;
    }
    Vector3& operator=(const Vector3& other){
        std::cout << "Copy" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    Vector3& operator=(Vector3&& other){
        std::cout << "Move" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    ~Vector3(){
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
    // Vector<std::string> vector;
    // vector.PushBack("Cherno");
    // vector.PushBack("C++");
    // vector.PushBack("Vector");
    // vector.PushBack("Vector");
    // vector.PushBack("Vector");
    // vector.PushBack("Vector");
    // vector.PushBack("Vector");
    // vector.PushBack("Vector");
    // vector.PushBack("Vector");
    // vector.PushBack("Vector");
    // PrintVector(vector);


    // Vector<Vector3> vector;
    // vector.PushBack(Vector3(1.0f));
    // vector.PushBack(Vector3(1.0f, 2.0f, 3.0f));
    // vector.PushBack(Vector3());
    // PrintVector(vector);


    Vector<Vector3> vector;
    vector.EmplaceBack(1.0f);
    vector.EmplaceBack(1.0f, 2.0f, 3.0f);
    vector.EmplaceBack(2.0f, 2.0f, 3.0f);
    vector.EmplaceBack();
    PrintVector(vector);

    vector.PopBack();
    vector.PopBack();
    PrintVector(vector);

    vector.EmplaceBack(3.0f, 2.0f, 3.0f);
    vector.EmplaceBack(4.0f, 2.0f, 3.0f);
    PrintVector(vector);

    vector.Clear();
    PrintVector(vector);

    vector.EmplaceBack(5.0f, 2.0f, 3.0f);
    vector.EmplaceBack(6.0f, 2.0f, 3.0f);

    PrintVector(vector);
    return 0;
}

#include <string>
#include <iostream>


class Example{
public:
	Example() {
		std::cout << "Created Entity!" << std::endl;
	}
	Example(int x) {
		std::cout << "Created Entity with " << x << "!" << std::endl;
	}
};


class Entity {
private:
	Example e;
public:
	Entity() {
		e = Example(1);
	}
};

class Entity2{
private:
	Example e;
public:
	Entity2() : e(Example(2)){
	}
};


int main() {
	Entity e;
	// Created Entity!
	// Created Entity with 1!
	
	Entity2 e2;
	// Created Entity with 2!
}

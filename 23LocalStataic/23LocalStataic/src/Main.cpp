#include <iostream>

void func() {
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

int main() {
	func();
	func();
	func();
	std::cin.get();
}
//Write a program that defines a unique pointer to an integer value.
//Use the std::make_unique function to create a pointer.

#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> p = std::make_unique<int>(123);
    std::cout << "The value of a pointed-to object is: " << *p << '\n';
	return 0;
}
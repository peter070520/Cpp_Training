//Write a program that defines a class with two data members, a user-defined constructor, and one member function.
//Create a unique pointer to an object of a class.
//Use the smart pointer to access the member function.

#include <iostream>
#include <memory>

class MyClass
{
private:
    int x;
    double d;
public:
    MyClass(int xx, double dd)
         : x{ xx }, d{ dd }
    {}
    void printdata()
    {
        std::cout << "Data members values are: " << x << " and: " << d;
    }
};
int main()
{
    std::unique_ptr<MyClass> p = std::make_unique<MyClass>(123, 456.789);
    p->printdata();
	return 0;
}
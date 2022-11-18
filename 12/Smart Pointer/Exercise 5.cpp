//Write a program that defines a base class with a pure virtual member function.
//Create a derived class that overrides a virtual function in the base class.
//Create a polymorphic object of a derived class through a unique pointer to a base class.
//Invoke the overridden member function through a unique pointer.

#include <iostream>
#include <memory>

class BaseClass
{
public:
    virtual void dowork() = 0;
    virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass
{
public:
    void dowork() override
    {
        std::cout << "Do work from a DerivedClass." << '\n';
    }
};

int main()
{
    std::unique_ptr<BaseClass> p = std::make_unique<DerivedClass>();
    p->dowork();
	return 0;
} // p1 goes out of scope here

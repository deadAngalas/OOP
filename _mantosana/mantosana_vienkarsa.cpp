#include<iostream>
#include<cstdlib>
using namespace std;

// base class
class Animal
{
   public:
    void eat()
    {
        cout << "I can eat!" << endl;
    }

    void sleep()
    {
        cout << "I can sleep!" << endl;
    }
};

// derived class
class Dog : private Animal
{
   public:
    void bark()
    {
        cout << "I can bark! Woof woof!!" << endl;
    }
    void eat2()
    {
      this->eat();
    }
    void sleep2()
    {
      this->sleep();
    }
};

int main() {
    // Create object of the Dog class
    Dog dog1;

    // Calling members of the base class
    dog1.eat2();
    dog1.sleep2();

    // Calling member of the derived class
    dog1.bark();
system("pause>>nul");
return 0;
    }

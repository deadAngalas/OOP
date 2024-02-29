#include<iostream>
#include<cstdlib>
using namespace std;
#include <iostream>
using namespace std;

class A
{
    public:
      void display()
      {
          cout<<"Base class content.";
      }
};

class B : public A
{

};

class C : public B
{
 
};

int main()
{
    C obj;
    obj.display();

system("pause>>nul");
return 0;
    }

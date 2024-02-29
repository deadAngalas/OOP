#include<iostream>
#include<cstdlib>
using namespace std;

class base    //single base class
{
private:
  int x;
public:
  void getdata()
  {
     cout << "Enter the value of x = "; cin >> x;
  }

  int get_x()
  {
    return x;
  }
 };

class derive : public base    //single derived class
{
private:
    int y;
public:
   void readdata()
   {
     cout << "Enter the value of y = "; cin >> y;
   }
   void product()
   {
     cout << "Product = " << get_x() * y;
   }
 };

 int main()
 {
    derive a;     //object of derived class
    a.getdata();
    a.readdata();
    a.product();

system("pause>>nul");
return 0;
    }

#include<iostream>
#include<cstdlib>
#include "functions_Triangle_Template.cpp"
#define N 100

using namespace std;

int main()
{
  Triangle<char> t1('a', 'b', 'c');
  double x;
  bool OK;

  // do
  // {
  //   cout << "\n  Enter a: ";
  //   cin >> x;
  //   t1.set_a(x);
  //   cout << "  Enter b: ";
  //   cin >> x;
  //   t1.set_b(x);
  //   cout << "  Enter c: ";
  //   cin >> x;
  //   t1.set_c(x);
  //
  //   OK = t1.check();
  //
  //   if(!OK)
  //   {
  //     system("cls");
  //     cout << "\n\nNot existing triangle! Try again!\n";
  //   }
  // }
  // while(!OK);

  OK = t1.check();
  if(OK)
  {
    cout << "\n\n  a = " << t1.get_a() << "\n  b = " << t1.get_b() << "\n  c = " << t1.get_c() << endl;

    double per = t1.perimetr();
    cout << "\n  P = " << per;

    double laukums = t1.laukums();
    cout << "\n  S = " << laukums;
  }
  else cout << "\n\nNot existing triangle!\n";

  //delete &t1;
  t1.~Triangle();
  system("pause>nul");
  return 0;
}

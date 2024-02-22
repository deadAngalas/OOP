#include<iostream>
#include<cmath>
#include "class.Triangle_Template.cpp"

using namespace std;

template <class T> Triangle<T>::Triangle()
{
  a = 0;
  b = 0;
  c = 0;
}

template <class T> Triangle<T>::Triangle(T a1, T b1, T c1)
{
  a = a1;
  b = b1;
  c = c1;
}

template <class T> void Triangle<T>::set_a(T aa)
{
  a = aa;
}

template <class T> void Triangle<T>::set_b(T bb)
{
  b = bb;
}

template <class T> void Triangle<T>::set_c(T cc)
{
  c = cc;
}

template <class T> double Triangle<T>::get_a()
{
  return a;
}

template <class T> double Triangle<T>::get_b()
{
  return b;
}

template <class T> double Triangle<T>::get_c()
{
  return c;
}

template <class T> double Triangle<T>::perimetr()
{
  return a + b + c;
}

template <class T> double Triangle<T>::laukums()
{
  double pp = perimetr()/2;
  return sqrt(pp*(pp-a)*(pp-b)*(pp-c));
}

template <class T> bool Triangle<T>::check()
{
  if(a + b > c && a + c > b && b + c > a) return true;
  return false;
}

template <class T> Triangle<T>::~Triangle()
{
  cout << "\n\n\tEND!\n";
}

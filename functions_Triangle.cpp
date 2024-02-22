#include<iostream>
#include<cmath>
#include "class.Triangle.cpp"

using namespace std;

Triangle::Triangle()
{
  a = 0;
  b = 0;
  c = 0;
}

Triangle::Triangle(double a1, double b1, double c1)
{
  a = a1;
  b = b1;
  c = c1;
}

void Triangle::set_a(double aa)
{
  a = aa;
}

void Triangle::set_b(double bb)
{
  b = bb;
}

void Triangle::set_c(double cc)
{
  c = cc;
}

double Triangle::get_a()
{
  return a;
}

double Triangle::get_b()
{
  return b;
}

double Triangle::get_c()
{
  return c;
}

double Triangle::perimetr()
{
  return a + b + c;
}

double Triangle::laukums()
{
  double pp = perimetr()/2;
  return sqrt(pp*(pp-a)*(pp-b)*(pp-c));
}

bool Triangle::check()
{
  if(a + b > c && a + c > b && b + c > a) return true;
  return false;
}

Triangle::~Triangle()
{
  cout << "\n\n\tEND!\n";
}

#include "class.Triangle.cpp"
#include <cmath>

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

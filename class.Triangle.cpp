class Triangle
{
private:
  double a;
  double b;
  double c;
public:
  Triangle();
  ~Triangle();
  Triangle(double a1, double b1, double c1);
  void set_a(double aa);
  void set_b(double bb);
  void set_c(double cc);
  double get_a();
  double get_b();
  double get_c();
  double perimetr();
  double laukums();
  bool check();
};

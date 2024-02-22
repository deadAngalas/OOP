template <class T> class Triangle
{
private:
  T a, b, c;
public:
  Triangle();
  ~Triangle();
  Triangle(T a1, T b1, T c1);
  void set_a(T aa);
  void set_b(T bb);
  void set_c(T cc);
  double get_a();
  double get_b();
  double get_c();
  double perimetr();
  double laukums();
  bool check();
};

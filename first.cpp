#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

class strings
{
private:
  char str[20];
  int len;
public:
  strings();
  void copy(char []);
  int length();
  void display();
};

strings::strings()
{
  str[0]='\0';
  len = 0;
}

void strings::copy(char s[])
{
  if (strlen(s) < 20) strcpy(str, s);
  else
  {
    for (int i = 0; i< 20; ++i)
    str[i] = s[i];
    str[20]='\0';
    len = strlen(str);
  }
}

int strings::length()
{
  return len;
}

void strings::display() // izvadit tekstu
{
  cout << "Teksts: " << str;
}

int main()
{
  strings s1;
  char arr[] = "Mans teksts";
  s1.copy(arr);
  s1.display();

  system("pause>nul");
  return 0;
}

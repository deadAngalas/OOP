#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 20

using namespace std;

/*
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
*/

/*
class Stack
{
private:
  char s[SIZE];
  int sp;
public:
  Stack();
  void push(char v);
  char pop();
};

Stack::Stack()
{
  cout << "Initializing...\n\n";
  sp = 0;
}

void Stack::push(char v)
{
  if(sp == SIZE)
  {
    cerr << "Overflow" << endl;
    return;
  }
  s[sp] = v;
  sp++;
}

char Stack::pop()
{
  if(sp == 0)
  {
    cerr << "Underflow" << endl;
    return 0;
  }
  sp--;
  return s[sp];
}
*/

int main()
{
  /*
  strings s1;
  char arr[] = "Mans teksts";
  s1.copy(arr);
  s1.display();
  */

  Stack *s1 = new Stack();

  s1->push('A');
  s1->push('B');
  s1->push('C');

  cout << "S1 elements: \n\n";
  cout << s1->pop() << " \n";
  cout << s1->pop() << " \n";
  cout << s1->pop() << " \n";
  cout << s1->pop() << endl;

  Stack *s2 = new Stack();

  for(int i = 0; i < 20; i++)
  {
    s2->push('A' + i);
  }

  cout << "S2 elements: \n\n";
  for(int i = 0; i < 21; i++)
  {
    cout << s2->pop() << " ";
  }

  system("pause>nul");
  return 0;
}

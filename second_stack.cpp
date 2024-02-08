#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 100

using namespace std;

/*
struct Stack
{
  char s[SIZE];
  int sp;
};

void create(Stack *s)
{
  s->sp = 0;
}

char pop(Stack *s)
{
  if (s->sp == 0) cout << "Underflow\n";
  return s->s[--s->sp];
}

void push(Stack *s, char v)
{
  if (s->sp == SIZE) cout << "Overflow\n";
  s->s[s->sp++] = v;
}
*/

class Stack
{
private:
  char s[SIZE];
  int sp;
public:
  Stack();
  char pop();
  void push(char v);
};

Stack::Stack()
{
  s[0]='\0';
  sp = 0;
}

char Stack::pop()
{
  if (sp == 0) cout << "Underflow\n";
  return s[--sp];
}

void Stack::push(char v)
{
  if (sp == SIZE) cout << "Overflow\n";
  s[sp++] = v;
}

int main()
{
  /*
  Stack *s = new Stack();
  create(s);
  push(s, 'a');
  cout << pop(s);
  */

  Stack steks1, steks2;

  for(int i = 0; i < 26; i++)
  {
    steks1.push('a' + i);
  }

  for(int i = 0; i < 26; i++)
  {
    cout << steks1.pop() << " ";
  }

  system("pause>nul");
  return 0;
}

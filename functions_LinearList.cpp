#include<iostream>
#include<cstdlib>
#include<conio.h>
#include "class.LinearList.cpp"
#define N 100

using namespace std;

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |     Linked            | |"<< endl;
  cout <<"              | |         List          | |"<< endl;
  cout <<"              | |            Program    | |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              |  _____________________  |"<< endl;
  cout <<"              |___________________________|"<< endl;
  cout <<"            ,---_____     []     _______------,"<< endl;
  cout <<"            |      ______________           |"<< endl;
  cout <<"        ___________________________________   | ___"<< endl;
  cout <<"        |                                   |   |    )"<< endl;
  cout <<"        |  _ _ _                 [-------]  |   |   ("<< endl;
  cout <<"        |  o o o                 [-------]  |      _)_"<< endl;
  cout <<"        |__________________________________ |       "<< endl;
  cout <<"    -------------------------------------|      ( )"<< endl;
  cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout << endl;
}

Node* CreateNode()
{
  Node *newNode = new Node();
  cout << "\nEnter number to node: ";
  cin >> newNode->data;
  newNode->link = NULL;
  return newNode;
}

int Saraksts::NodeCount()
{
  return size;
}

void Saraksts::PlusSize()
{
  size++;
}

/*
Saraksts::Saraksts()
{
  head = NULL;
  size = 0;
}
*/

void Saraksts::Init()
{
  head = NULL;
  size = 0;
}

Node*& Saraksts::headCheck()
{
  // return atsauci (adress - &) uz raditaju (ptr - *) uz head
  // lauj gan parbaudit vai eksiste head gan mainit head
  return head;
}

void Saraksts::PrintList()
{
  Node *cur;
  cout<<"\nList elements:\n";
  cur = head;
  while (cur != NULL)
    {
      cout << cur->data << " ";
      cur = cur->link;
    }
}

void Saraksts::AddFirst()
{
  Node *cur = new Node;
  cur = CreateNode();
  cur->link = head;
  head = cur;
  size++;
}

void Saraksts::AddEnd()
{
  Node *cur, *cur1;
  cur1 = new Node;
  cur1 = CreateNode();

  cur = head;
  while (cur->link != NULL)
  {
      cur = cur->link;
  }
  cur->link = cur1;
  size++;
}

Node* Saraksts::FindNode(int x)
{
  Node *cur;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      cur = cur->link;
  }

  return cur;
}

Node* Saraksts::PreviousNode(int x)
{
  Node *cur, *prev;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      prev = cur;
      cur = cur->link;
  }

  return prev;
}

Node* Saraksts::NextNode(int x)
{
  Node *cur, *next;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      cur = cur->link;
  }
  next = cur->link;

  return next;
}

void Saraksts::AddBefore()
{
  int x;
  Node *cur, *newNode, *prev;
  cout << "Before which node add: ";
  cin >> x;

  cur = FindNode(x);
  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode();
    prev = PreviousNode(x);
    if(head->data == x)
    {
      newNode->link = head;
      head = newNode;
    }
    else
    {
      prev->link = newNode;
      newNode->link = cur;
    }
    cout << "New node is added!\n";
    size++;
  }
  else cout << "Node does not exist!\n";
}

void Saraksts::AddAfter()
{
  int x;
  Node *cur, *newNode, *next;
  cout << "After which node add: ";
  cin >> x;

  cur = FindNode(x);

  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode();
    next = NextNode(x);

    if(!next)
    {
      cur->link = newNode;
    }
    else
    {
      cur->link = newNode;
      newNode->link = next;
    }

    cout << "New node is added!\n";
    size++;
  }
  else cout << "Node does not exist!\n";
}

void Saraksts::RemoveNodeBeginning()
{
  Node* cur = head->link;
  delete head;
  head = cur; // return new head
  size--;
}

void Saraksts::RemoveNodeEnd()
{
  Node *cur, *prev;

  if(head->link != NULL) // if there is more nodes after head
  {
    cur = head;

    while(cur->link!=NULL)
    {
      prev = cur;
      cur = cur->link;
    }
    delete cur; // delete last
    prev->link = NULL;
    size--;
  }
  else // if head is the one node
  {
    // delete head;
    // head = NULL;
    RemoveNodeBeginning();
  }
}

void Saraksts::RemoveBefore()
{
  int x;
  cout << "Before which node remove: ";
  cin >> x;

  Node *cur, *prev, *prev2;

  cur = FindNode(x);

  if(cur)
  {
    cout << "Node exist!\n";
    if(head->data == x)
    {
      cout << "Nothing to delete!\n";
    }
    else
    {
      prev = PreviousNode(x);
      if(prev->data == head->data)
      {
        head = cur;
        delete prev;
      }
      else
      {
        prev2 = PreviousNode(prev->data);
        prev2->link = cur;
        delete prev;
      }
      cout << "Node has been removed!\n";
      size--;
    }
  }
  else cout << "Node does not exist!\n";
}

void Saraksts::RemoveAfter()
{
  int x;
  cout << "After which node remove: ";
  cin >> x;

  Node *cur, *next, *next2;
  cur = FindNode(x);

  if(cur)
  {
    cout << "Node exist!\n";
    if(cur->link == NULL)
    {
      cout << "Nothing to delete!\n";
    }
    else
    {
      next = NextNode(x);
      if(next->link == NULL)
      {
        RemoveNodeEnd();
      }
      else
      {
        next2 = NextNode(next->data);
        delete next;
        cur->link = next2;
        size--;
      }
      cout << "Node has been removed!\n";
    }
  }
  else cout << "Node does not exist!\n";
}

void Saraksts::RemoveAll()
{
  Node* cur;
  while(head != nullptr)
  {
    cur = head;
    head = head->link; // next node
    delete cur; // delete current node
  }
  size = 0;
}

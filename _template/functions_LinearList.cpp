#include<iostream>
#include<cstdlib>
#include "class.LinearList.cpp"

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

template <typename T>Node<T>* CreateNode()
{
  Node<T> *newNode = new Node<T>();
  cout << "\nEnter number to node: ";
  cin >> newNode->data;
  newNode->link = NULL;
  return newNode;
}

template <typename T>int Saraksts<T>::NodeCount()
{
  return size;
}

template <typename T>void Saraksts<T>::PlusSize()
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

template <typename T>void Saraksts<T>::Init()
{
  head = NULL;
  size = 0;
}

template <typename T>Node<T>*& Saraksts<T>::headCheck()
{
  // return atsauci (adress - &) uz raditaju (ptr - *) uz head
  // lauj gan parbaudit vai eksiste head gan mainit head
  return head;
}

template <typename T>void Saraksts<T>::PrintList()
{
  Node<T> *cur;
  cout<<"\nList elements:\n";
  cur = head;
  while (cur != NULL)
    {
      cout << cur->data << " ";
      cur = cur->link;
    }
}

template <typename T>void Saraksts<T>::AddFirst()
{
  Node<T> *cur = new Node<T>;
  cur = CreateNode<T>();
  cur->link = head;
  head = cur;
  size++;
}

template <typename T>void Saraksts<T>::AddEnd()
{
  Node<T> *cur, *cur1;
  cur1 = new Node<T>;
  cur1 = CreateNode<T>();

  cur = head;
  while (cur->link != NULL)
  {
      cur = cur->link;
  }
  cur->link = cur1;
  size++;
}

template <typename T>Node<T>* Saraksts<T>::FindNode(T x)
{
  Node<T> *cur;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      cur = cur->link;
  }

  return cur;
}

template <typename T>Node<T>* Saraksts<T>::PreviousNode(T x)
{
  Node<T> *cur, *prev;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      prev = cur;
      cur = cur->link;
  }

  return prev;
}

template <typename T>Node<T>* Saraksts<T>::NextNode(T x)
{
  Node<T> *cur, *next;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      cur = cur->link;
  }
  next = cur->link;

  return next;
}

template <typename T>void Saraksts<T>::AddBefore()
{
  T x;
  Node<T> *cur, *newNode, *prev;
  cout << "Before which node add: ";
  cin >> x;

  cur = FindNode(x);
  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode<T>();
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

template <typename T>void Saraksts<T>::AddAfter()
{
  T x;
  Node<T> *cur, *newNode, *next;
  cout << "After which node add: ";
  cin >> x;

  cur = FindNode(x);

  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode<T>();
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

template <typename T>void Saraksts<T>::RemoveNodeBeginning()
{
  Node<T>* cur = head->link;
  delete head;
  head = cur; // return new head
  size--;
}

template <typename T>void Saraksts<T>::RemoveNodeEnd()
{
  Node<T> *cur, *prev;

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

template <typename T>void Saraksts<T>::RemoveBefore()
{
  T x;
  cout << "Before which node remove: ";
  cin >> x;

  Node<T> *cur, *prev, *prev2;

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

template <typename T>void Saraksts<T>::RemoveAfter()
{
  T x;
  cout << "After which node remove: ";
  cin >> x;

  Node<T> *cur, *next, *next2;
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

template <typename T>void Saraksts<T>::RemoveAll()
{
  Node<T>* cur;
  while(head != nullptr)
  {
    cur = head;
    head = head->link; // next node
    delete cur; // delete current node
  }
  size = 0;
}

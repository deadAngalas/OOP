#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<conio.h>
#include "class.BST.cpp"

using namespace std;

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |     Binary            | |"<< endl;
  cout <<"              | |         Search        | |"<< endl;
  cout <<"              | |              Tree     | |"<< endl;
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

Node *CreateNode()
{
  Node *newNode = new Node;
  cout << "\nEnter number to node: ";
  cin >> newNode->data;

  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

//-------- PRINT ----------

void BSTree::PrintTree(Node *cur, int padding) // RVL princips - 90 gradi
{
  if(cur != NULL)
  {
    PrintTree(cur->right, padding+=5);
    cout << setw(padding) << "[" << cur->data << "]" << endl;
    PrintTree(cur->left, padding);
  }
}

void BSTree::PreOrder(Node *p) // VLR
{
  if(p != NULL)
  {
    cout << p->data << " ";
    PreOrder(p->left);
    PreOrder(p->right);
  }
}

void BSTree::InOrder(Node *p) // LVR
{
  if(p != NULL)
  {
    InOrder(p->left);
    cout << p->data << " ";
    InOrder(p->right);
  }
}

void BSTree::PostOrder(Node *p) // LRV
{
  if(p != NULL)
  {
    PostOrder(p->left);
    PostOrder(p->right);
    cout << p->data << " ";
  }
}

//------------------------

BSTree::BSTree()
{
  root = NULL;
}

Node*& BSTree::rootCheck()
{
  return root;
}

void BSTree::AddNode()
{
  Node *newNode, *cur;
  newNode = CreateNode();

  cur = root;

  while((cur->data > newNode->data && cur->left != NULL) || (cur->data <= newNode->data && cur->right != NULL))
  {
    while(cur->data > newNode->data && cur->left != NULL)
    {
      cur = cur->left;
    }
    while(cur->data <= newNode->data && cur->right != NULL)
    {
      cur = cur->right;
    }
  }

  if(cur->data > newNode->data && cur->left == NULL)
  {
    cur->left = newNode;
  }
  if(cur->data <= newNode->data && cur->right == NULL)
  {
    cur->right = newNode;
  }
}

Node* BSTree::FindNode(int x)
{
  Node *cur = new Node;
  cur = root;

  while((cur->data > x && cur->left != NULL) || (cur->data <= x && cur->right != NULL) && cur->data != x)
  {
    while(cur->data > x && cur->left != NULL && cur->data != x)
    {
      cur = cur->left;
    }
    while(cur->data <= x && cur->right != NULL && cur->data != x)
    {
      cur = cur->right;
    }
  }

  if(cur->data == x)
  {
    cout << "\nSuccessfully Found! :)\n";
  }
  else
  {
    cur = NULL;
    cout << "\nSorry! There is no your Node! :(\n";
  }

  return cur;
}

Node* BSTree::FindParent(int x)
{
  Node *cur = new Node;
  Node *parent;
  cur = root;

  while((cur->data > x && cur->left != NULL) || (cur->data <= x && cur->right != NULL) && cur->data != x)
  {
    while(cur->data > x && cur->left != NULL && cur->data != x)
    {
      parent = cur;
      cur = cur->left;
    }
    while(cur->data <= x && cur->right != NULL && cur->data != x)
    {
      parent = cur;
      cur = cur->right;
    }
  }

  if(root->data == x || cur->data != x)
  {
    parent = NULL;
  }

  return parent;
}

int BSTree::NodesCount(Node *cur)
{
  if(cur != NULL)
  {
    return 1 + NodesCount(cur->left) + NodesCount(cur->right);
  }
  else return 0;
}

Node* BSTree::SwapTree(Node *cur)
{
  Node *temp1 = NULL;
  Node *temp2 = NULL;

  if(cur != NULL)
  {
    temp1 = SwapTree(cur->left);
    temp2 = SwapTree(cur->right);
    cur->right = temp1;
    cur->left = temp2;
  }
  return cur;
}

void BSTree::RemoveNode()
{
  Node *x, *y, *temp;

  int value;
  cout << "Enter which Node need to remove: ";
  cin >> value;
  x = FindNode(value);

  if(x != NULL)
  {
    // Node who is a root
    if(x == root)
    {
      // root who has no children
      if(x->left == NULL && x->right == NULL)
      {
        delete root;
        cout << "\nTree was fully removed!" << endl;
        root = NULL;
      }
      // root who has only right child
      else if(x->left == NULL)
      {
        root = x->right;
        delete x;
        cout << "\nRoot was successfully removed!" << endl;
      }
      // root who has only left child
      else if(x->right == NULL)
      {
        root = x->left;
        delete x;
        cout << "\nRoot was successfully removed!" << endl;
      }
      else
      {
        // two children
        temp = x->left;
        y = x->right;
        root = temp;
        while(temp->right != NULL) temp = temp->right;
        temp->right = y;
        delete x;
        cout << "\nRoot was successfully removed!" << endl;
      }
    }
    else
    {
      y = FindParent(value);

      // Node who has no children
      if(x->left == NULL && x->right == NULL && x != root)
      {
        if(y->left == x) y->left = NULL;
        else y->right = NULL;
        delete x;
      }

      // Node who has 1 child
      if(x->left == NULL && x->right != NULL && x != root)
      {
        if(y->left == x) y->left = x->right;
        else y->right = x->right;
        x->right = NULL;
        delete x;
      }
      if(x->left != NULL && x->right == NULL && x != root)
      {
        if(y->left == x) y->left = x->left;
        else y->right = x->left;
        x->left = NULL;
        delete x;
      }

      // Node who has 2 children
      if(x->left != NULL && x->right != NULL && x != root)
      {
        if(y->left == x)
        {
          temp = x->left;
          y->left = x->left;
          while(temp->right != NULL) temp = temp->right;
          temp->right = x->right;
          x->left = NULL;
          x->right = NULL;
        }
        else
        {
          temp = x->right;
          y->right = x->right;
          while(temp->left != NULL) temp = temp->left;
          temp->left = x->left;
          x->left = NULL;
          x->right = NULL;
        }
        delete x;
      }
      cout << "\nNode was successfully removed!" << endl;
    }
  }
}

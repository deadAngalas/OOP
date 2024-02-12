#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<conio.h>
#include "functions_BST.cpp"
#define N 100

using namespace std;

int main()
{
  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61, num12 = 112 };
  /*
  num10 = 45; it is   -
  num11 = 61; it is   =
  num12 = 112; it is  p
  */
  int choice;

  BSTree *t = new BSTree;

  system("cls");
  cout << "\n\t\tBinary Search Tree\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 2.0.1\n Date (start): 18.10.2023 / 14:28\n Date (end): 16.11.2023 / 16:18\n Modified: 12.02.2024 / 11:34\n Closed: 12.02.2024 / 14:43\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n\t\tMENU \n\n";
      cout << "-------------- CREATE --------------\n";
      cout << "1. Create Root\n";
      cout << "\n--------------- ADD ----------------\n";
      cout << "2. Add Node\n";
      cout << "\n-------------- PRINT  --------------\n";
      cout << "3. Print Root value\n";
      cout << "4. Print Tree\n";
      cout << "5. Print PreOrder (VLR)\n";
      cout << "6. Print InOrder (LVR)\n";
      cout << "7. Print PostOrder (LRV)\n";
      cout << "\n--------------- FIND ---------------\n";
      cout << "8. Find Node\n";
      cout << "\n-------------- REMOVE --------------\n";
      cout << "9. Remove Node\n";
      cout << "\n--------- COUNT & TURNING ----------\n";
      cout << "10. Count How many Nodes (-)\n";
      cout << "11. Swap Tree (=)\n";
      cout << "\n-------------- STOP ----------------\n";
      cout << "12. Stop Program (p)\n\n";
      cout << "------------------------------------\n\n";

      choice = getch();

      switch(choice)
      {
        case num1: // create root
        {
          if(!t->rootCheck())
          {
            t->rootCheck() = CreateNode();
          }
          else cout << "Root already exist!\n";
          break;
        }
        case num2: // add node
        {
          if(t->rootCheck())
          {
            t->AddNode();
          }
          else cout << "Tree does not exists!\n";
          break;
        }
        case num3:
        {
          if(t->rootCheck())
          {
            cout << "Root data: " << t->rootCheck()->data << endl;
            cout << "Root left pointer: " << t->rootCheck()->left << endl;
            cout << "Root right pointer: " << t->rootCheck()->right << endl;
          }
          else cout << "Root does not exists! Create Root!\n";
          system("pause>nul");
          break;
        }
        case num4:
        {
          if(t->rootCheck())
          {
            int padding = 0;
            cout << "Tree elements:\n\n";
            t->PrintTree(t->rootCheck(), padding);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num5:
        {
          if(t->rootCheck())
          {
            cout << "Tree elements (VLR):\n";
            t->PreOrder(t->rootCheck());
          }
          else cout << "Tree does not exists!\n";
          break;
        }
        case num6:
        {
          if(t->rootCheck())
          {
            cout << "Tree elements (LVR):\n";
            t->InOrder(t->rootCheck());
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num7:
        {
          if(t->rootCheck())
          {
            cout << "Tree elements (LRV):\n";
            t->PostOrder(t->rootCheck());
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num8: // find
        {
          if(t->rootCheck())
          {
            int x;
            cout << "Enter which Node need to find: ";
            cin >> x;
            t->FindNode(x);
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num9: // remove
        {
          if(t->rootCheck())
          {
            t->RemoveNode();
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num10: // count
        {
          if(t->rootCheck())
          {
            int count = t->NodesCount(t->rootCheck());
            cout << "There is " << count << " Node/s in the tree!\n";
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num11: // swap
        {
          if(t->rootCheck())
          {
            t->SwapTree(t->rootCheck());
            cout << "Tree has been swapped!" << endl;
          }
          else cout << "Tree does not exists!\n";
          system("pause>nul");
          break;
        }
        case num12:
        {
          cout << "\nProgram is stopped! Goodbye!"; ProgEnd(); break;
        }
        default: cout << "Incorrect input!\n";
      }
    } while(choice != num12);

  system("pause>nul");
  return 0;
}

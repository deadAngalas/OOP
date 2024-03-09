#include<iostream>
#include<cstdlib>
#include<conio.h>
#include "functions_LinearList.cpp"

using namespace std;

int main()
{
  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61, num12 = 112, num13 = 91, num14 = 93 };
  /*
  num10 = 45; it is   -
  num11 = 61; it is   =
  num12 = 112; it is  p
  num13 = 91; it is   [
  num14 = 93; it is   ]
  */
  int choice;

  // creation and initialization of new list
  Saraksts<char>* s = new Saraksts<char>();
  s->Init();

  system("cls");
  cout << "\n\t\tLinked List\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 8.0\n Date (start): 06.09.2023 / 14:33\n Date (end): 11.10.2023 / 16:13\n Modified: 08.03.2024 / 16:03\n Closed: 09.03.2024 / 12:30\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n\t\tMENU \n\n";
      cout << "-------------- CREATE --------------\n";
      cout << "1. Create head\n";
      cout << "2. Print head value and link\n";
      cout << "\n--------------- ADD ----------------\n";
      cout << "3. Add node to list beginning\n";
      cout << "4. Add node to list end\n";
      cout << "5. Add node before\n";
      cout << "6. Add node after\n";
      cout << "\n-------------- PRINT  --------------\n";
      cout << "7. Show how many nodes exist\n";
      cout << "8. Print List\n";
      cout << "\n-------------- REMOVE --------------\n";
      cout << "9. Remove node at the beginning\n";
      cout << "10. Remove node at the end (-)\n";
      cout << "11. Remove node before (=)\n";
      cout << "12. Remove node after (p)\n";
      cout << "13. Remove all nodes ([)\n";
      cout << "\n-------------- STOP ----------------\n";
      cout << "14. Stop Program (])\n\n";
      cout << "------------------------------------\n\n";

      choice = getch();

      switch(choice)
      {
        case num1: // create head
        {
          if(!s->headCheck())
          {
            s->headCheck() = CreateNode<char>();
            s->PlusSize();
          }
          else cout << "Head already exist!\n";
          break;
        }
        case num2:
        {
          if(s->headCheck())
          {
            cout << "Head data: " << s->headCheck()->data << endl;
            cout << "Head link: " << s->headCheck()->link << endl;
          }
          else cout << "Head does not exists! Create Head!\n";
          system("pause>nul");
          break;
        }
        case num3: // add node to list beginning
                s->AddFirst();
                break;
        case num4: // add node to list end
        {
          if(s->headCheck())
          {
            s->AddEnd();
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num5: // add node before specific node
        {
          if(s->headCheck())
          {
            s->AddBefore();
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num6:
        {
          if(s->headCheck())
          {
            s->AddAfter();
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num7:
        {
          int count = s->NodeCount();
          cout << "Now there is " << count << " node/s!";
          break;
        }
        case num8:
        {
          s->PrintList();
          break;
        }
        case num14: cout << "\nProgram is stopped! Goodbye!"; ProgEnd(); break;
        case num9:
        {
          if(s->headCheck())
          {
            s->RemoveNodeBeginning();
            cout << "First node has been removed!\n";
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num10:
        {
          if(s->headCheck())
          {
            s->RemoveNodeEnd();
            cout << "Last node has been removed!\n";
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        case num11:
        {
          if(s->headCheck())
          {
            s->RemoveBefore();
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        case num12:
        {
          if(s->headCheck())
          {
            s->RemoveAfter();
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        case num13:
        {
          if(s->headCheck())
          {
            s->RemoveAll();
            cout << "All nodes have been removed!!\n";
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        default: cout << "Incorrect input!\n";
      }
    } while(choice != num14);

  system("pause>nul");
  return 0;
}

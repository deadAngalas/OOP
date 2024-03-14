#include <iostream>
#include <windows.h>

using namespace std;

const int N = 10;

DWORD WINAPI plusma(void *ptr)
{
  for (int i = 0; i < N; i++)
  {
    cout << *((char*)ptr) << endl << "\t" << i << endl;
    Sleep (rand()%2*100);
  }

  cout << "End of the thread " << *((char*)ptr) << endl;
  return 0;
}

int main()
{
 HANDLE thread_a, thread_b, thread_c;
 char id_a={'A'}, id_b={'B'}, id_c{'C'};
 DWORD id2_a, id2_b, id2_c;

 thread_a = CreateThread(NULL, 0, plusma, (void*)&id_a, 0, &id2_a);
 thread_b = CreateThread(NULL, 0, plusma, (void*)&id_b, 0, &id2_b);
 thread_c = CreateThread(NULL, 0, plusma, (void*)&id_c, 0, &id2_c);

 HANDLE tt[3];

 tt[0] = thread_a;
 tt[1] = thread_b;
 tt[2] = thread_c;

 WaitForMultipleObjects (3, tt, TRUE, INFINITE);
 CloseHandle (thread_a);
 CloseHandle (thread_b);
 CloseHandle (thread_c);

 cout << "END OF " << id_a << " " << id_b << " " << id_c << endl;

system("Pause>>nul");
return 0;
}

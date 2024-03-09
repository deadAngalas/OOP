template <typename T> struct Node
{
  T data;
  Node<T> *link;
};

template <typename T> class Saraksts
{
private:
  Node<T> *head;
  int size;
public:
  void Init();
  // Saraksts();
  Node<T>*& headCheck();
  void PlusSize();
  int NodeCount();
  void PrintList();
  Node<T>* FindNode(T x);
  Node<T>* PreviousNode(T x);
  Node<T>* NextNode(T x);
  void AddFirst();
  void AddEnd();
  void AddBefore();
  void AddAfter();
  void RemoveNodeBeginning();
  void RemoveNodeEnd();
  void RemoveBefore();
  void RemoveAfter();
  void RemoveAll();
};

struct Node
{
  int data;
  Node *link;
};

class Saraksts
{
private:
  Node *head;
  int size;
public:
  void Init();
  // Saraksts();
  Node*& headCheck();
  void PlusSize();
  int NodeCount();
  void PrintList();
  Node* FindNode(int x);
  Node* PreviousNode(int x);
  Node* NextNode(int x);
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

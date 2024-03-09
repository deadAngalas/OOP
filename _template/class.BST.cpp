template <typename T> struct Node
{
  T data;
  Node<T> *left, *right;
};

template <typename T> class BSTree
{
private:
  Node<T> *root;
public:
  BSTree();
  void PrintTree(Node<T> *cur, int padding); // real Tree
  void PreOrder(Node<T> *p); //VLR
  void InOrder(Node<T>* p); //LVR
  void PostOrder(Node<T>* p); //LRV
  Node<T>*& rootCheck();
  void AddNode();
  Node<T>* FindNodeInside(T x);
  Node<T>* FindNodeOutside();
  Node<T>* FindParent(T x);
  int NodesCount(Node<T> *cur);
  Node<T>* SwapTree(Node<T> *cur);
  void RemoveNode();
};

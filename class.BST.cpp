struct Node
{
  int data;
  Node *left, *right;
};

class BSTree
{
private:
  Node *root;
public:
  BSTree();
  void PrintTree(Node *cur, int padding); // real Tree
  void PreOrder(Node *p); //VLR
  void InOrder(Node* p); //LVR
  void PostOrder(Node* p); //LRV
  Node*& rootCheck();
  void AddNode();
  Node* FindNode(int x);
  Node* FindParent(int x);
  int NodesCount(Node *cur);
  Node* SwapTree(Node *cur);
  void RemoveNode();
};

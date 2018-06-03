#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
  explicit Node(int n) : value(n), left(NULL), right(NULL), parent(NULL) {}
  ~Node() { delete left; delete right; }

  Node* root() {
    return parent ? parent->root() : this;
  }

  void print(ostream& os, int order) const {
    if (order == -1) {
      os << value;
      if (left) {
        os << ",";
        left->print(os, order);
      }
      if (right) {
        os << ",";
        right->print(os, order);
      }
    }
    else if (order == 0) {
      if (left) {
        left->print(os, order);
        os << ",";
      }
      os << value;
      if (right) {
        os << ",";
        right->print(os, order);
      }
    }
    else {
      assert(order == 1);
      if (left) {
        left->print(os, order);
      }
      if (right) {
        if (left) {
          os << ",";
        }
        right->print(os, order);
      }
      if (left || right) {
        os << ",";
      }
      os << value;
    }
  }

  int value;
  Node* left;
  Node* right;
  Node* parent;
};

class BinaryTree {
public:
  BinaryTree() : mRoot(NULL) {}
  ~BinaryTree() { delete mRoot; }

  void setRoot(Node* root) {
    assert(mRoot == NULL);
    mRoot = root;
  }

  Node* getRoot() const { mRoot; }

  void free() { delete mRoot; mRoot = NULL; }

  // order: {-1: inorder, 0: middle, 1: postorder}
  ostream& print(ostream& os, int order) const {
    if (mRoot) {
      mRoot->print(os, order);
    }
    return os;
  }

private:
  Node* mRoot;
};

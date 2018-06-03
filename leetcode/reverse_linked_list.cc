#include "../include/utils.hh"

struct ListNode {
  ListNode(int x) : value(x), next(NULL) {}
  ~ListNode() { delete next; }

  void print(ostream& os) const {
    os << value;
    if (next) {
      os << ",";
      next->print(os);
    }
  }

  int value;
  ListNode* next;
};

static ListNode* reverseLinkedList(ListNode* head) {
  ListNode* prev = NULL;
  while (head) {
    ListNode* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

int main(int argc, char** argv) {
  ListNode* head = new ListNode(0);
  ListNode* node = head;
  for (int i = 1; i < 10; ++i) {
    node->next = new ListNode(i);
    node = node->next;
  }
  head->print(cout);
  cout << "\n";
  head = reverseLinkedList(head);
  head->print(cout);
  cout << endl;
  return 0;
}
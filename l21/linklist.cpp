#include <iostream>
#include <string>

using namespace std;

/* Type: Node
 *
 * A node in a linked list.
 */
struct Node {
  string data;
  Node* next;

  /*
   * This is the default Node constructor. Ths constructor
   * gets called when the following line of code is executed.
   *
   * Node* node = new Node;
   *
   * This version of the constructor does NOT initialize either of
   * the two field values, which can lead to undefined behavior
   * if not used carefully!
   */
  Node() {}

  /*
   * This is the two-argument version of the Node constructor.
   * The constructor gets called when the following line of code is
   * executed:
   *
   * Node* node = new Node(10, nullptr);
   *
   * This version of the constructor initializes both the data and next
   * pointer fields to the specified values.
   */
  Node(string d, Node* n) {
    data = d;
    next = n;
  }
};

/* Given a linked list, returns the length of that list. */
int lengthOf(Node* list) {
  int len = 0;

  while (list != nullptr) {
    list = list->next;
    len++;
  }

  return len;
}

/* Prints the contents of a linked list, in order. */
void printList(Node* list) {
  while (list != nullptr) {
    cout << list->data << endl;
    list = list->next;
  }
}

/* Frees all the memory used by a linked list. */
void freeList(Node* list) {
  while (list != nullptr) {
    Node* tmp = list;
    list = list->next;
    delete tmp;
  }
}

/* Add a new element containing the provided data to the beginning of the
 * specified list. */
void prependTo(Node*& list, string data) {
  Node* n = new Node(data, nullptr);

  n->next = list;
  list = n;
}

/* Adds a new element containing the provided data to the end of the specified
 * list. */
void appendTo(Node*& list, string data) {
  Node* n = new Node(data, nullptr);
  Node* tmp = list;

  while (tmp != nullptr && tmp->next != nullptr) {
    tmp = tmp->next;
  }

  if (tmp != nullptr) {
    tmp->next = n;
  } else {
    list = n;
  }
}

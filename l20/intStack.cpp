#include "IntStack.h"

IntStack::IntStack() { top = nullptr; }

IntStack::~IntStack() {
  while (!isEmpty()) {
    Node* n = top;
    top = top->next;
    delete n;
  }
}

void IntStack::push(int value) {
  Node* n = new Node;
  n->data = value;
  n->next = top;
  top = n;
}

int IntStack::pop() {
  if (isEmpty()) throw std::runtime_error("Stack underflow");

  int value = top->data;

  Node* n = top;
  top = top->next;

  delete n;
  return value;
}

bool IntStack::isEmpty() { return top == nullptr; }

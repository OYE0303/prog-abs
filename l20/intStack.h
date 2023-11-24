#pragma once

#include <stdexcept>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class IntStack {
 public:
  IntStack();
  ~IntStack();
  void push(int value);
  int pop();
  bool isEmpty();

 private:
  Node* top;
};

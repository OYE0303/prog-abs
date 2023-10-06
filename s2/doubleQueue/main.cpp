#include <iostream>
#include <queue>
#include <stack>

#include "../../Headers/printQueue.h"

using namespace std;

void doubleQueue(queue<int>& q);

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  cout << "q: ";
  printQueue(q);

  doubleQueue(q);

  cout << "q: ";
  printQueue(q);

  return 0;
}

void doubleQueue(queue<int>& q) {
  int size = q.size();

  for (int i = 0; i < size; i++) {
    int val = q.front();
    q.push(val);
    q.push(val);
    q.pop();
  }
}
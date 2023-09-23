#include <iostream>
#include <queue>

using namespace std;

#define BLUE_TEXT "\033[1;34m"
#define GREEN_TEXT "\033[1;32m"

template <typename T>

void printQueue(queue<T> q) {
  cout << BLUE_TEXT << "[";
  int i = 0;

  while (!q.empty()) {
    if (i != 0) cout << ", ";
    cout << q.front();
    q.pop();
    i++;
  }

  cout << "]" << endl;
}

void printQueue(queue<string> q) {
  cout << GREEN_TEXT << "[";
  int i = 0;

  while (!q.empty()) {
    if (i != 0) cout << ", ";
    cout << "\"" << q.front() << "\"";
    q.pop();
    i++;
  }

  cout << "]" << endl;
}
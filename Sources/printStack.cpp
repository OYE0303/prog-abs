#include <iostream>
#include <stack>

using namespace std;

#define BLUE_TEXT "\033[1;34m"
#define GREEN_TEXT "\033[1;32m"

template <typename T>

void printStack(stack<T> s) {
  cout << BLUE_TEXT << "[";
  int i = 0;

  while (!s.empty()) {
    if (i != 0) cout << ", ";
    cout << s.top();
    s.pop();
    i++;
  }

  cout << "]" << endl;
}

void printStack(stack<string> s) {
  cout << GREEN_TEXT << "[";
  int i = 0;

  while (!s.empty()) {
    if (i != 0) cout << ", ";
    cout << "\"" << s.top() << "\"";
    s.pop();
    i++;
  }

  cout << "]" << endl;
}
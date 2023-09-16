#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, char> matchingPairs = {
  {'}', '{'}, 
  {')', '('}, 
  {']', '['}
};
const string balancedChars = "({[)}]";

bool checkBalance(string str){
  stack<char> sta;

  for (char c : str) {
    if (balancedChars.find(c) == std::string::npos) continue;

    if (matchingPairs.find(c) == matchingPairs.end()) {
      sta.push(c);
      continue;
    }

    if (sta.empty() || sta.top() != matchingPairs[c]) {
      return false;
    }

    sta.pop();
  }

  return sta.size() == 0;
}

int main() {
  bool aa = checkBalance("if (x) {") ;

  cout << aa << endl;

  return 0;
}
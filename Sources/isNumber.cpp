#include <string>
using namespace std;

bool isNumber(string str) {
  if (str.length() == 0) return false;

  if (str.length() > 0 && str[0] == '-') {
    str = str.substr(1);
  }

  for (char c : str) {
    if (!isdigit(c)) return false;
  }

  return true;
}
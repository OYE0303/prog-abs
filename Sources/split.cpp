#include <string>
#include <vector>
using namespace std;

vector<string> split(string str, string delimiter) {
  vector<string> res;
  int startIdx = 0;

  if (delimiter.length() >= str.length()) return res;

  while (startIdx < str.length()) {
    int findIdx = str.find(delimiter, startIdx);

    if (findIdx == string::npos) {
      break;
    }

    string subStr = str.substr(startIdx, findIdx - startIdx);
    res.push_back(subStr);
    startIdx = findIdx + delimiter.length();
  }

  if (startIdx != str.length()) {
    res.push_back(str.substr(startIdx));
  }

  return res;
}

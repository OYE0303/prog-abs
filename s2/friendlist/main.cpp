#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../../Headers/readFile.h"
#include "../../Headers/split.h"

using namespace std;

map<string, vector<string>> friendList(string filename);

int main() {
  map<string, vector<string>> output = friendList("s2/friendlist/buddies.txt");

  cout << "{";
  for (auto it = output.begin(); it != output.end(); it++) {
    cout << "\"" << it->first << "\":{";
    for (int i = 0; i < it->second.size(); i++) {
      cout << "\"" << it->second[i] << "\"";
      if (i != it->second.size() - 1) {
        cout << ", ";
      }
    }
    cout << "}";
    if (it != --output.end()) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  return 0;
}

map<string, vector<string>> friendList(string filename) {
  map<string, vector<string>> output;
  vector<string> content = readFile(filename);

  for (string friends : content) {
    vector<string> friendList = split(friends, " ");
    string firstFrie = friendList[0];
    string secondFrie = friendList[1];

    output[firstFrie].push_back(secondFrie);
    output[secondFrie].push_back(firstFrie);
  }

  return output;
}
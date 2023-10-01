#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> readFile(string fileName) {
  vector<string> fileContent;
  ifstream file(fileName);
  string line;

  if (file.is_open()) {
    while (getline(file, line)) {
      fileContent.push_back(line);
    }
    file.close();
  }

  return fileContent;
}
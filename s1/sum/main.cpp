#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "./../../Headers/split.h"
#include "./../../Headers/isNumber.h"
using namespace std;


int main(){
  ifstream myFile;
  string line;
  vector<string> lines;
  int result = 0;

  myFile.open("s1/sum/numbers.txt");

  if(!myFile.is_open()) {
    cout << "File can't open successfully" << endl;
    return 1;
  }

  while(myFile){
    getline(myFile, line);
    lines.push_back(line);
  }

  for(string line : lines){
    vector<string> strs = split(line, " ");

    for(string str : strs){
      if(isNumber(str)) result += stoi(str);
    }
  }

  cout << result << endl;

  return 0;
}
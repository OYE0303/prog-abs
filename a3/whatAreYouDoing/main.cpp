#include <set>
#include <string>
#include <vector>

#include "../../Headers/executionTimeMeasurement.h"
#include "../../Headers/split.h"

using namespace std;

// allEmphasesOf returns a set of all possible emphases of a sentence.
set<string> allEmphasesOf(const string& sentence);

// allEmphasesOfHelper is a helper function for allEmphasesOf.
void allEmphasesOfHelper(vector<string>& sentences, int idx,
                         set<string>& output);

// merge merges a vector of strings into a single string with a delimiter.
string merge(vector<string>& sentence, string delimiter);

// upperCase converts a string to upper case.
void upperCase(string& sentence);

// lowerCase converts a string to lower case.
void lowerCase(string& sentence);

#include <cctype>
#include <iostream>

using namespace std;

int main() {
  set<string> emphases = allEmphasesOf(
      "Turing and turning in a widening gyre / the falcon cannot hear the "
      "falconer.");

  for (string str : emphases) {
    cout << str << "\n";
  }

  // check size
  cout << "size: " << emphases.size() << "\n";
}

set<string> allEmphasesOf(const string& sentence) {
  vector<string> sentences = split(sentence, " ");
  set<string> output;

  allEmphasesOfHelper(sentences, 0, output);

  return output;
}

void allEmphasesOfHelper(vector<string>& sentences, int idx,
                         set<string>& output) {
  if (idx == sentences.size()) {
    output.insert(merge(sentences, " "));
    return;
  }

  upperCase(sentences[idx]);
  allEmphasesOfHelper(sentences, idx + 1, output);

  lowerCase(sentences[idx]);
  allEmphasesOfHelper(sentences, idx + 1, output);
}

string merge(vector<string>& sentence, string delimiter) {
  string output = "";

  for (string str : sentence) {
    output += str;
    output += delimiter;
  }

  return output.substr(0, output.size() - 1);
}

void upperCase(string& sentence) {
  for (char& c : sentence) {
    c = toupper(c);
  }
}

void lowerCase(string& sentence) {
  for (char& c : sentence) {
    c = tolower(c);
  }
}
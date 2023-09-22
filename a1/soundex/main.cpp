#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../../Headers/printVector.h"
using namespace std;

// lettersOnly takes a string and returns a string with only the letters
string lettersOnly(string s);

// convertToUppercase transforms a string to uppercase
string convertToUppercase(string s);

// createCharToDigitMap creates a map from char to digit
map<char, int> createCharToDigitMap();

// mapStringToDigit maps a string to a digit
string mapStringToDigit(string s);

// removeAdjacentDuplicates removes adjacent duplicates
string removeAdjacentDuplicates(string s);

// removeAdjacentDuplicates removes adjacent duplicates, but use while loop
// instead of for loop
string removeAdjacentDuplicates1(string s);
string removeAdjacentDuplicates2(const string &s);

// formatCode formats the code, change the first character to uppercase
string formatCode(string s, char firstChar);
string formatCode1(string s, char firstChar);

// removeZeros removes zeros
string removeZeros(string s);

// removeString removes the last 4 characters
string removeString(string s);

// formatOutput formats the output
string formatOutput(string s);

// soundex implement the main logic of soundex
string soundex(string s);

// soundexSearch implement the main logic of soundexSearch
void soundexSearch();

int main() {
  soundexSearch();
  return 0;
}

string soundex(string s) {
  string upperString = convertToUppercase(lettersOnly(s));
  string digits = mapStringToDigit(upperString);
  string uniqueDigits = removeAdjacentDuplicates(digits);
  string formatedCode = formatCode(uniqueDigits, s[0]);
  string removedZeroCode = removeZeros(formatedCode);
  string output = formatOutput(removedZeroCode);

  return output;
}

void soundexSearch() {
  ifstream inputFile("a1/soundex/surnames.txt");

  if (!inputFile.is_open()) {
    cerr << "Failed to open the file: " << strerror(errno) << endl;
  }

  vector<string> lines;
  string line;

  // Read each line from the file
  while (getline(inputFile, line)) {
    lines.push_back(line);
  }

  cout << "Read file surnames.txt " << lines.size() << " names found.";

  map<string, vector<string>> stringBySoundex;
  int i = 0;

  while (i < lines.size()) {
    string soundexCode = soundex(lines[i]);

    if (stringBySoundex.count(soundexCode) == 0) {
      vector<string> names;
      names.push_back(lines[i]);
      stringBySoundex[soundexCode] = names;
    } else {
      stringBySoundex[soundexCode].push_back(lines[i]);
    }

    i++;
  }

  string input;
  cout << "Enter a surname: ";
  cin >> input;

  string soundexCode = soundex(input);
  vector<string> names = stringBySoundex[soundexCode];
  printVector(names);

  // print out the all result
  // for (auto it = stringBySoundex.begin(); it != stringBySoundex.end();
  // it++)
  // {
  //   for (string name : it->second) {
  //     cout << name << " ";
  //   }

  //   cout << endl;
  // }

  inputFile.close();
}

string lettersOnly(string s) {
  string result;

  for (char c : s) {
    if (isalpha(c)) {
      result += c;
    }
  }

  return result;
}

string convertToUppercase(string s) {
  string output = "";

  for (char c : s) {
    output += toupper(c);
  }

  return output;
}

map<char, int> createCharToDigitMap() {
  map<char, int> charToDigit = {
      {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 0}, {'F', 1}, {'G', 2},
      {'H', 0}, {'I', 0}, {'J', 2}, {'K', 2}, {'L', 4}, {'M', 5}, {'N', 5},
      {'O', 0}, {'P', 1}, {'Q', 2}, {'R', 6}, {'S', 2}, {'T', 3}, {'U', 0},
      {'V', 1}, {'W', 0}, {'X', 2}, {'Y', 0}, {'Z', 2}};
  return charToDigit;
}

string mapStringToDigit(string s) {
  string output = "";
  map<char, int> charToDigit = createCharToDigitMap();

  for (char c : s) {
    output += to_string(charToDigit[c]);
  }

  return output;
}

string removeAdjacentDuplicates(string s) {
  string output = "";
  int len = s.length();

  for (int i = 0; i < len; i++) {
    char cur = s[i];
    output += cur;

    for (int j = i + 1; j < len; j++) {
      if (cur != s[j]) break;
      i = j;
    }
  }

  return output;
}

string removeAdjacentDuplicates1(string s) {
  if (s.length() <= 1) return s;

  string output = "";
  int i = 0;
  int j = 1;

  while (j < s.length()) {
    if (s[i] != s[j]) {
      output += s[i];
    }

    i++;
    j++;
  }

  // handle edge case for the last character
  if (i < s.length()) {
    output += s[i];
  }

  return output;
}

string removeAdjacentDuplicates2(const string &s) {
  string output;
  for (char c : s) {
    if (output.empty() || output.back() != c) {
      output += c;
    }
  }
  return output;
}

string formatCode(string s, char firstChar) {
  string output = string(1, toupper(firstChar));

  for (int i = 1; i < s.length(); i++) {
    output += s[i];
  }

  return output;
}

string formatCode1(string s, char firstChar) {
  string output = string(1, toupper(firstChar)) + s.substr(1);

  return output;
}

string removeZeros(string s) {
  string output;

  for (char c : s) {
    if (c != '0') {
      output += c;
    }
  }

  return output;
}

string removeString(string s) {
  string output = "";

  for (int i = 0; i < 4; i++) {
    output += s[i];
  }

  return output;
}

string formatOutput(string s) {
  if (s.length() == 4) return s;

  if (s.length() > 4) {
    return removeString(s);
  }

  while (s.length() < 4) {
    s += "0";
  }

  return s;
}
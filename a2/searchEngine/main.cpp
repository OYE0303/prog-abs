#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "../../Headers/printVector.h"
#include "../../Headers/readFile.h"
#include "../../Headers/split.h"

using namespace std;

// main functionality
void searchEngine(string dbfile);

// builds the index from the database file
int buildIndex(string dbfile, map<string, set<string>>& index);

// finds the matches for a query
set<string> findQueryMatches(map<string, set<string>>& index, string query);

// gathers tokens from a string
set<string> gatherTokens(string bodytext);

// cleans a token
string cleanToken(string token);

// checks if a string is a non-word
bool isNonWord(string s);

// set operations
set<string> unionWith(set<string> a, set<string> b);
set<string> intersect(set<string> a, set<string> b);
set<string> difference(set<string> a, set<string> b);

int main() {
  searchEngine("a2/searchEngine/res/website.txt");
  return 0;
}

void searchEngine(string dbfile) {
  cout << "Stand by while building index..." << endl;

  map<string, set<string>> index;
  int nPages = buildIndex(dbfile, index);

  cout << "Indexed " << nPages << " pages containing " << index.size()
       << " unique terms" << endl;

  while (true) {
    cout << "Enter query sentence (RETURN/ENTER to quit): ";
    string query;
    getline(cin, query);

    if (query == "") {
      cout << "All done!" << endl;
      break;
    }

    set<string> matches = findQueryMatches(index, query);

    cout << "Found " << matches.size() << " matching pages " << endl;

    cout << "{";
    for (string match : matches) {
      cout << "\"" << match << "\", " << endl;
    }
    cout << "}" << endl;
  }
}

int buildIndex(string dbfile, map<string, set<string>>& index) {
  vector<string> content = readFile(dbfile);
  int contentSize = content.size();
  int i = 0;
  int output = 0;

  while (i < contentSize) {
    string url = content[i];
    set<string> words = gatherTokens(content[i + 1]);

    for (string word : words) {
      index[word].insert(url);
    }

    i += 2;
    output++;
  }

  return output;
}

set<string> findQueryMatches(map<string, set<string>>& index, string query) {
  set<string> output;
  vector<string> splittedQuery = split(query, " ");

  for (string q : splittedQuery) {
    char operand = q[0];
    string value = cleanToken(q);
    set<string> matches = index[value];

    if (operand == '+') {
      output = intersect(output, matches);
    } else if (operand == '-') {
      output = difference(output, matches);
    } else {
      output = unionWith(output, matches);
    }
  }

  return output;
}

set<string> gatherTokens(string bodytext) {
  vector<string> splittedString = split(bodytext, " ");
  set<string> output;

  for (string str : splittedString) {
    output.insert(cleanToken(str));
  }

  return output;
}

string cleanToken(string token) {
  int start = 0;
  int end = token.length() - 1;

  while (start < end) {
    bool isStartPunct = ispunct(token[start]);
    bool isEndPunct = ispunct(token[end]);

    if (!isStartPunct && !isEndPunct) break;

    if (isStartPunct) {
      start++;
    }

    if (isEndPunct) {
      end--;
    }
  }

  string trimmedString = token.substr(start, end - start + 1);

  if (isNonWord(trimmedString)) return "";

  for (char& c : trimmedString) {
    c = tolower(c);
  }

  return trimmedString;
}

bool isNonWord(string s) {
  for (char c : s) {
    if (isalpha(c)) return false;
  }

  return true;
}

set<string> unionWith(set<string> a, set<string> b) {
  set<string> output;

  for (string value : a) {
    output.insert(value);
  }

  for (string value : b) {
    output.insert(value);
  }

  return output;
}

set<string> intersect(set<string> a, set<string> b) {
  set<string> output;

  for (string value : a) {
    if (b.find(value) != b.end()) {
      output.insert(value);
    }
  }

  for (string value : b) {
    if (a.find(value) != a.end()) {
      output.insert(value);
    }
  }

  return output;
}

set<string> difference(set<string> a, set<string> b) {
  set<string> output;

  for (string value : a) {
    output.insert(value);
  }

  for (string value : b) {
    output.erase(value);
  }

  return output;
}
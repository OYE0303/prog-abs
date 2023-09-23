#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "./../Headers/printQueue.h"
#include "./../Headers/printStack.h"
#include "./../Headers/printVector.h"
#include "./../Headers/split.h"
using namespace std;

void wordLadderProgram();
void populateDictionary(set<string>& dictionary, string filename);
stack<string> findWordLadder(string startingWord, string destinationWord,
                             set<string>& dictionary);
set<string> generateNeighboringWords(string currentWord,
                                     set<string>& dictionary);

int main() {
  wordLadderProgram();

  cout << "All done!" << endl;
  return 0;
}

void wordLadderProgram() {
  cout << "Welcome to the Word Ladder Finder!" << endl;
  cout << "A powerful computer program that leverages many different" << endl;
  cout << "ADTs to solve a fun children's puzzle." << endl;
  cout << "Up, up, and away!" << endl << endl;

  set<string> dictionary;
  populateDictionary(dictionary, "l7/EnglishWords.txt");

  while (true) {
    string userInput;
    cout << "Please enter two words that you want to find a word ladder "
            "between, separated by a comma: ";
    cin >> userInput;
    if (userInput == "") break;

    cout << userInput << endl;

    vector<string> words = split(userInput, ",");
    stack<string> wordLadder = findWordLadder(words[0], words[1], dictionary);

    if (wordLadder.empty()) {
      cout << "Coudn't find a word ladder between those two words!" << endl;
      continue;
    }

    cout << "Here is the word ladder from " << words[1] << " to " << words[0]
         << endl;
    while (!wordLadder.empty()) {
      cout << wordLadder.top() << endl;
      wordLadder.pop();
    }
    cout << endl;
  }
}

void populateDictionary(set<string>& dictionary, string filename) {
  ifstream inputFile(filename);

  if (!inputFile.is_open()) {
    cerr << "Failed to open the file: " << strerror(errno) << endl;
  }

  vector<string> lines;
  string line;

  while (getline(inputFile, line)) {
    lines.push_back(line);
  }

  for (string word : lines) {
    dictionary.insert(word);
  }

  cout << "Found " << dictionary.size() << " words in the dictionary file."
       << endl;
}

set<string> generateNeighboringWords(string currentWord,
                                     set<string>& dictionary) {
  set<string> neighboringWords;

  for (int i = 0; i < currentWord.length(); i++) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      string newWord = currentWord;
      newWord[i] = ch;
      if (dictionary.find(newWord) != dictionary.end()) {
        neighboringWords.insert(newWord);
      }
    }
  }
  return neighboringWords;
}

stack<string> findWordLadder(string startingWord, string destinationWord,
                             set<string>& dictionary) {
  stack<string> s;
  queue<stack<string>> q;
  set<string> visitedWords;

  s.push(startingWord);
  q.push(s);
  visitedWords.insert(startingWord);

  while (!q.empty()) {
    stack<string> curStack = q.front();
    q.pop();

    string curStr = curStack.top();

    if (curStr == destinationWord) {
      return curStack;
    }

    set<string> neighboringWords = generateNeighboringWords(curStr, dictionary);

    for (auto itr = neighboringWords.begin(); itr != neighboringWords.end();
         itr++) {
      if (visitedWords.find(*itr) != visitedWords.end()) continue;

      stack<string> newStack = curStack;
      newStack.push(*itr);
      q.push(newStack);
      visitedWords.insert(*itr);
    }
  }

  return {};
}

/*
sudo code
  1. initialize stack and queue containing the stack
  (queue represents all possible paths)
  (stack represents the each search path)
  2. initialize set of visited words
  3. while queue is not empty
    4. pop the front stack from the queue
    5. get the top word from the stack(without popping)
    6. if the top word is the destination word
      7. return the stack
    8. get all neighboring words of the top word(with helper function)
    9. for each neighboring word
      10. if the neighboring word has not been visited
        11. copy the stack
        12. push the neighboring word onto the stack
        13. push the new stack onto the queue
        14. mark the neighboring word as visited
*/

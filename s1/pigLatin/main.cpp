#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

int findFirstVowel(string& str) {
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    vector<const char>::iterator finder = find(vowel.begin(), vowel.end(), ch);

    if (finder != vowel.end()) return i;
  }

  return -1;
}

string pigLatinReturn(string str) {
  int firstVowelIdx = findFirstVowel(str);

  string firstPart = str.substr(0, firstVowelIdx);
  string lastPart = str.substr(firstVowelIdx + 1);

  return str[firstVowelIdx] + lastPart + firstPart + "ay";
}

void pigLatinReference(string& str) {
  int firstVowelIdx = findFirstVowel(str);

  string firstPart = str.substr(0, firstVowelIdx);
  string lastPart = str.substr(firstVowelIdx + 1);

  str = str[firstVowelIdx] + lastPart + firstPart + "ay";
}

int main() {
  string s = "julie";
  string aa = pigLatinReturn(s);

  cout << aa << endl;
  return 0;
}
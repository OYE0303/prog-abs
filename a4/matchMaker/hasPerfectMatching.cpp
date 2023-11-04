#include <map>
#include <set>
#include <string>
#include <vector>

#include "pair.cpp"

using namespace std;

// hasPerfectMatching checkes if there is a perfect matching
bool hasPerfectMatching(const map<string, set<string>>& possibleLinks,
                        set<Pair>& matching);

// hasPerfectMatchingHelper is the helper function for hasPerfectMatching
bool hasPerfectMatchingHelper(map<string, set<string>>& possibleLinks,
                              set<Pair>& matching);

// fromLinks is a helper function to convert vector<Pair> to map<string,
// set<string>> for the purpose of testing
map<string, set<string>> fromLinks(const vector<Pair>& pairs);

// isPerfectMatching checks if the matching is a perfect matching for the
// purpose of testing
bool isPerfectMatching(const map<string, set<string>>& possibleLinks,
                       const set<Pair>& matching);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool hasPerfectMatching(const map<string, set<string>>& possibleLinks,
                        set<Pair>& matching) {
  map<string, set<string>> copyLinks = possibleLinks;

  return hasPerfectMatchingHelper(copyLinks, matching);
}

/*
"A": { "B" },
"B": { "A", "C", "E", "G" },
"C": { "B", "D", "G" },
"D": { "C", "G", "H" },
"E": { "B", "F" },
"F": { "E", "G" },
"G": { "B", "C", "D", "F", "H" },
"H": { "D", "G" }

The idea is straightforward:
1. Pick a node, say "A", and pick a link, say "B".
2. Remove "A" and "B" from the graph.
3. Repeat 1 and 2 until there is no node left.
4. If there is no node left, then return true.
5. If there's no matching from picking "A" and "B", then backtrack.
(Add "A" and "B" back to the graph.)


Note that here we MODIFY the graph(possibleLinks) in place.
If we want to keep the graph intact, we can create a vector to record the
possibleLinks and restore it after the recursion.
Look above for an example.
*/
bool hasPerfectMatchingHelper(map<string, set<string>>& possibleLinks,
                              set<Pair>& matching) {
  if (possibleLinks.size() == 0) {
    return true;
  }

  // Simply pick the first node and the first link
  string curNode = possibleLinks.begin()->first;
  auto curLinks = possibleLinks[curNode];

  for (string link : curLinks) {
    // If the link is not in the possibleLinks, then there's no point to
    // explore.
    if (possibleLinks.find(link) == possibleLinks.end()) {
      continue;
    }

    // tmplinks is used to restore the possibleLinks after the recursion
    auto tmpLinks = possibleLinks[link];

    Pair pair(curNode, link);

    // Choose the pair
    matching.insert(pair);

    // Remove the pair from the possibleLinks
    possibleLinks.erase(curNode);
    possibleLinks.erase(link);

    // Explore
    if (hasPerfectMatchingHelper(possibleLinks, matching)) {
      return true;
    }

    // Unchoose the pair
    matching.erase(pair);

    // Restore the possibleLinks
    possibleLinks[curNode] = curLinks;
    possibleLinks[link] = tmpLinks;
  }

  return false;
}

map<string, set<string>> fromLinks(const vector<Pair>& pairs) {
  map<string, set<string>> result;

  for (const auto& link : pairs) {
    result[link.first()].insert(link.second());
    result[link.second()].insert(link.first());
  }

  return result;
}

bool isPerfectMatching(const map<string, set<string>>& possibleLinks,
                       const set<Pair>& matching) {
  auto copyLinks = possibleLinks;
  /* Need to check that
   *
   * 1. each pair is indeed a possible link,
   * 2. each person appears in exactly one pair.
   */

  // 1. each pair is indeed a possible link,
  for (const auto& pair : matching) {
    if (copyLinks.find(pair.first()) == copyLinks.end()) {
      return false;
    }

    if (copyLinks.find(pair.second()) == copyLinks.end()) {
      return false;
    }

    if (copyLinks[pair.first()].find(pair.second()) ==
        copyLinks[pair.first()].end()) {
      return false;
    }

    if (copyLinks[pair.second()].find(pair.first()) ==
        copyLinks[pair.second()].end()) {
      return false;
    }
  }

  // 2. each person appears in exactly one pair.
  set<string> used;
  for (const auto& pair : matching) {
    if (used.find(pair.first()) != used.end()) {
      return false;
    }

    if (used.find(pair.second()) != used.end()) {
      return false;
    }

    used.insert(pair.first());
    used.insert(pair.second());
  }

  return used.size() == copyLinks.size();
}

/*
possibleLinks is never modified in the recursion.
Instead, we use nodes to keep track of the nodes that are not matched yet.

bool hasPerfectMatchingHelper(map<string, set<string>>& possibleLinks,
                              set<string>& nodes, set<Pair>& matching) {
  if (nodes.size() == 0) {
    return true;
  }

  string curNode = *nodes.begin();
  auto curLinks = possibleLinks[curNode];

  for (string link : curLinks) {
    if (nodes.find(link) == nodes.end()) {
      continue;
    }

    Pair pair(curNode, link);
    matching.insert(pair);

    nodes.erase(curNode);
    nodes.erase(link);

    if (hasPerfectMatchingHelper(possibleLinks, nodes, hashTable, matching))
    {
      return true;
    }

    matching.erase(pair);

    nodes.insert(curNode);
    nodes.insert(link);
  }

  return false;
}
*/
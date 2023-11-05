#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "pair.cpp"

using namespace std;

// maximumWeightMatching returns a maximum weight matching
set<Pair> maximumWeightMatching(
    const map<string, map<string, int>>& possibleLinks);

// maximumWeightMatchingHelper is a helper function for maximumWeightMatching
void maximumWeightMatchingHelper(map<string, map<string, int>>& possibleLinks,
                                 set<string> nodes, set<Pair>& pairs,
                                 set<Pair>& curPairs, int& maxWeight,
                                 int curWeight);

// genSet generates a set of nodes from a map of possibleLinks
set<string> genSet(const map<string, map<string, int>>& links);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

set<Pair> maximumWeightMatching(
    const map<string, map<string, int>>& possibleLinks) {
  map<string, map<string, int>> copyLinks = possibleLinks;
  set<string> nodes = genSet(possibleLinks);
  set<Pair> pairs;
  set<Pair> curPairs;
  int maxWeight = -1;

  maximumWeightMatchingHelper(copyLinks, nodes, pairs, curPairs, maxWeight, 0);

  return pairs;
}

/*
The idea is pretty similar to hasPerfectMatchingHelper.
The only difference is that we need to keep track of the maximum weight.

"A": { "B": 1 },
"B": { "A": 1, "C": 2, "E": 3, "G": 4 },
"C": { "B": 2, "D": 5, "G": 6 },
"D": { "C": 5, "G": 7, "H": 8 },
"E": { "B": 3, "F": 9 },
"F": { "E": 9, "G": 10 },

Here, we do NOT modify the graph in place.
Instead, we use nodes to keep track of the nodes that are not chosen yet.
*/
void maximumWeightMatchingHelper(map<string, map<string, int>>& possibleLinks,
                                 set<string> nodes, set<Pair>& pairs,
                                 set<Pair>& curPairs, int& maxWeight,
                                 int curWeight) {
  if (curWeight > maxWeight) {
    set<Pair> newPairs = curPairs;
    pairs = newPairs;
    maxWeight = curWeight;
  }

  if (nodes.size() == 0) {
    return;
  }

  // copy the nodes to iterate over
  // because we'll modify nodes during the iteration
  auto copyNodes = nodes;

  for (string node : copyNodes) {
    map<string, int> links = possibleLinks[node];

    for (auto link : links) {
      string key = link.first;

      // if the link is not in the graph(nodes), then skip
      if (copyNodes.find(key) == copyNodes.end()) {
        continue;
      }

      // Choose
      Pair pair(node, key);
      curPairs.insert(pair);
      nodes.erase(node);
      nodes.erase(key);

      maximumWeightMatchingHelper(possibleLinks, nodes, pairs, curPairs,
                                  maxWeight, curWeight + link.second);

      // Unchoose
      curPairs.erase(pair);
      nodes.insert(node);
      nodes.insert(key);
    }
  }
}

struct WeightedLink {
  string from;
  string to;
  int cost;
};

map<string, map<string, int>> fromWeightedLinks(
    const vector<WeightedLink>& links) {
  map<string, map<string, int>> result;
  for (const auto& link : links) {
    result[link.from][link.to] = link.cost;
    result[link.to][link.from] = link.cost;
  }
  return result;
}

set<string> genSet(const map<string, map<string, int>>& links) {
  set<string> result;
  for (const auto& link : links) {
    result.insert(link.first);
  }
  return result;
}
#pragma once

#include <string>

class Pair {
 public:
  /* Creates a pair of two empty strings. */
  Pair() = default;

  /* Sort the strings. */
  Pair(const std::string& one, const std::string& two) {
    if (one < two) {
      one_ = one;
      two_ = two;
    } else {
      one_ = two;
      two_ = one;
    }
  }

  const std::string& first() const { return one_; }
  const std::string& second() const { return two_; }

  bool operator<(const Pair& rhs) const {
    /* Compare first components. */
    auto comp = first().compare(rhs.first());
    if (comp != 0) return comp < 0;

    return second() < rhs.second();
  }

  bool operator==(const Pair& rhs) const {
    return first() == rhs.first() && second() == rhs.second();
  }

  bool operator>(const Pair& rhs) const { return rhs < *this; }
  bool operator>=(const Pair& rhs) const { return !(*this < rhs); }
  bool operator<=(const Pair& rhs) const { return !(*this > rhs); }
  bool operator!=(const Pair& rhs) const { return !(*this == rhs); }

 private:
  std::string one_;
  std::string two_;
};
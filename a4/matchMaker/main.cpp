#include <cassert>
#include <iostream>

#include "hasPerfectMatching.cpp"
#include "maximumWeightMatching.cpp"

void test_hasPerfectMatching() {
  // Test 1: hasPerfectMatching works on a world with just one person.
  set<Pair> unused;
  assert(hasPerfectMatching({{"A", {}}}, unused) == false);

  // Test 2: hasPerfectMatching works on an empty set of people.
  unused.clear();
  assert(hasPerfectMatching({}, unused) == true);

  // Test 3: hasPerfectMatching works on a world with two linked people.
  /* This world is a pair of people A and B. There should be a perfect
  matching.
   *
   *               A -- B
   *
   * The matching is {A, B}
   */
  unused.clear();
  auto links = fromLinks({{"A", "B"}});
  assert(hasPerfectMatching(links, unused) == true);

  // Test 4: "hasPerfectMatching works on a world with two linked people, and
  // produces output.
  /* This world is a pair of people A and B. There should be a perfect
  matching.
   *
   *               A -- B
   *
   * The matching is {A, B}
   */
  unused.clear();
  links = fromLinks({{"A", "B"}});
  set<Pair> expected = {{"A", "B"}};
  assert(hasPerfectMatching(links, unused) == true);
  assert(unused == expected);

  // Test 5: hasPerfectMatching works on a triangle of people.
  /* Here's the world:
   *
   *               A --- B
   *                \   /
   *                 \ /
   *                  C
   *
   * There is no perfect matching here, unfortunately.
   */
  unused.clear();
  links = fromLinks({{"A", "B"}, {"B", "C"}, {"C", "A"}});
  assert(hasPerfectMatching(links, unused) == false);

  // Test 6: hasPerfectMatching works on a square of people.
  /* Here's the world:
   *
   *               A --- B
   *               |     |
   *               |     |
   *               D --- C
   *
   * There are two different perfect matching here: AB / CD, and AD/BD.
   * Either will work.
   */
  unused.clear();
  links = fromLinks({{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "A"}});
  assert(hasPerfectMatching(links, unused) == true);

  // Test 7: hasPerfectMatching works on a square of people, and
  //   produces output.
  /* Here's the world:
   *
   *               A --- B
   *               |     |
   *               |     |
   *               C --- D
   *
   * There are two different perfect matching here: AB / CD, and AC/BC.
   * Either will work.
   */
  unused.clear();
  links = fromLinks({{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "A"}});
  assert(hasPerfectMatching(links, unused) == true);
  assert(isPerfectMatching(links, unused) == true);

  // Test 8: hasPerfectMatching works on a pentagon of people.
  /* Here's the world:
   *
   *               A --- B
   *             /       |
   *            E        |
   *             \       |
   *               D --- C
   *
   * There is no perfect matching here, since the cycle has odd
   * length.
   */
  unused.clear();
  links =
      fromLinks({{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "E"}, {"E", "A"}});
  assert(hasPerfectMatching(links, unused) == false);

  // Test 9: hasPerfectMatching works on a line of six people.
  /* Because Map and Set internally store items in sorted order, the order
   * in which you iterate over people when making decisions is sensitive
   * to the order of those peoples' names. This test looks at a group like
   * this one, trying out all possible orderings of peoples' names:
   *
   *
   *
   *        * -- * -- * -- * -- * -- *
   *
   *
   *
   * There are 6! = 720 possible permutations of the ordering of these six
   * people. If your code is able to solve the problem correctly for all of
   * those orderings, there's a good chance that you're correctly tracking
   * who is matched at each step. On the other hand, if your code runs into
   * issues here, it may indicate that there's a bug in how you mark who's
   * paired and who isn't.
   */
  vector<string> people = {"A", "B", "C", "D", "E", "F"};
  do {
    auto links = fromLinks({{people[0], people[1]},
                            {people[1], people[2]},
                            {people[2], people[3]},
                            {people[3], people[4]},
                            {people[4], people[5]}});
    unused.clear();

    assert(hasPerfectMatching(links, unused) == true);
    assert(isPerfectMatching(links, unused) == true);
  } while (next_permutation(people.begin(), people.end()));

  // Test 10: hasPerfectMatching works on a more complex negative example.
  /* Because Map and Set internally store items in sorted order, the order
   * in which you iterate over people when making decisions is sensitive
   * to the order of those peoples' names. This test looks at a group like
   * this one, trying out all possible orderings of peoples' names:
   *
   *
   *
   *        *        *
   *         \      /
   *          * -- *
   *         /      \
   *        *        *
   *
   * There are 6! = 720 possible permutations of the ordering of these six
   * people. If your code is able to solve the problem correctly for all of
   * those orderings, there's a good chance that you're correctly tracking
   * who is matched at each step. On the other hand, if your code runs into
   * issues here, it may indicate that there's a bug in how you mark who's
   * paired and who isn't.
   */
  people = {"A", "B", "C", "D", "E", "F"};
  do {
    auto links = fromLinks({
        {people[0], people[2]},
        {people[1], people[2]},
        {people[2], people[3]},
        {people[3], people[4]},
        {people[3], people[5]},
    });
    unused.clear();

    assert(hasPerfectMatching(links, unused) == false);
  } while (next_permutation(people.begin(), people.end()));

  // Test 11: hasPerfectMatching works on a caterpillar.
  /* Because Map and Set internally store items in sorted order, the order
   * in which you iterate over people when making decisions is sensitive
   * to the order of those peoples' names. This test looks at a group like
   * this one, trying out all possible orderings of peoples' names:
   *
   *         *---*---*
   *         |   |   |
   *         *   *   *
   *
   * There are 6! = 720 possible permutations of the ordering of these six
   * people. If your code is able to solve the problem correctly for all of
   * those orderings, there's a good chance that you're correctly tracking
   * who is matched at each step. On the other hand, if your code runs into
   * issues here, it may indicate that there's a bug in how you mark who's
   * paired and who isn't.
   */
  people = {"A", "B", "C", "D", "E", "F"};
  do {
    auto links = fromLinks({{people[0], people[1]},
                            {people[1], people[2]},
                            {people[0], people[3]},
                            {people[1], people[4]},
                            {people[2], people[5]}});
    unused.clear();

    assert(hasPerfectMatching(links, unused) == true);
    assert(isPerfectMatching(links, unused) == true);
  } while (next_permutation(people.begin(), people.end()));

  // Test 12: hasPerfectMatching stress test: negative example (should) take
  // under a second).
  /* Here, we're giving a "caterpillar" of people, like this:
   *
   *    *   *   *   *     *   *
   *    |   |   |   |     |   |
   *    *---*---*---* ... *---*
   *    |   |   |   |     |   |
   *    *   *   *   *     *   *
   *
   * This doesn't have a perfect matching, However, it may take some
   searching
   * to confirm this is the case. At this size, however, it should be
   * almost instanteous to find the solution, since the search space is
   fairly
   * small and most "wrong" decisions can be detected quickly.
   *
   * On the other hand, if your implementation repeatedly constructs the same
   * matchings over and over again, or keeps exploring even when a person who
   * couldn't be paired with the current setup is found, then the number of
   * options you need to consider will be too large for your computer to
   handle
   * in any reasonable time.
   *
   * If you're passing the other tests and this test hangs, double-check your
   * code to make sure you aren't repeatedly constructing the same matchings
   * multiple times.
   */
  int kRowSize = 10;
  vector<Pair> rawLinks;
  for (int i = 0; i < kRowSize - 1; i++) {
    rawLinks.push_back({to_string(i), to_string(i + 1)});
  }
  for (int i = 0; i < kRowSize; i++) {
    rawLinks.push_back({to_string(i), to_string(i + kRowSize)});
  }
  for (int i = 0; i < kRowSize; i++) {
    rawLinks.push_back({to_string(i), to_string(i + 2 * kRowSize)});
  }

  set<Pair> matching;
  assert(hasPerfectMatching(fromLinks(rawLinks), matching) == false);

  // Test 13: hasPerfectMatching stress test: positive example (should) take
  // under a second).
  /* Here, we're giving a "millipede" of people, like this:
   *
   *    *---*---*---* ... *---*
   *    |   |   |   |     |   |
   *    *   *   *   *     *   *
   *
   * This always has a perfect matching, which is found by pairing each
   person
   * with the person directly below them. However, it may take some searching
   * to find this particular configuration. At this size, however, it should
   be
   * almost instanteous to find the solution, since the search space is
   fairly
   * small and most "wrong" decisions can be detected quickly.
   *
   * On the other hand, if your implementation repeatedly constructs the same
   * matchings over and over again, or keeps exploring even when a person who
   * couldn't be paired with the current setup is found, then the number of
   * options you need to consider will be too large for your computer to
   handle
   * in any reasonable time.
   *
   * If you're passing the other tests and this test hangs, double-check your
   * code to make sure you aren't repeatedly constructing the same matchings
   * multiple times.
   */
  kRowSize = 10;
  rawLinks.clear();
  for (int i = 0; i < kRowSize - 1; i++) {
    rawLinks.push_back({to_string(i), to_string(i + 1)});
  }
  for (int i = 0; i < kRowSize; i++) {
    rawLinks.push_back({to_string(i), to_string(i + kRowSize)});
  }

  matching.clear();
  assert(hasPerfectMatching(fromLinks(rawLinks), matching) == true);
  assert(isPerfectMatching(fromLinks(rawLinks), matching) == true);
}

void test_maximumWeightMatching() {
  // Test 1: maximumWeightMatching works for empty group.
  assert(maximumWeightMatching({}) == set<Pair>());

  // Test 2: maximumWeightMatching works for group of one person.
  map<string, map<string, int>> links = {{"A", {}}};
  assert(maximumWeightMatching(links) == set<Pair>());

  // Test 3: maximumWeightMatching works for a single pair of people.
  links = fromWeightedLinks({{"A", "B", 1}});
  assert(maximumWeightMatching(links) == set<Pair>({{"A", "B"}}));

  // Test 4: maximumWeightMatching: Won't pick a negative edge.
  /* This world:
   *
   *  A --- B
   *     -1
   *
   * Best option is to not match anyone!
   */
  links = fromWeightedLinks({{"A", "B", -1}});
  assert(maximumWeightMatching(links) == set<Pair>());

  // Test 5: maximumWeightMatching: Works on a line of three people.
  /* This world:
   *
   *  A --- B --- C
   *     1     2
   *
   * Best option is to pick B -- C.
   */
  links = fromWeightedLinks({{"A", "B", 1}, {"B", "C", 2}});
  assert(maximumWeightMatching(links) == set<Pair>({{"B", "C"}}));

  // Test 6: maximumWeightMatching: Works on a triangle.
  /* This world:
   *
   *         A
   *      1 / \ 2
   *       B---C
   *         3
   *
   * Best option is to pick B -- C.
   */
  links = fromWeightedLinks({{"A", "B", 1}, {"B", "C", 3}, {"A", "C", 2}});
  assert(maximumWeightMatching(links) == set<Pair>({{"B", "C"}}));

  // Test 7: maximumWeightMatching: Works on a square.
  /* This world:
   *
   *         1
   *      A --- B
   *      |     |
   *    8 |     | 2
   *      |     |
   *      D --- C
   *         4
   *
   * Best option is to pick BC/AD.
   */
  links = fromWeightedLinks(
      {{"A", "B", 1}, {"B", "C", 2}, {"C", "D", 4}, {"D", "A", 8}});
  assert(maximumWeightMatching(links) == set<Pair>({{"A", "D"}, {"B", "C"}}));

  // Test 8: maximumWeightMatching: Works on a line of four people.
  /* This world:
   *
   *  A --- B --- C --- D
   *     1     3     1
   *
   * Best option is to pick B -- C, even though this is not a perfect
   * matching.
   */
  links = fromWeightedLinks({{"A", "B", 1}, {"B", "C", 3}, {"C", "D", 1}});
  assert(maximumWeightMatching(links) == set<Pair>({{"B", "C"}}));

  // Test 9:  maximumWeightMatching: Small stress test (should take at most a
  // second or two).
  /* Because Map and Set internally store items in sorted order, the order
   * in which you iterate over people when making decisions is sensitive
   * to the order of those peoples' names. This test looks at a group like
   * this one, trying out all possible orderings of peoples' names:
   *
   *               *
   *               | 1
   *               *
   *            1 / \ 5
   *             *---*
   *          1 /  1  \ 1
   *           *       *
   *
   * (Best option is to pick the 5-cost edge and the opposite-side 1-cost
   * edge.)
   *
   * There are 6! = 720 possible permutations of the ordering of these
   * people. If your code is able to solve the problem correctly for all of
   * those orderings, there's a good chance that you're correctly tracking
   * who is matched at each step. On the other hand, if your code runs into
   * issues here, it may indicate that there's a bug in how you mark who's
   * paired and who isn't.
   */
  vector<string> people = {"A", "B", "C", "D", "E", "F"};
  do {
    auto links = fromWeightedLinks({
        {people[0], people[1], 5},
        {people[1], people[2], 1},
        {people[2], people[0], 1},
        {people[3], people[0], 1},
        {people[4], people[1], 1},
        {people[5], people[2], 1},
    });

    set<Pair> expected = {{people[2], people[5]}, {people[0], people[1]}};

    assert(maximumWeightMatching(links) == expected);
  } while (next_permutation(people.begin(), people.end()));
}

int main() {
  test_hasPerfectMatching();
  test_maximumWeightMatching();

  return 0;
}

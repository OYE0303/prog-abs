#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Day represents the day of the week.
enum class Day {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};

// Shift represents a work shift.
struct Shift {
  Day day;
  int startHour;
  int endHour;
  int value;
};

// highestValueScheduleFor returns a schedule of shifts that maximizes the
// total value of the shifts
vector<Shift> highestValueScheduleFor(vector<Shift>& shifts, int maxHours);

// highestValueScheduleForHelper is a helper function for
// highestValueScheduleFor.
vector<Shift> highestValueScheduleForHelper(vector<Shift>& remaining,
                                            const int& maxHours,
                                            vector<Shift>& curShift,
                                            int curHours);

// lengthOf returns the length(hours) of a shift.
int lengthOf(const Shift& shift);

// valueOf returns the value of a shift.
int valueOf(const Shift& shift);

// overlapsWith returns true if two shifts overlap.
bool overlapsWith(const Shift& one, const Shift& two);

// checkIsOverlap returns true if the target shift overlaps with any shift in
bool checkIsOverlap(vector<Shift>& shifts, Shift targetShift);

// sumValueOf returns the sum of values of a vector of shifts.
int sumValueOf(const vector<Shift>& shifts);

int main() {
  vector<Shift> shifts = {
      {Day::SUNDAY, 8, 14, 12},     {Day::SUNDAY, 12, 18, 36},
      {Day::MONDAY, 8, 12, 44},     {Day::MONDAY, 12, 16, 32},
      {Day::MONDAY, 16, 20, 0},     {Day::MONDAY, 8, 16, 16},
      {Day::MONDAY, 12, 20, 22},    {Day::TUESDAY, 8, 12, 48},
      {Day::TUESDAY, 12, 16, 20},   {Day::TUESDAY, 16, 20, 24},
      {Day::TUESDAY, 8, 16, 24},    {Day::TUESDAY, 12, 20, 80},
      {Day::WEDNESDAY, 8, 12, 20},  {Day::WEDNESDAY, 12, 16, 8},
      {Day::WEDNESDAY, 16, 20, 8},  {Day::WEDNESDAY, 8, 16, 40},
      {Day::WEDNESDAY, 12, 20, 16}, {Day::THURSDAY, 8, 12, 40},
      {Day::THURSDAY, 12, 16, 0},   {Day::THURSDAY, 16, 20, 24},
      {Day::THURSDAY, 8, 16, 56},   {Day::THURSDAY, 12, 20, 32},
      {Day::FRIDAY, 8, 12, 4},      {Day::FRIDAY, 12, 16, 8},
      {Day::FRIDAY, 16, 20, 40},    {Day::FRIDAY, 8, 16, 72},
      {Day::FRIDAY, 12, 20, 40},    {Day::SATURDAY, 8, 14, 18},
      {Day::SATURDAY, 12, 18, 66},
  };

  vector<Shift> output = highestValueScheduleFor(shifts, 30);

  for (Shift s : output) {
    cout << "Day: " << static_cast<int>(s.day) << " Start: " << s.startHour
         << " End: " << s.endHour << " Value: " << s.value << "\n";
  }
  cout << "size: " << output.size() << "\n";
}

vector<Shift> highestValueScheduleFor(vector<Shift>& shifts, int maxHours) {
  vector<Shift> output;

  return highestValueScheduleForHelper(shifts, maxHours, output, 0);
}

/*
The basic idea is
For each recursive call, we only care about one thing
"Which one is higher, the value of including or excluding the current(last)
element?"

If there's N element in the input vector,
then there will be N height recursive tree
Each recursive call will have two branches, one for including the current
element, one for excluding the current element
*/
vector<Shift> highestValueScheduleForHelper(vector<Shift>& remaining,
                                            const int& maxHours,
                                            vector<Shift>& curShift,
                                            int curHours) {
  // base case
  if (remaining.size() == 0) {
    return curShift;
  }

  // recursive case
  // simply get the last element of the remaining shifts
  // It's more efficient to get the last element than the first element
  Shift firstElem = remaining[remaining.size() - 1];
  remaining.pop_back();

  // choose not to include the first element
  vector<Shift> exclude =
      highestValueScheduleForHelper(remaining, maxHours, curShift, curHours);

  // before even considering including the first element, check if it overlaps
  // with any shift in the current shift, as well as if it exceeds the maxHours
  // This is curcial to avoid unnecessary recursive calls
  // As long as adding firstElem to curShift is INVALID, we don't even need to
  // consider it
  bool isOverlap = checkIsOverlap(curShift, firstElem);
  bool isExceedMaxHours = curHours + lengthOf(firstElem) > maxHours;

  // if it is invalid, we simply put it back to the remaining shifts and return
  // the exclude vector, which is the highest value schedule without the first
  // We can simply concludes that `exclude` is the highest value schedule
  // because `include` is invalid, which is euqal to empty vector
  if (isOverlap || isExceedMaxHours) {
    remaining.push_back(firstElem);
    return exclude;
  }

  // if it is valid, we can consider including it
  curShift.push_back(firstElem);
  vector<Shift> include = highestValueScheduleForHelper(
      remaining, maxHours, curShift, curHours + lengthOf(firstElem));

  // undo step
  // we need to undo the step of including the first element
  curShift.pop_back();

  // we also need to put the first element back to the remaining shifts
  remaining.push_back(firstElem);

  // now we can compare the value of `exclude` and `include`
  int excludeVal = sumValueOf(exclude);
  int includeVal = sumValueOf(include);

  return excludeVal > includeVal ? exclude : include;
}

int lengthOf(const Shift& shift) { return shift.endHour - shift.startHour; }
int valueOf(const Shift& shift) { return shift.value; }

bool overlapsWith(const Shift& one, const Shift& two) {
  return one.day == two.day &&
         ((one.startHour <= two.startHour && two.startHour < one.endHour) ||
          (two.startHour <= one.startHour && one.startHour < two.endHour));
}

bool checkIsOverlap(vector<Shift>& shifts, Shift targetShift) {
  for (Shift s : shifts) {
    if (overlapsWith(s, targetShift)) {
      return true;
    }
  }
  return false;
}

int sumValueOf(const vector<Shift>& shifts) {
  int result = 0;
  for (Shift s : shifts) {
    result += s.value;
  }
  return result;
}

/*
This is the deprecated version of highestValueScheduleForHelper
The main reason is that it's not efficient enough
Look the for-loop inside recursive case

In this version,
For each recursive call, we will iterate through all the remaining shifts
Which means that
If there's N element in the input vector,
then the height of the recursive tree will be N
and the branching factor will also be N
so there will be N^N height recursive tree
*/
// void highestValueScheduleForHelper(vector<Shift>& shifts, vector<Shift>&
// output,
//                                    vector<Shift>& curShift, int curHours,
//                                    int curVal, int maxHours, int& maxVal) {
//   if (curHours > maxHours) {
//     return;
//   }

//   if (shifts.size() == 0 || curHours == maxHours) {
//     if (curVal > maxVal) {
//       output = curShift;
//       maxVal = curVal;
//     }
//     return;
//   }

//   int size = shifts.size();

//   for (int i = 0; i < size; i++) {
//     Shift s = shifts[i];

//     if (checkIsOverlap(curShift, s)) {
//       continue;
//     }

//     shifts.erase(shifts.begin() + i);

//     curShift.push_back(s);
//     highestValueScheduleForHelper(shifts, output, curShift,
//                                   curHours + lengthOf(s), curVal +
//                                   valueOf(s), maxHours, maxVal);
//     curShift.pop_back();
//     highestValueScheduleForHelper(shifts, output, curShift, curHours, curVal,
//                                   maxHours, maxVal);

//     shifts.insert(shifts.begin() + i, s);
//   }
// }
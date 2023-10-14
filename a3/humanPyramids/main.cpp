#include <map>

#include "../../Headers/executionTimeMeasurement.h"

using namespace std;

double weightOnBackOf(int row, int col);
double weightOnBackOfHelper(int row, int col);

double weightOnBackOfMemo(int row, int col);
double weightOnBackOfMemoHelper(int row, int col,
                                map<string, double>& hashTable);

int main() {
  measureExecutionTime(weightOnBackOf, 30, 16);
  measureExecutionTime(weightOnBackOfMemo, 30, 16);

  cout << "original: " << weightOnBackOf(4, 3) << "\n";
  cout << "memo: " << weightOnBackOfMemo(4, 3) << "\n";

  return 0;
}

double weightOnBackOf(int row, int col) {
  return weightOnBackOfHelper(row, col) - 160;
}

double weightOnBackOfHelper(int row, int col) {
  if (row < 0 || col < 0) {
    return 0;
  }

  if (row < col) {
    return 0;
  }

  // base case
  // The requirement indicates that the weight of the top person is 160 pounds.
  if (row == 0 && col == 0) {
    return 160.0;
  }

  double rightWei = weightOnBackOfHelper(row - 1, col);
  double leftWei = weightOnBackOfHelper(row - 1, col - 1);

  return (rightWei + leftWei) / 2 + 160;
}

double weightOnBackOfMemo(int row, int col) {
  map<string, double> hashTable;

  return weightOnBackOfMemoHelper(row, col, hashTable) - 160;
}
double weightOnBackOfMemoHelper(int row, int col,
                                map<string, double>& hashTable) {
  if (row < 0 || col < 0) {
    return 0;
  }

  if (row < col) {
    return 0;
  }

  if (row == 0 && col == 0) {
    return 160.0;
  }

  string key = to_string(row) + "," + to_string(col);

  if (hashTable.find(key) != hashTable.end()) {
    return hashTable[key];
  }

  double rightWei = weightOnBackOfMemoHelper(row - 1, col, hashTable);
  double leftWei = weightOnBackOfMemoHelper(row - 1, col - 1, hashTable);

  hashTable[key] = (rightWei + leftWei) / 2 + 160;

  return hashTable[key];
}
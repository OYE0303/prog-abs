#include <vector>

#include "./../../Headers/printVector.h"
using namespace std;

void rotateGrip(vector<vector<int>> &grid) {
  for (int i = 0; i < grid.size(); i++) {
    vector<int> curRow = grid[i];

    for (int j = i; j < curRow.size(); j++) {
      int tmp = grid[i][j];

      grid[i][j] = grid[j][i];
      grid[j][i] = tmp;
    }
  }
}

int main() {
  vector<vector<int>> grid = {
      {6, 1, 9, 4}, {-2, 5, 8, 12}, {14, 39, -6, 18}, {21, 55, 73, -3}};

  rotateGrip(grid);

  for (int i = 0; i < grid.size(); i++) {
    printVector(grid[i]);
  }

  return 0;
}
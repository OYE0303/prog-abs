#include <iostream>
#include <vector>
using namespace std;

int crossSum(vector<vector<int>> &grid, int rowIdx, int colIdx) {
  int result = 0;

  for (int c = 0; c < grid[rowIdx].size(); c++) {
    result += grid[rowIdx][c];
  }

  for (int r = 0; r < grid.size(); r++) {
    result += grid[r][colIdx];
  }

  result -= grid[rowIdx][colIdx];

  return result;
}

int main() {
  vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int aa = crossSum(grid, 1, 1);

  cout << aa << endl;
  return 0;
}
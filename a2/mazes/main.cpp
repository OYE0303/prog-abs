#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include "../../Headers/printStack.h"
#include "../../Headers/printVector.h"
#include "../../Headers/split.h"

using namespace std;

struct GridLocation {
  int row;
  int col;

  bool operator<(const GridLocation& other) const {
    return (row < other.row) || ((row == other.row) && (col < other.col));
  }

  bool operator!=(const GridLocation& other) const {
    return row != other.row || col != other.col;
  }

  bool operator==(const GridLocation& other) const {
    return row == other.row && col == other.col;
  }
};

// Generates all valid moves for a given current location in the maze.
set<GridLocation> generateValidMoves(vector<vector<bool>>& maze,
                                     GridLocation cur);

// Solves a maze.
stack<GridLocation> solveMaze(vector<vector<bool>>& maze);

// Validates a path through the maze.
bool validatePath(vector<vector<bool>>& maze, stack<GridLocation> path);

// Reads a maze file and stores the maze in a 2D vector.
void readMazeFile(string filename, vector<vector<bool>>& maze);

// Generates a maze from a file.
vector<vector<bool>> generateMazeFromFile(string filename);

// Generates a solution from a file.
stack<GridLocation> generateSolution(string fileName);

// Initializes a maze to all true values.
void initializeMaze(vector<vector<bool>>& maze, int numRows, int numCols);

// Prints a stack of GridLocations.
void printGridLocationStack(stack<GridLocation> s);

int main() {
  vector<vector<bool>> maze = generateMazeFromFile("a2/mazes/res/13x39.maze");
  stack<GridLocation> path = solveMaze(maze);

  cout << "path size: ";
  cout << path.size() << endl;

  cout << "path: ";
  printGridLocationStack(path);

  bool isValid = validatePath(maze, path);
  if (isValid) {
    cout << "The path is valid" << endl;
  } else {
    cout << "The path is invalid" << endl;
  }

  return 0;
}

stack<GridLocation> solveMaze(vector<vector<bool>>& maze) {
  int row = maze.size();

  if (row <= 0) {
    return stack<GridLocation>();
  }

  int col = maze[0].size();
  GridLocation start = {0, 0};
  GridLocation end = {row - 1, col - 1};

  stack<GridLocation> sta;
  sta.push(start);

  queue<stack<GridLocation>> que;
  que.push(sta);

  set<GridLocation> visited;
  while (!que.empty()) {
    stack<GridLocation> curStack = que.front();
    que.pop();

    GridLocation cur = curStack.top();
    if (cur == end) {
      return curStack;
    }

    set<GridLocation> moves = generateValidMoves(maze, cur);
    for (auto move : moves) {
      if (visited.find(move) != visited.end()) {
        continue;
      }

      curStack.push(move);
      que.push(curStack);
    }

    visited.insert(cur);
  }

  return stack<GridLocation>();
}

set<GridLocation> generateValidMoves(vector<vector<bool>>& maze,
                                     GridLocation cur) {
  set<GridLocation> res;

  int maxWidth = maze.size();
  int maxHeight = maze[0].size();

  if (cur.col + 1 < maxHeight && maze[cur.row][cur.col + 1]) {
    res.insert({cur.row, cur.col + 1});
  }

  if (cur.col - 1 >= 0 && maze[cur.row][cur.col - 1]) {
    res.insert({cur.row, cur.col - 1});
  }

  if (cur.row + 1 < maxWidth && maze[cur.row + 1][cur.col]) {
    res.insert({cur.row + 1, cur.col});
  }

  if (cur.row - 1 >= 0 && maze[cur.row - 1][cur.col]) {
    res.insert({cur.row - 1, cur.col});
  }

  return res;
}

bool validatePath(vector<vector<bool>>& maze, stack<GridLocation> path) {
  if (path.empty()) {
    cout << "The path is empty." << endl;
    return false;
  }

  int row = maze.size();
  int col = maze[0].size();
  GridLocation mazeExit = {row - 1, col - 1};
  GridLocation mazeStart = {0, 0};

  if (path.top() != mazeExit) {
    cout << "The path must end at the exit (lower right corner) of the maze"
         << endl;
    return false;
  }

  set<GridLocation> visited;

  GridLocation prevLocation = path.top();
  path.pop();

  while (!path.empty()) {
    GridLocation curLocation = path.top();

    if (path.size() == 1 && curLocation != mazeStart) {
      cout
          << "The path must start at the entry (upper left corner) of the maze."
          << endl;
      return false;
    }

    if (curLocation.col < 0 || curLocation.col >= col || curLocation.row < 0 ||
        curLocation.row >= row) {
      cout << "Each location in the path is within the maze bounds." << endl;
      return false;
    }

    if (!maze[curLocation.row][curLocation.col]) {
      cout << "Each location in the path is an open corridor (not wall)."
           << endl;
      return false;
    }

    if (abs(curLocation.row - prevLocation.row) > 2 ||
        abs(curLocation.col - prevLocation.col) > 2) {
      cout << "Each location is one cardinal step (N,S,E,W) from the next in "
              "path"
           << endl;
      return false;
    }

    if (visited.find(curLocation) != visited.end()) {
      cout << "The path contains no loops, i.e. a location appears at most "
              "once in the path."
           << endl;
      return false;
    }

    visited.insert(curLocation);
    prevLocation = curLocation;
    path.pop();
  }

  return true;
}

vector<vector<bool>> generateMazeFromFile(string fileName) {
  vector<vector<bool>> maze;
  ifstream inputFile(fileName);

  if (!inputFile.is_open()) {
    cerr << "Failed to open the file: " << strerror(errno) << endl;
  }

  vector<string> lines;
  string line;

  while (getline(inputFile, line)) {
    lines.push_back(line);
  }

  int numRows = lines.size();
  int numCols = lines[0].length();
  initializeMaze(maze, numRows, numCols);

  for (int r = 0; r < numRows; r++) {
    if (lines[r].length() != numCols) {
      cerr << "Maze row has inconsistent number of columns" << endl;
    }

    for (int c = 0; c < numCols; c++) {
      char ch = lines[r][c];

      if (ch == '@') {
        maze[r][c] = false;
      } else if (ch == '-') {
        maze[r][c] = true;
      } else {
        cerr << "Maze location has invalid character" << endl;
      }
    }
  }

  return maze;
}

void initializeMaze(vector<vector<bool>>& maze, int numRows, int numCols) {
  for (int r = 0; r < numRows; r++) {
    vector<bool> row;

    for (int c = 0; c < numCols; c++) {
      row.push_back(true);
    }

    maze.push_back(row);
  }
}

std::stack<GridLocation> generateSolution(string fileName) {
  ifstream inputFile(fileName);

  if (!inputFile.is_open()) {
    cerr << "Failed to open the file: " << strerror(errno) << endl;
  }

  vector<string> lines;
  string line;

  while (getline(inputFile, line)) {
    lines.push_back(line);
  }

  std::stack<GridLocation> result;

  string input = lines[0];

  cout << "Input: " << input << endl;

  int i = 0;
  while (i < input.size()) {
    if (input[i] == 'r') {
      i++;
      int row = 0;
      while (isdigit(input[i])) {
        row = row * 10 + (input[i] - '0');
        i++;
      }

      if (input[i] == 'c') {
        i++;
        int col = 0;
        while (isdigit(input[i])) {
          col = col * 10 + (input[i] - '0');
          i++;
        }

        if (input[i] == ',' || input[i] == '}') {
          GridLocation location{row, col};
          result.push(location);

          if (input[i] == '}') {
            break;
          }
        } else {
          std::cerr << "Error parsing input string: expected ',' or '}'"
                    << std::endl;
          return result;
        }
      } else {
        std::cerr << "Error parsing input string: expected 'c'" << std::endl;
        return result;
      }
    } else {
      i++;
    }
  }

  return result;
}

void printGridLocationStack(stack<GridLocation> s) {
  cout << "[";
  int i = 0;

  while (!s.empty()) {
    if (i != 0) cout << ", ";
    cout << "(" << s.top().row << ", " << s.top().col << ")";
    s.pop();
    i++;
  }

  cout << "]" << endl;
}
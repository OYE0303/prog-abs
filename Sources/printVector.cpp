#include <iostream>
#include <vector>
using namespace std;

#define BLUE_TEXT "\033[1;34m"
#define GREEN_TEXT "\033[1;32m"

// Function to print vector of non-string types (blue)
template <typename T>
void printVector(const vector<T>& vec) {
    cout << BLUE_TEXT << "[";
    if (!vec.empty()) {
        cout << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            cout << ", " << vec[i];
        }
    }
    cout << "]" << endl;
}

// Function to print vector of string types (green)
void printVector(const vector<string>& vec) {
    cout << GREEN_TEXT << "[";
    if (!vec.empty()) {
        cout << "\"" << vec[0] << "\"";
        for (size_t i = 1; i < vec.size(); ++i) {
            cout << ", \"" << vec[i] << "\"";
        }
    }
    cout << "]" << endl;
}
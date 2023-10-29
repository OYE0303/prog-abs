#include "myVector.h"

#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 8;

MyVector::MyVector() {
  arr = new int[INITIAL_CAPACITY];
  capacity = INITIAL_CAPACITY;
  length = 0;
}

MyVector::~MyVector() { delete[] arr; }

void MyVector::add(int value) {
  if (length >= capacity) {
    int* newArr = new int[capacity * 2];
    for (int i = 0; i < length; i++) {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity *= 2;
  }

  arr[length] = value;
  length++;
}

void MyVector::insert(int index, int value) {
  if (length >= capacity) {
    cout << "error" << endl;
    return;
  }

  if (index < 0 || index > length) {
    cout << "error" << endl;
    return;
  }

  for (int i = length; i > index; i--) {
    arr[i] = arr[i - 1];
  }

  arr[index] = value;
  length++;
}

int MyVector::get(int index) {
  if (index < 0 || index >= length) {
    cout << "error" << endl;
    return -1;
  }

  return arr[index];
}

void MyVector::remove(int index) {
  if (index < 0 || index >= length) {
    cout << "error" << endl;
    return;
  }

  for (int i = length - 1; i > index; i--) {
    arr[i - 1] = arr[i];
  }
  length--;
}

int MyVector::size() { return length; }

bool MyVector::isEmpty() { return length == 0; }
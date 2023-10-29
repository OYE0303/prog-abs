#pragma once

using namespace std;

class MyVector {
 public:
  // the name of constructor is the same as the name of the class
  // and takes no arguments, and no return value
  MyVector();

  // A desctructor is a special function responsible for cleaning up
  // the memory allocated by the object
  // It's automatically called when an object's lifetime ends
  // The destructor must take responsibility for freeing any allocated
  // memory currently held by the object
  ~MyVector();

  // add a value to the end of the vector
  void add(int value);

  // insert a value at a given index
  void insert(int index, int value);

  // get the value at a given index
  int get(int index);

  // remove the value at a given index
  void remove(int index);

  // size of the vector
  int size();

  // check if the vector is empty
  bool isEmpty();

 private:
  // A pointer to an array of integers, which will act as underlying
  // data structure
  int* arr;

  // An integer representing the size of the allocated array
  int capacity;

  // An integer representing the number of elements in the vector
  int length;
};
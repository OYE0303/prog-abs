#pragma once

#include <iostream>
#include <string>

using namespace std;

struct DataPoint {
  string name;    // Name of this data point; varies by application
  double weight;  // "Weight" of this data point. Points are sorted by weight.
};

/**
 * Priority queue type implemented using a binary heap
 *
 * As a reminder, you are required to do all your own memory management using
 * new[] and delete[].
 */
class HeapPQueue {
 public:
  // HeapPQueue is a constructor that initializes the array to a default size
  HeapPQueue();

  // ~HeapPQueue() is a destructor that cleans up all memory allocated by this
  // priority queue
  ~HeapPQueue();

  /**
   * Adds a new data point into the queue. This operation runs in time O(log n),
   * where n is the number of elements in the queue.
   *
   * @param data The data point to add.
   */
  void enqueue(const DataPoint& data);

  /**
   * Removes and returns the lowest-weight data point in the priority queue. If
   * multiple elements are tied for having the loweset weight, any one of them
   * may be returned.
   *
   * If the priority queue is empty, this function calls error() to report an
   * error.
   *
   * This operation must run in time O(log n), where n is the number of elements
   * in the queue.
   *
   * @return The lowest-weight data point in the queue.
   */
  DataPoint dequeue();

  /**
   * Returns, but does not remove, the element that would next be removed via a
   * call to dequeue.
   *
   * If the priority queue is empty, this function calls error() to report an
   * error.
   *
   * This operation must run in time O(1).
   *
   * @return
   */
  DataPoint peek() const;

  /**
   * Returns whether the priority queue is empty.
   *
   * This operation must run in time O(1).
   *
   * @return Whether the priority queue is empty.
   */
  bool isEmpty() const;

  /**
   * Returns the number of data points in this priority queue.
   *
   * This operation must run in time O(1).
   *
   * @return The number of elements in the priority queue.
   */
  int size() const;

  /* This function exists purely for testing purposes. You can have it do
   * whatever you'd like and we won't be invoking it when grading. In the past,
   * students have had this function print out the array representing the heap,
   * or information about how much space is allocated, etc. Feel free to use it
   * as you see fit!
   */
  void printDebugInfo();

  void printHeapPQueue();

  int checkCapacity();

  DataPoint checkSpecificNode(int index);

  // Constant controlling how big the original array should be.
  static const int INITIAL_SIZE = 6;

 private:
  // Pointer to the array of elements in the heap.
  DataPoint* arr = nullptr;

  // length is the number of elements in the heap
  int length = 0;

  // capacity is the number of elements the heap can hold
  int capacity = 0;

  void expandCapacity();

  void bubbleUp();

  void bubbleDown();
};

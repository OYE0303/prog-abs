#include "heapPQueue.h"

HeapPQueue::HeapPQueue() {
  arr = new DataPoint[INITIAL_SIZE];
  capacity = INITIAL_SIZE;
  length = 0;
  arr[0] = {"", -std::numeric_limits<double>::infinity()};
}

HeapPQueue::~HeapPQueue() { delete[] arr; }

bool HeapPQueue::isEmpty() const { return length == 0; }

int HeapPQueue::size() const { return length; }

void HeapPQueue::enqueue(const DataPoint& data) {
  length++;

  if (capacity == length) {
    expandCapacity();
  }

  arr[length] = data;
  bubbleUp();
}

DataPoint HeapPQueue::dequeue() {
  if (isEmpty()) {
    cout << "Priority queue is empty" << endl;
    return {"", 0};
  }

  DataPoint res = arr[1];

  arr[1] = arr[length];
  length--;
  bubbleDown();
  return res;
}

DataPoint HeapPQueue::peek() const {
  if (isEmpty()) {
    cout << "Priority queue is empty" << endl;
    return {"", 0};
  }

  return arr[1];
}

void HeapPQueue::expandCapacity() {
  DataPoint* oldArr = arr;
  capacity *= 2;
  arr = new DataPoint[capacity];
  for (int i = 0; i <= length; i++) arr[i] = oldArr[i];
  delete[] oldArr;
}

void HeapPQueue::bubbleUp() {
  int curNodeIndex = length;
  int parentNodeIndex = length / 2;
  DataPoint curNode = arr[curNodeIndex];
  DataPoint parentNode = arr[parentNodeIndex];

  while (curNode.weight < parentNode.weight) {
    arr[parentNodeIndex] = curNode;
    arr[curNodeIndex] = parentNode;

    curNodeIndex = parentNodeIndex;
    parentNodeIndex = curNodeIndex / 2;

    curNode = arr[curNodeIndex];
    parentNode = arr[parentNodeIndex];
  }
}

void HeapPQueue::bubbleDown() {
  if (length <= 1) {
    return;
  }

  int curNodeIndex = 1;
  int childNodeIndex1 = 2 * curNodeIndex;
  int childNodeIndex2 = 2 * curNodeIndex + 1;
  int childNodeIndex;

  DataPoint curNode = arr[curNodeIndex];
  DataPoint childNode;

  // choose the smaller child node
  // note that childNodeIndex2 is the right child node, and is always larger
  // so if childNodeIndex2 is out of bounds, then childNodeIndex1 is the only
  // child node
  if (length < childNodeIndex2 ||
      arr[childNodeIndex2].weight > arr[childNodeIndex1].weight) {
    childNode = arr[childNodeIndex1];
    childNodeIndex = childNodeIndex1;
  } else {
    childNode = arr[childNodeIndex2];
    childNodeIndex = childNodeIndex2;
  }

  // keep while-loop until the current node is smaller than both child nodes
  // or the current node is out of bounds
  while (length > curNodeIndex && curNode.weight > childNode.weight) {
    // swap
    arr[childNodeIndex] = curNode;
    arr[curNodeIndex] = childNode;

    // update index
    curNodeIndex = childNodeIndex;
    childNodeIndex1 = 2 * curNodeIndex;
    childNodeIndex2 = 2 * curNodeIndex + 1;

    if (length < childNodeIndex1) {
      break;
    }

    // update pointer
    if (length < childNodeIndex2 ||
        arr[childNodeIndex2].weight > arr[childNodeIndex1].weight) {
      childNode = arr[childNodeIndex1];
      childNodeIndex = childNodeIndex1;
    } else {
      childNode = arr[childNodeIndex2];
      childNodeIndex = childNodeIndex2;
    }
  }
}

void HeapPQueue::printHeapPQueue() {
  cout << "HeapPQueue: "
       << "[" << endl;
  for (int i = 0; i <= length; i++) {
    cout << "  {" << endl;
    cout << "    name: \"" << arr[i].name << "\"," << endl;
    cout << "    weight: " << arr[i].weight << endl;
    cout << "  }" << endl;
  }
  cout << "]" << endl;
}

int HeapPQueue::checkCapacity() { return capacity; }

DataPoint HeapPQueue::checkSpecificNode(int index) {
  if (index > length) {
    cout << "Index out of bounds" << endl;
    return {"", 0};
  }

  return arr[index];
}

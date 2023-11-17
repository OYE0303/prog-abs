#include <iostream>
#include <random>
#include <vector>

#include "heapPQueue.cpp"

using namespace std;

double randomReal(double low, double high);

void testHeapPQueue1() {
  //////////////////////////////////////////
  // Fist test
  //////////////////////////////////////////
  cout << "TEST: Newly-created heap allocates an array of the right size."
       << endl;
  HeapPQueue pq;

  if (!pq.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  if (pq.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  //////////////////////////////////////////
  // Second test
  //////////////////////////////////////////
  cout << "TEST: Can enqueue a single element." << endl;
  HeapPQueue pq2;
  pq2.enqueue({"First", 137.0});
  if (pq2.size() != 1) {
    cout << "Test Failed: pq.size() should return 1" << endl;
    return;
  }

  if (pq2.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return false" << endl;
    return;
  }

  if (pq2.checkSpecificNode(1).name != "First" ||
      pq2.checkSpecificNode(1).weight != 137.0) {
    cout << "Test Failed: pq.checkSpecificNode(1).name should return \"First\""
         << endl;
    return;
  }

  if (pq2.checkCapacity() != HeapPQueue::INITIAL_SIZE) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE << endl;
    return;
  }

  //////////////////////////////////////////
  // Third test
  //////////////////////////////////////////
  cout << "TEST: Enqueues two elements in sorted order." << endl;
  HeapPQueue pq3;
  pq3.enqueue({"First", 1.6108});

  if (pq3.checkSpecificNode(1).name != "First" ||
      pq3.checkSpecificNode(1).weight != 1.6108) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", "
            "1.6108}"
         << endl;
    return;
  }

  pq3.enqueue({"Second", 2.7182});

  if (pq3.size() != 2) {
    cout << "Test Failed: pq.size() should return 2" << endl;
    return;
  }

  if (pq3.checkSpecificNode(1).name != "First" ||
      pq3.checkSpecificNode(1).weight != 1.6108) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", "
            "1.6108} after enqueueing {\"Second\", 2.7182}"
         << endl;
    return;
  }

  if (pq3.checkSpecificNode(2).name != "Second" ||
      pq3.checkSpecificNode(2).weight != 2.7182) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2.7182}"
         << endl;
    return;
  }

  if (pq3.checkCapacity() != HeapPQueue::INITIAL_SIZE) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE << endl;
    return;
  }

  //////////////////////////////////////////
  // Fourth test
  //////////////////////////////////////////
  cout << "TEST: Enqueues two elements in reverse sorted order." << endl;
  HeapPQueue pq4;
  pq4.enqueue({"First", 3.1415});

  if (pq4.checkSpecificNode(1).name != "First" ||
      pq4.checkSpecificNode(1).weight != 3.1415) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", "
            "3.1415}"
         << endl;
    return;
  }

  pq4.enqueue({"Second", 2.7182});

  if (pq4.size() != 2) {
    cout << "Test Failed: pq.size() should return 2" << endl;
    return;
  }

  if (pq4.checkSpecificNode(1).name != "Second" ||
      pq4.checkSpecificNode(1).weight != 2.7182) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"Second\", "
            "2.7182} after enqueueing {\"First\", 3.1415}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(2).name != "First" ||
      pq4.checkSpecificNode(2).weight != 3.1415) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"First\", "
            "3.1415}"
         << endl;
    return;
  }

  if (pq4.checkCapacity() != HeapPQueue::INITIAL_SIZE) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE << endl;
    return;
  }

  //////////////////////////////////////////
  // Fifth test
  //////////////////////////////////////////
  cout << "TEST: Enqueues three elements in sorted order." << endl;
  HeapPQueue pq5;
  pq5.enqueue({"First", 1.6108});
  pq5.enqueue({"Second", 2.7182});
  pq5.enqueue({"Third", 3.1415});

  if (pq5.size() != 3) {
    cout << "Test Failed: pq.size() should return 3" << endl;
    return;
  }

  if (pq5.checkSpecificNode(1).name != "First" ||
      pq5.checkSpecificNode(1).weight != 1.6108) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", "
            "1.6108}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(2).name != "Second" ||
      pq5.checkSpecificNode(2).weight != 2.7182) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2.7182}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(3).name != "Third" ||
      pq5.checkSpecificNode(3).weight != 3.1415) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", "
            "3.1415}"
         << endl;
    return;
  }

  if (pq5.checkCapacity() != HeapPQueue::INITIAL_SIZE) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE << endl;
    return;
  }

  //////////////////////////////////////////
  // Sixth test
  //////////////////////////////////////////
  cout << "TEST: Enqueues three elements in reverse sorted order." << endl;
  HeapPQueue pq6;
  pq6.enqueue({"First", 3.1415});
  pq6.enqueue({"Second", 2.7182});
  pq6.enqueue({"Third", 1.6108});

  if (pq6.size() != 3) {
    cout << "Test Failed: pq.size() should return 3" << endl;
    return;
  }

  if (pq6.checkSpecificNode(1).name != "Third" ||
      pq6.checkSpecificNode(1).weight != 1.6108) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"Third\", "
            "1.6108}"
         << endl;
    return;
  }

  if (pq6.checkSpecificNode(2).name != "First" ||
      pq6.checkSpecificNode(2).weight != 3.1415) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"First\", "
            "3.1415}"
         << endl;
    return;
  }

  if (pq6.checkSpecificNode(3).name != "Second" ||
      pq6.checkSpecificNode(3).weight != 2.7182) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Second\", "
            "2.7182}"
         << endl;
    return;
  }

  if (pq6.checkCapacity() != HeapPQueue::INITIAL_SIZE) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE << endl;
    return;
  }

  //////////////////////////////////////////
  // Seventh test
  //////////////////////////////////////////
  cout << "TEST: Enqueues five elements in sorted order." << endl;
  HeapPQueue pq7;
  pq7.enqueue({"First", 1.0});
  pq7.enqueue({"Second", 2.0});
  pq7.enqueue({"Third", 3.0});
  pq7.enqueue({"Fourth", 4.0});
  pq7.enqueue({"Fifth", 5.0});

  if (pq7.size() != 5) {
    cout << "Test Failed: pq.size() should return 5" << endl;
    return;
  }

  if (pq7.checkSpecificNode(1).name != "First" ||
      pq7.checkSpecificNode(1).weight != 1.0) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", "
            "1.0}"
         << endl;
    return;
  }

  if (pq7.checkSpecificNode(2).name != "Second" ||
      pq7.checkSpecificNode(2).weight != 2.0) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2.0}"
         << endl;
    return;
  }

  if (pq7.checkSpecificNode(3).name != "Third" ||
      pq7.checkSpecificNode(3).weight != 3.0) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", "
            "3.0}"
         << endl;
    return;
  }

  if (pq7.checkSpecificNode(4).name != "Fourth" ||
      pq7.checkSpecificNode(4).weight != 4.0) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Fourth\", "
            "4.0}"
         << endl;
    return;
  }

  if (pq7.checkSpecificNode(5).name != "Fifth" ||
      pq7.checkSpecificNode(5).weight != 5.0) {
    cout << "Test Failed: pq.checkSpecificNode(5) should return {\"Fifth\", "
            "5.0}"
         << endl;
    return;
  }

  if (pq7.checkCapacity() != HeapPQueue::INITIAL_SIZE) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE << endl;
    return;
  }

  //////////////////////////////////////////
  // Eighth test
  //////////////////////////////////////////
  cout << "TEST: Enqueues five elements in reverse sorted order." << endl;
  HeapPQueue pq8;
  pq8.enqueue({"First", 10.0});
  pq8.enqueue({"Second", 9.0});
  pq8.enqueue({"Third", 8.0});
  pq8.enqueue({"Fourth", 7.0});
  pq8.enqueue({"Fifth", 6.0});

  if (pq8.size() != 5) {
    cout << "Test Failed: pq.size() should return 5" << endl;
    return;
  }

  if (pq8.checkSpecificNode(1).name != "Fifth" ||
      pq8.checkSpecificNode(1).weight != 6.0) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"Fifth\", "
            "6.0}"
         << endl;
    return;
  }

  if (pq8.checkSpecificNode(2).name != "Fourth" ||
      pq8.checkSpecificNode(2).weight != 7.0) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Fourth\", "
            "7.0}"
         << endl;
    return;
  }

  if (pq8.checkSpecificNode(3).name != "Second" ||
      pq8.checkSpecificNode(3).weight != 9.0) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Second\", "
            "9.0}"
         << endl;
    return;
  }

  if (pq8.checkSpecificNode(4).name != "First" ||
      pq8.checkSpecificNode(4).weight != 10.0) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"First\", "
            "10.0}"
         << endl;
    return;
  }

  if (pq8.checkSpecificNode(5).name != "Third" ||
      pq8.checkSpecificNode(5).weight != 8.0) {
    cout << "Test Failed: pq.checkSpecificNode(5) should return {\"Third\", "
            "8.0}"
         << endl;
    return;
  }

  if (pq8.checkCapacity() != HeapPQueue::INITIAL_SIZE) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE << endl;
    return;
  }

  //////////////////////////////////////////
  // Ninth test
  //////////////////////////////////////////
  cout << "TEST: Enqueues grows the internal array." << endl;
  HeapPQueue pq9;
  pq9.enqueue({"First", 1.0});
  pq9.enqueue({"Second", 2.0});
  pq9.enqueue({"Third", 3.0});
  pq9.enqueue({"Fourth", 4.0});
  pq9.enqueue({"Fifth", 5.0});
  pq9.enqueue({"Sixth", 6.0});
  pq9.enqueue({"Seventh", 7.0});

  if (pq9.size() != 7) {
    cout << "Test Failed: pq.size() should return 7" << endl;
    return;
  }

  if (pq9.checkSpecificNode(1).name != "First" ||
      pq9.checkSpecificNode(1).weight != 1.0) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", "
            "1.0}"
         << endl;
    return;
  }

  if (pq9.checkSpecificNode(2).name != "Second" ||
      pq9.checkSpecificNode(2).weight != 2.0) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2.0}"
         << endl;
    return;
  }

  if (pq9.checkSpecificNode(3).name != "Third" ||
      pq9.checkSpecificNode(3).weight != 3.0) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", "
            "3.0}"
         << endl;
    return;
  }

  if (pq9.checkSpecificNode(4).name != "Fourth" ||
      pq9.checkSpecificNode(4).weight != 4.0) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Fourth\", "
            "4.0}"
         << endl;
    return;
  }

  if (pq9.checkSpecificNode(5).name != "Fifth" ||
      pq9.checkSpecificNode(5).weight != 5.0) {
    cout << "Test Failed: pq.checkSpecificNode(5) should return {\"Fifth\", "
            "5.0}"
         << endl;
    return;
  }

  if (pq9.checkSpecificNode(6).name != "Sixth" ||
      pq9.checkSpecificNode(6).weight != 6.0) {
    cout << "Test Failed: pq.checkSpecificNode(6) should return {\"Sixth\", "
            "6.0}"
         << endl;
    return;
  }

  if (pq9.checkSpecificNode(7).name != "Seventh" ||
      pq9.checkSpecificNode(7).weight != 7.0) {
    cout << "Test Failed: pq.checkSpecificNode(7) should return {\"Seventh\", "
            "7.0}"
         << endl;
    return;
  }

  if (pq9.checkCapacity() != HeapPQueue::INITIAL_SIZE * 2) {
    cout << "Test Failed: pq.checkCapacity() should return "
         << HeapPQueue::INITIAL_SIZE * 2 << endl;
    return;
  }

  //////////////////////////////////////////
  // Tenth test
  //////////////////////////////////////////
  cout << "TEST: Enqueues repeatedly grows the internal array." << endl;
  HeapPQueue pq10;

  for (int i = 1; i < 14; i++) {
    pq10.enqueue({to_string(i), double(i)});

    if (pq10.size() != i) {
      cout << "Test Failed: pq.size() should return " << i << endl;
      return;
    }

    for (int j = 1; j <= i; j++) {
      if (pq10.checkSpecificNode(j).name != to_string(j) ||
          pq10.checkSpecificNode(j).weight != double(j)) {
        cout << "Test Failed: pq.checkSpecificNode(" << j
             << ") should return {\"" << to_string(j) << "\", " << double(j)
             << "}" << endl;
        return;
      }
    }
  }

  //////////////////////////////////////////
  // 11th test
  //////////////////////////////////////////
  cout << "TEST: Enqueue can bubble up long chains." << endl;
  HeapPQueue pq11;
  for (int i = 2; i <= 15; i++) {
    pq11.enqueue({to_string(i), double(i)});
  }

  for (int i = 2; i <= 15; i++) {
    if (pq11.checkSpecificNode(i - 1).name != to_string(i) ||
        pq11.checkSpecificNode(i - 1).weight != double(i)) {
      cout << "Test Failed: pq.checkSpecificNode(" << i - 1
           << ") should return {\"" << to_string(i) << "\", " << double(i)
           << "}" << endl;
      return;
    }
  }

  pq11.enqueue({"1", 1});

  if (pq11.size() != 15) {
    cout << "Test Failed: pq.size() should return 15" << endl;
    return;
  }

  if (pq11.checkSpecificNode(1).name != "1" ||
      pq11.checkSpecificNode(1).weight != 1) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"1\", 1}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(2).name != "3" ||
      pq11.checkSpecificNode(2).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"3\", 3}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(3).name != "2" ||
      pq11.checkSpecificNode(3).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"2\", 2}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(4).name != "5" ||
      pq11.checkSpecificNode(4).weight != 5) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"5\", 5}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(5).name != "6" ||
      pq11.checkSpecificNode(5).weight != 6) {
    cout << "Test Failed: pq.checkSpecificNode(5) should return {\"6\", 6}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(6).name != "7" ||
      pq11.checkSpecificNode(6).weight != 7) {
    cout << "Test Failed: pq.checkSpecificNode(6) should return {\"7\", 7}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(7).name != "4" ||
      pq11.checkSpecificNode(7).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(7) should return {\"4\", 4}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(8).name != "9" ||
      pq11.checkSpecificNode(8).weight != 9) {
    cout << "Test Failed: pq.checkSpecificNode(8) should return {\"9\", 9}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(9).name != "10" ||
      pq11.checkSpecificNode(9).weight != 10) {
    cout << "Test Failed: pq.checkSpecificNode(9) should return {\"10\", 10}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(10).name != "11" ||
      pq11.checkSpecificNode(10).weight != 11) {
    cout << "Test Failed: pq.checkSpecificNode(10) should return {\"11\", 11}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(11).name != "12" ||
      pq11.checkSpecificNode(11).weight != 12) {
    cout << "Test Failed: pq.checkSpecificNode(11) should return {\"12\", 12}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(12).name != "13" ||
      pq11.checkSpecificNode(12).weight != 13) {
    cout << "Test Failed: pq.checkSpecificNode(12) should return {\"13\", 13}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(13).name != "14" ||
      pq11.checkSpecificNode(13).weight != 14) {
    cout << "Test Failed: pq.checkSpecificNode(13) should return {\"14\", 14}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(14).name != "15" ||
      pq11.checkSpecificNode(14).weight != 15) {
    cout << "Test Failed: pq.checkSpecificNode(14) should return {\"15\", 15}"
         << endl;
    return;
  }

  if (pq11.checkSpecificNode(15).name != "8" ||
      pq11.checkSpecificNode(15).weight != 8) {
    cout << "Test Failed: pq.checkSpecificNode(15) should return {\"8\", 8}"
         << endl;
    return;
  }

  cout << "All tests passed!!!" << endl;
}

void testHeapPQueue2() {
  //////////////////////////////////////////
  // 1st test
  //////////////////////////////////////////
  cout << "TEST: Can enqueue and dequeue a single element." << endl;
  HeapPQueue pq;
  pq.enqueue({"First", 137});
  DataPoint res = pq.dequeue();

  if (res.name != "First" || res.weight != 137) {
    cout << "Test Failed: pq.dequeue() should return {\"First\", 137}" << endl;
    return;
  }

  if (pq.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 2nd test
  //////////////////////////////////////////
  cout << "TEST: Can bubble down to the left." << endl;
  HeapPQueue pq2;
  pq2.enqueue({"First", 1});
  pq2.enqueue({"Second", 2});
  pq2.enqueue({"Third", 3});
  pq2.enqueue({"Fourth", 4});

  if (pq2.size() != 4) {
    cout << "Test Failed: pq.size() should return 4" << endl;
    return;
  }

  if (pq2.checkSpecificNode(1).name != "First" ||
      pq2.checkSpecificNode(1).weight != 1) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", 1}"
         << endl;
    return;
  }

  if (pq2.checkSpecificNode(2).name != "Second" ||
      pq2.checkSpecificNode(2).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq2.checkSpecificNode(3).name != "Third" ||
      pq2.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", 3}"
         << endl;
    return;
  }

  if (pq2.checkSpecificNode(4).name != "Fourth" ||
      pq2.checkSpecificNode(4).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  DataPoint res2nd1 = pq2.dequeue();

  if (res2nd1.name != "First" || res2nd1.weight != 1) {
    cout << "Test Failed: pq.dequeue() should return {\"First\", 1}" << endl;
    return;
  }

  if (pq2.size() != 3) {
    cout << "Test Failed: pq.size() should return 3" << endl;
    return;
  }

  if (pq2.checkSpecificNode(1).name != "Second" ||
      pq2.checkSpecificNode(1).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq2.checkSpecificNode(2).name != "Fourth" ||
      pq2.checkSpecificNode(2).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  if (pq2.checkSpecificNode(3).name != "Third" ||
      pq2.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", 3}"
         << endl;
    return;
  }

  //////////////////////////////////////////
  // 3rd test
  //////////////////////////////////////////
  cout << "TEST: Can bubble down to the right." << endl;
  HeapPQueue pq3;
  pq3.enqueue({"First", 1});
  pq3.enqueue({"Second", 2});
  pq3.enqueue({"Third", 3});
  pq3.enqueue({"Fourth", 4});

  if (pq3.size() != 4) {
    cout << "Test Failed: pq.size() should return 4" << endl;
    return;
  }

  if (pq3.checkSpecificNode(1).name != "First" ||
      pq3.checkSpecificNode(1).weight != 1) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", 1}"
         << endl;
    return;
  }

  if (pq3.checkSpecificNode(2).name != "Second" ||
      pq3.checkSpecificNode(2).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq3.checkSpecificNode(3).name != "Third" ||
      pq3.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed111: pq.checkSpecificNode(3) should return {\"Third\", "
            "3}"
         << endl;
    return;
  }

  if (pq3.checkSpecificNode(4).name != "Fourth" ||
      pq3.checkSpecificNode(4).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  DataPoint res3rd1 = pq3.dequeue();

  if (res3rd1.name != "First" || res3rd1.weight != 1) {
    cout << "Test Failed: pq.dequeue() should return {\"First\", 1}" << endl;
    return;
  }

  if (pq3.size() != 3) {
    cout << "Test Failed: pq.size() should return 3" << endl;
    return;
  }

  if (pq3.checkSpecificNode(1).name != "Second" ||
      pq3.checkSpecificNode(1).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq3.checkSpecificNode(2).name != "Fourth" ||
      pq3.checkSpecificNode(2).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  if (pq3.checkSpecificNode(3).name != "Third" ||
      pq3.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", "
            "3}"
         << endl;
    return;
  }

  //////////////////////////////////////////
  // 4th test
  //////////////////////////////////////////
  cout << "TEST: Can bubble down two layers." << endl;
  HeapPQueue pq4;
  pq4.enqueue({"First", 1});
  pq4.enqueue({"Second", 2});
  pq4.enqueue({"Third", 3});
  pq4.enqueue({"Fourth", 4});
  pq4.enqueue({"Fifth", 5});
  pq4.enqueue({"Sixth", 6});

  if (pq4.size() != 6) {
    cout << "Test Failed: pq.size() should return 6" << endl;
    return;
  }

  if (pq4.checkSpecificNode(1).name != "First" ||
      pq4.checkSpecificNode(1).weight != 1) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", 1}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(2).name != "Second" ||
      pq4.checkSpecificNode(2).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(3).name != "Third" ||
      pq4.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", 3}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(4).name != "Fourth" ||
      pq4.checkSpecificNode(4).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(5).name != "Fifth" ||
      pq4.checkSpecificNode(5).weight != 5) {
    cout << "Test Failed: pq.checkSpecificNode(5) should return {\"Fifth\", 5}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(6).name != "Sixth" ||
      pq4.checkSpecificNode(6).weight != 6) {
    cout << "Test Failed: pq.checkSpecificNode(6) should return {\"Sixth\", 6}"
         << endl;
    return;
  }

  DataPoint res4th1 = pq4.dequeue();

  if (res4th1.name != "First" || res4th1.weight != 1) {
    cout << "Test Failed: pq.dequeue() should return {\"First\", 1}" << endl;
    return;
  }

  if (pq4.size() != 5) {
    cout << "Test Failed: pq.size() should return 5" << endl;
    return;
  }

  if (pq4.checkSpecificNode(1).name != "Second" ||
      pq4.checkSpecificNode(1).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(2).name != "Fourth" ||
      pq4.checkSpecificNode(2).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(3).name != "Third" ||
      pq4.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", "
            "3}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(4).name != "Sixth" ||
      pq4.checkSpecificNode(4).weight != 6) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Sixth\", 6}"
         << endl;
    return;
  }

  if (pq4.checkSpecificNode(5).name != "Fifth" ||
      pq4.checkSpecificNode(5).weight != 5) {
    cout << "Test Failed: pq.checkSpecificNode(5) should return {\"Fifth\", 5}"
         << endl;
    return;
  }

  //////////////////////////////////////////
  // 5th test
  //////////////////////////////////////////
  cout << "TEST: Can bubble down when only one child exists." << endl;
  HeapPQueue pq5;
  pq5.enqueue({"First", 1});
  pq5.enqueue({"Second", 2});
  pq5.enqueue({"Third", 3});
  pq5.enqueue({"Fourth", 4});
  pq5.enqueue({"Fifth", 5});

  if (pq5.size() != 5) {
    cout << "Test Failed: pq.size() should return 5" << endl;
    return;
  }

  if (pq5.checkSpecificNode(1).name != "First" ||
      pq5.checkSpecificNode(1).weight != 1) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"First\", 1}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(2).name != "Second" ||
      pq5.checkSpecificNode(2).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(3).name != "Third" ||
      pq5.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", 3}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(4).name != "Fourth" ||
      pq5.checkSpecificNode(4).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(5).name != "Fifth" ||
      pq5.checkSpecificNode(5).weight != 5) {
    cout << "Test Failed: pq.checkSpecificNode(5) should return {\"Fifth\", 5}"
         << endl;
    return;
  }

  DataPoint res5th1 = pq5.dequeue();

  if (res5th1.name != "First" || res5th1.weight != 1) {
    cout << "Test Failed: pq.dequeue() should return {\"First\", 1}" << endl;
    return;
  }

  if (pq5.size() != 4) {
    cout << "Test Failed: pq.size() should return 4" << endl;
    return;
  }

  if (pq5.checkSpecificNode(1).name != "Second" ||
      pq5.checkSpecificNode(1).weight != 2) {
    cout << "Test Failed: pq.checkSpecificNode(1) should return {\"Second\", "
            "2}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(2).name != "Fourth" ||
      pq5.checkSpecificNode(2).weight != 4) {
    cout << "Test Failed: pq.checkSpecificNode(2) should return {\"Fourth\", "
            "4}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(3).name != "Third" ||
      pq5.checkSpecificNode(3).weight != 3) {
    cout << "Test Failed: pq.checkSpecificNode(3) should return {\"Third\", "
            "3}"
         << endl;
    return;
  }

  if (pq5.checkSpecificNode(4).name != "Fifth" ||
      pq5.checkSpecificNode(4).weight != 5) {
    cout << "Test Failed: pq.checkSpecificNode(4) should return {\"Fifth\", 5}"
         << endl;
    return;
  }

  //////////////////////////////////////////
  // 6th test
  //////////////////////////////////////////
  cout << "TEST: Enqueue / dequeue single elemen" << endl;
  HeapPQueue pq6;
  DataPoint point = {"enqueue me!", 4};
  pq6.enqueue(point);

  if (pq6.size() != 1) {
    cout << "Test Failed: pq.size() should return 1" << endl;
    return;
  }

  if (pq6.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return false" << endl;
    return;
  }

  DataPoint res6th1 = pq6.dequeue();

  if (res6th1.name != "enqueue me!" || res6th1.weight != 4) {
    cout << "Test Failed: pq.dequeue() should return {\"enqueue me!\", 4}"
         << endl;
    return;
  }

  if (pq6.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq6.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  pq6.enqueue(point);

  if (pq6.size() != 1) {
    cout << "Test Failed: pq.size() should return 1" << endl;
    return;
  }

  if (pq6.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return false" << endl;
    return;
  }

  DataPoint res6th2 = pq6.dequeue();

  if (res6th2.name != "enqueue me!" || res6th2.weight != 4) {
    cout << "Test Failed: pq.dequeue() should return {\"enqueue me!\", 4}"
         << endl;
    return;
  }

  if (pq6.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq6.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  cout << "All tests passed!!!" << endl;
}

void testHeapPQueue3() {
  //////////////////////////////////////////
  // 1st test
  //////////////////////////////////////////
  cout << "TEST: Enqueue elements in sorted order." << endl;
  HeapPQueue pq;
  for (int i = 0; i < 10; i++) {
    pq.enqueue({"elem" + to_string(i), double(i)});
  }

  if (pq.size() != 10) {
    cout << "Test Failed: pq.size() should return 10" << endl;
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (pq.peek().name != "elem" + to_string(i) ||
        pq.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"elem" << i << "\", " << i
           << "}" << endl;
      return;
    }

    DataPoint res = pq.dequeue();
    if (res.name != "elem" + to_string(i) || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"elem" << i << "\", "
           << i << "}" << endl;
      return;
    }
  }

  if (pq.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 2nd test
  //////////////////////////////////////////
  cout << "TEST: Enqueue many elements in sorted order." << endl;
  HeapPQueue pq2;
  for (int i = 0; i < 10000; i++) {
    pq2.enqueue({"elem" + to_string(i), double(i)});
  }

  if (pq2.size() != 10000) {
    cout << "Test Failed: pq.size() should return 10000" << endl;
    return;
  }

  for (int i = 0; i < 10000; i++) {
    if (pq2.peek().name != "elem" + to_string(i) ||
        pq2.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"elem" << i << "\", " << i
           << "}" << endl;
      return;
    }

    DataPoint res = pq2.dequeue();
    if (res.name != "elem" + to_string(i) || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"elem" << i << "\", "
           << i << "}" << endl;
      return;
    }
  }

  if (pq2.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq2.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 3rd test
  //////////////////////////////////////////
  cout << "TEST: Enqueue elements in reverse-sorted order." << endl;
  HeapPQueue pq3;
  for (int i = 10; i >= 0; i--) {
    pq3.enqueue({"elem" + to_string(i), double(i)});
  }

  if (pq3.size() != 11) {
    cout << "Test Failed: pq.size() should return 11" << endl;
    return;
  }

  for (int i = 0; i <= 10; i++) {
    if (pq3.peek().name != "elem" + to_string(i) ||
        pq3.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"elem" << i << "\", " << i
           << "}" << endl;
      return;
    }

    DataPoint res = pq3.dequeue();
    if (res.name != "elem" + to_string(i) || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"elem" << i << "\", "
           << i << "}" << endl;
      return;
    }
  }

  if (pq3.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq3.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 4th test
  //////////////////////////////////////////
  cout << "TEST: Enqueue many elements in reverse-sorted order." << endl;
  HeapPQueue pq4;
  for (int i = 10000; i >= 0; i--) {
    pq4.enqueue({"elem" + to_string(i), double(i)});
  }

  if (pq4.size() != 10001) {
    cout << "Test Failed: pq.size() should return 10001" << endl;
    return;
  }

  for (int i = 0; i <= 10000; i++) {
    if (pq4.peek().name != "elem" + to_string(i) ||
        pq4.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"elem" << i << "\", " << i
           << "}" << endl;
      return;
    }

    DataPoint res = pq4.dequeue();
    if (res.name != "elem" + to_string(i) || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"elem" << i << "\", "
           << i << "}" << endl;
      return;
    }
  }

  if (pq4.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq4.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 5th test
  //////////////////////////////////////////
  cout << "TEST: Insert ascending and descending sequences." << endl;
  HeapPQueue pq5;
  for (int i = 0; i < 20; i++) {
    pq5.enqueue({"a" + to_string(i), 2 * double(i)});
  }
  for (int i = 19; i >= 0; i--) {
    pq5.enqueue({"b" + to_string(i), 2 * double(i) + 1});
  }

  if (pq5.size() != 40) {
    cout << "Test Failed: pq.size() should return 40" << endl;
    return;
  }

  for (int i = 0; i < 40; i++) {
    auto removed = pq5.dequeue();
    if (removed.weight != i) {
      cout << "Test Failed: pq.dequeue() should return {\"a" << i << "\", " << i
           << "}" << endl;
      return;
    }
  }

  if (pq5.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq5.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 6th test
  //////////////////////////////////////////
  cout << "TEST: Insert large ascending and descending sequences." << endl;
  HeapPQueue pq6;
  for (int i = 0; i < 20000; i++) {
    pq6.enqueue({"a" + to_string(i), 2 * double(i)});
  }
  for (int i = 19999; i >= 0; i--) {
    pq6.enqueue({"b" + to_string(i), 2 * double(i) + 1});
  }

  if (pq6.size() != 40000) {
    cout << "Test Failed: pq.size() should return 40000" << endl;
    return;
  }

  for (int i = 0; i < 40000; i++) {
    auto removed = pq6.dequeue();
    if (removed.weight != i) {
      cout << "Test Failed: pq.dequeue() should return {\"a" << i << "\", " << i
           << "}" << endl;
      return;
    }
  }

  if (pq6.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq6.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 7th test
  //////////////////////////////////////////
  cout << "TEST: Insert random permutation." << endl;
  vector<DataPoint> sequence = {
      {"A", 0}, {"D", 3}, {"F", 5}, {"G", 6}, {"C", 2},
      {"H", 7}, {"I", 8}, {"B", 1}, {"E", 4}, {"J", 9},
  };

  HeapPQueue pq7;
  for (DataPoint elem : sequence) {
    pq7.enqueue(elem);
  }

  if (pq7.size() != sequence.size()) {
    cout << "Test Failed: pq.size() should return " << sequence.size() << endl;
    return;
  }

  for (int i = 0; i < 10; i++) {
    auto removed = pq7.dequeue();
    DataPoint expected = {string(1, 'A' + i), double(i)};
    if (removed.name != expected.name || removed.weight != expected.weight) {
      cout << "Test Failed: pq.dequeue() should return {\""
           << string(1, 'A' + i) << "\", " << i << "}" << endl;
      return;
    }
  }

  if (pq7.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq7.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 8th test
  //////////////////////////////////////////
  cout << "TEST: Insert deplicate elements" << endl;
  HeapPQueue pq8;
  for (int i = 0; i < 20; i++) {
    pq8.enqueue({"a" + to_string(i), double(i)});
  }
  for (int i = 19; i >= 0; i--) {
    pq8.enqueue({"b" + to_string(i), double(i)});
  }

  if (pq8.size() != 40) {
    cout << "Test Failed: pq.size() should return 40" << endl;
    return;
  }

  for (int i = 0; i < 20; i++) {
    auto one = pq8.dequeue();
    auto two = pq8.dequeue();

    if (one.weight != i || two.weight != i) {
      cout << "Test Failed: pq.dequeue() should return {\"a" << i << "\", " << i
           << "}" << endl;
      return;
    }
  }

  if (pq8.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq8.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 9th test
  //////////////////////////////////////////
  cout << "TEST: Insert many deplicate elements" << endl;
  HeapPQueue pq9;
  for (int i = 0; i < 20000; i++) {
    pq9.enqueue({"a" + to_string(i), double(i)});
  }
  for (int i = 19999; i >= 0; i--) {
    pq9.enqueue({"b" + to_string(i), double(i)});
  }

  if (pq9.size() != 40000) {
    cout << "Test Failed: pq.size() should return 40000" << endl;
    return;
  }

  for (int i = 0; i < 20000; i++) {
    auto one = pq9.dequeue();
    auto two = pq9.dequeue();

    if (one.weight != i || two.weight != i) {
      cout << "Test Failed: pq.dequeue() should return {\"a" << i << "\", " << i
           << "}" << endl;
      return;
    }
  }

  if (pq9.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq9.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 10th test
  //////////////////////////////////////////
  cout << "TEST: Handles data points with empty string name." << endl;
  HeapPQueue pq10;
  for (int i = 0; i < 10; i++) {
    pq10.enqueue({"", double(i)});
  }

  if (pq10.size() != 10) {
    cout << "Test Failed: pq.size() should return 10" << endl;
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (pq10.peek().name != "" || pq10.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq10.dequeue();
    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq10.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq10.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 11th test
  //////////////////////////////////////////
  cout << "TEST: Handles data points with empty string name." << endl;
  HeapPQueue pq11;
  for (int i = 0; i < 10000; i++) {
    pq11.enqueue({"", double(i)});
  }

  if (pq11.size() != 10000) {
    cout << "Test Failed: pq.size() should return 10000" << endl;
    return;
  }

  for (int i = 0; i < 10000; i++) {
    if (pq11.peek().name != "" || pq11.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq11.dequeue();
    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq11.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq11.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 12th test
  //////////////////////////////////////////
  cout << "TEST: Handles data points with negative weights." << endl;
  HeapPQueue pq12;
  for (int i = -10; i < 10; i++) {
    pq12.enqueue({"", double(i)});
  }

  if (pq12.size() != 20) {
    cout << "Test Failed: pq.size() should return 20" << endl;
    return;
  }

  for (int i = -10; i < 10; i++) {
    if (pq12.peek().name != "" || pq12.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq12.dequeue();

    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq12.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq12.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 13th test
  //////////////////////////////////////////
  cout << "TEST: Handles many data points with negative weights." << endl;
  HeapPQueue pq13;
  for (int i = -10000; i < 10000; i++) {
    pq13.enqueue({"", double(i)});
  }

  if (pq13.size() != 20000) {
    cout << "Test Failed: pq.size() should return 20000" << endl;
    return;
  }

  for (int i = -10000; i < 10000; i++) {
    if (pq13.peek().name != "" || pq13.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq13.dequeue();

    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq13.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq13.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  //////////////////////////////////////////
  // 14th test
  //////////////////////////////////////////
  cout << "TEST: Interleave enqueues and dequeues." << endl;
  HeapPQueue pq14;
  int n = 100;
  for (int i = n / 2; i < n; i++) {
    pq14.enqueue({"", double(i)});
  }

  if (pq14.size() != n / 2) {
    cout << "Test Failed: pq.size() should return " << n / 2 << endl;
    return;
  }

  for (int i = n / 2; i < n; i++) {
    if (pq14.peek().name != "" || pq14.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq14.dequeue();

    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq14.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  for (int i = 0; i < n / 2; i++) {
    pq14.enqueue({"", double(i)});
  }

  if (pq14.size() != n / 2) {
    cout << "Test Failed: pq.size() should return " << n / 2 << endl;
    return;
  }

  for (int i = 0; i < n / 2; i++) {
    if (pq14.peek().name != "" || pq14.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq14.dequeue();

    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq14.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  //////////////////////////////////////////
  // 15th test
  //////////////////////////////////////////
  cout << "TEST: Interleave many enqueues and dequeues." << endl;
  HeapPQueue pq15;
  int n2 = 10000;
  for (int i = n2 / 2; i < n2; i++) {
    pq15.enqueue({"", double(i)});
  }

  if (pq15.size() != n2 / 2) {
    cout << "Test Failed: pq.size() should return " << n2 / 2 << endl;
    return;
  }

  for (int i = n2 / 2; i < n2; i++) {
    if (pq15.peek().name != "" || pq15.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq15.dequeue();

    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq15.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  for (int i = 0; i < n2 / 2; i++) {
    pq15.enqueue({"", double(i)});
  }

  if (pq15.size() != n2 / 2) {
    cout << "Test Failed: pq.size() should return " << n2 / 2 << endl;
    return;
  }

  for (int i = 0; i < n2 / 2; i++) {
    if (pq15.peek().name != "" || pq15.peek().weight != double(i)) {
      cout << "Test Failed: pq.peek() should return {\"\", " << i << "}"
           << endl;
      return;
    }

    DataPoint res = pq15.dequeue();

    if (res.name != "" || res.weight != double(i)) {
      cout << "Test Failed: pq.dequeue() should return {\"\", " << i << "}"
           << endl;
      return;
    }
  }

  if (pq15.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  //////////////////////////////////////////
  // 16th test
  //////////////////////////////////////////
  cout << "TEST: Stress test: cycle 100,000 elems (should take at most a few "
          "seconds)"
       << endl;

  HeapPQueue pq16;
  int n3 = 100000;
  for (int i = 0; i < n3; i++) {
    pq16.enqueue({"", randomReal(double(-100000), double(100000))});
  }

  if (pq16.size() != n3) {
    cout << "Test Failed: pq.size() should return " << n3 << endl;
    return;
  }

  for (int i = 0; i < n3; i++) {
    pq16.dequeue();
  }

  if (pq16.size() != 0) {
    cout << "Test Failed: pq.size() should return 0" << endl;
    return;
  }

  if (!pq16.isEmpty()) {
    cout << "Test Failed: pq.isEmpty() should return true" << endl;
    return;
  }

  for (int i = 0; i < n3; i++) {
    pq16.enqueue({"", randomReal(double(-100000), double(100000))});
  }

  if (pq16.size() != n3) {
    cout << "Test Failed: pq.size() should return " << n3 << endl;
    return;
  }

  cout << "All tests passed!!!" << endl;
}

int main() {
  testHeapPQueue1();
  testHeapPQueue2();
  testHeapPQueue3();

  return 0;
}

/**
 * Returns a random real number in the half-open interval [low, high).
 * A half-open interval includes the first endpoint but not the second.
 */
double randomReal(double low, double high) {
  // Seed the random number generator (usually done once in the program)
  random_device rd;
  mt19937 gen(rd());

  // Define a uniform distribution for real numbers in the range [low, high)
  uniform_real_distribution<double> distribution(low, high);

  // Generate a random number
  return distribution(gen);
}
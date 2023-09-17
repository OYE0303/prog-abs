#include <iostream>
#include <cmath>
#include "../../Headers/executionTimeMeasurement.h"
using namespace std;

/* 
   divisorSum is a exhaustive algorithm
   loop throught from 1 ~ n
*/
long divisorSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor < n; divisor++) {
        if (n % divisor == 0) {
            total += divisor;
        }
    }
    return total;
}

bool isPerfect(long n) {
    return (n != 0) && (n == divisorSum(n)) && n > 0;
}

void findPerfects(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfect(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    cout << endl << "Done searching up to " << stop << endl;
}

/* 
   smarterSum is a optimize algorithm
   loop throught from 1 ~ sqrt(n)
*/
long smarterSum(long n) {
    long total = 0;

    for (long divisor = 1; divisor <= sqrt(n); divisor++) {
        if (n % divisor == 0) {
            total += divisor; // Add the smaller divisor
            long otherFactor = n / divisor;
            
            // Check if the divisor and the other factor are different
            if (otherFactor != divisor) {
                total += otherFactor; // Add the other factor
            }
        }
    }

    return total;
}

bool isPerfectSmarter(long n) {
  return (n != 0) && (n == smarterSum(n)) && n > 0;
}

void findPerfectsSmarter(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfectSmarter(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
    }
    cout << endl << "Done searching up to " << stop << endl;
}


int main() {
    measureExecutionTime(divisorSum, 1000000000);
    measureExecutionTime(smarterSum, 1000000000);

    return 0;
}


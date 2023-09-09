#ifndef EXECUTION_TIME_MEASUREMENT_H
#define EXECUTION_TIME_MEASUREMENT_H

#include "./../Sources/executionTimeMeasurement.cpp"

// Function to measure the execution time of another function
template <typename Func, typename... Args>
void measureExecutionTime(const Func& func, Args... args);

#endif
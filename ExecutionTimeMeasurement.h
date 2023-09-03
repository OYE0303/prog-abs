// ExecutionTimeMeasurement.h

#ifndef EXECUTION_TIME_MEASUREMENT_H
#define EXECUTION_TIME_MEASUREMENT_H

#include <iostream>
#include <functional>
#include <chrono>

// Function to measure the execution time of another function
template <typename Func, typename... Args>
void measureExecutionTime(const Func& func, Args... args) {
    // Start the clock
    auto start = std::chrono::high_resolution_clock::now();
    
    // Call the provided function with arguments
    func(args...);
    
    // Stop the clock
    auto stop = std::chrono::high_resolution_clock::now();
    
    // Calculate the duration in microseconds
    auto durationMicroSec = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    auto durationSec = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    
    // Print the execution time
    std::cout << "\033[1;34mExecution time: " << durationMicroSec.count() << " microseconds \033[0m\033[1;31m" << "/ " << durationSec.count() << " seconds\033[0m" << std::endl;
}

#endif // EXECUTION_TIME_MEASUREMENT_H

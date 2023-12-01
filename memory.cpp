#include <iostream>
#include <sys/resource.h>
#include <sys/time.h>
#include <fstream>
#include <sstream>

// Function to get CPU usage
double get_cpu_usage() {
    std::ifstream file("/proc/self/stat");
    std::string line;
    std::getline(file, line);
    std::istringstream iss(line);
    
    // Extracting utime (user time) and stime (system time) from /proc/self/stat
    long utime, stime;
    for (int i = 1; i <= 13; ++i) {
        iss.ignore();
    }
    iss >> utime >> stime;

    // Calculating total time
    long total_time = utime + stime;

    // Getting total elapsed time
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    long total_elapsed_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);

    // Calculating CPU usage percentage
    double cpu_usage = 100.0 * total_time / total_elapsed_time;

    return cpu_usage;
}

// Function to get memory usage
long get_memory_usage() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        return usage.ru_maxrss; // Max resident set size in kilobytes
    }
    return -1;
}

int main() {
    // Get initial resource usage
    long initial_memory = get_memory_usage();
    double initial_cpu = get_cpu_usage();

    // Simulate some workload (you can replace this with your actual code)
    for (int i = 0; i < 1000000000; ++i) {
        // Do some computations
    }

    // Get final resource usage
    long final_memory = get_memory_usage();
    double final_cpu = get_cpu_usage();

    // Calculate the usage difference
    long memory_usage_diff = final_memory - initial_memory;
    double cpu_usage_diff = final_cpu - initial_cpu;

    // Print the results
    std::cout << "Memory Usage: " << memory_usage_diff << " KB" << std::endl;
    std::cout << "CPU Usage: " << cpu_usage_diff << "%" << std::endl;

    return 0;
}


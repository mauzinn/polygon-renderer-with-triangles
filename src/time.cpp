#include <chrono>
#include "../include/time.hpp"

bool Time::canUpdate(int _frames) {
    std::chrono::high_resolution_clock::time_point current_time = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - Time::last_time);

    if (elapsed_time.count() >= (1000 / _frames)) {
        Time::last_time = current_time;
        return true;
    }
    return false;
}
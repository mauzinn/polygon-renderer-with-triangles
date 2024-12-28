#ifndef TIME_HPP
#define TINE_HPP

#include <chrono>

struct Time {
    std::chrono::high_resolution_clock::time_point last_time;

    bool canUpdate(int _frames);
};

#endif
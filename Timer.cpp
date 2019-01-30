#include <iostream>
#include <thread>
#include <chrono>
#include "Timer.hpp"

using namespace std;

void Timer::start(const Interval &interval,
           const Timeout &timeout)
{
    running = true;

    th = thread([=]()
    {
        while (running == true) {
            this_thread::sleep_for(interval);
            timeout();
        }
    });

// [*]
}

void Timer::stop()
{
    running = false;
    th.join();
}

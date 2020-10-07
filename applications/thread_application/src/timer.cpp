
#include "timer.h"

#include <iostream>

using namespace MyGame;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using namespace std::literals::chrono_literals;
using std::this_thread::sleep_for;


Timer::Timer(int timeout_in_ms):
m_timeout_in_ms(timeout_in_ms)
{}
void Timer::start()
{
    starttime  = Clock::now();     
    if(1300 == m_timeout_in_ms)
    {
        sleep_for(1300ms);
    }
    else if(2600 == m_timeout_in_ms)
    {
        sleep_for(2600ms);
    }
}


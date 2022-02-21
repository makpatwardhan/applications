#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>
#include <thread>
#include <functional>

#include "iplayer.h"

namespace MyGame
{

using Clock = std::chrono::steady_clock;


class Timer
{
public:
    Timer(int timeout_in_ms);    
    void start();
    
private:
int m_timeout_in_ms;
std::chrono::time_point<Clock> starttime;
std::chrono::time_point<Clock> endtime;
};
}
#endif

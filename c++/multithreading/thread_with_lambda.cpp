#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <chrono>
int main()
{
    // vector container stores threads
    std::vector<std::thread> workers;
    std::mutex counterMutex;
    int count = 0;   
    for (int i = 0; i < 5; i++) {
        workers.push_back(std::thread([&counterMutex,&count]() 
        {
            counterMutex.lock();
            count++;
            counterMutex.unlock();
            std::cout << count <<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }));
    }
    std::cout << "main thread\n";
    std::for_each(workers.begin(),workers.end(),[](std::thread& t){t.join();});
    return 0;
}
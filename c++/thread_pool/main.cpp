#include "function_pool.h"
#include <thread>
#include <iostream>
#include <vector>
int main()
{
	FunctionPool f;
	std::vector<std::thread> thread_pool;
	unsigned int n = std::thread::hardware_concurrency();
	std::cout << "Harware concurrency : " << n << std::endl;
	for(int i = 0; i< 5; i++)
	{
		thread_pool.emplace_back(std::thread(&FunctionPool::run, &f));
	}
		
	for(int i = 0 ; i < 100 ; i++)
	{
		f.push([]()
		{
			static  int counter = 0;
			std::cout << "Hello World : " << counter++ << std::endl;
		});
	}
	
	f.done();
	
	for(int i = 0; i < 5; i++)
	{
		if(thread_pool.at(i).joinable())
		{
			thread_pool.at(i).join();
		}
	}
}


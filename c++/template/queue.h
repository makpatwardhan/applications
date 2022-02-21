#include <queue>
#include <mutex>
#include <list>
#include <iostream>

namespace MyApp
{
	template<typename T>
	class queue
	{
		public:
		void push(T a);	
		void pop();
		T front();
		void print();
		private:
		std::mutex mutex;
		std::list<T> m_queue;
	};
}

#include "queue.cpp"



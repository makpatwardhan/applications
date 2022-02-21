#include <iostream>
namespace MyApp
{
	template <typename T>
	void queue<T>::push(T a)
	{
		mutex.lock();
		m_queue.emplace_back(a);
		mutex.unlock();
	}

	template <typename T>
	void queue<T>::pop()
	{	
		mutex.lock();
		m_queue.erase(m_queue.begin());
		mutex.unlock();
	}

	template <typename T>
	T queue<T>::front()
	{
		mutex.lock();	
		T  var = m_queue.front();
		mutex.unlock();
		return var;
	}
	template <typename T>
	void queue<T>::print()
	{
		for(auto& itr : m_queue)
		{
			std::cout << " " << itr <<std::endl;
		}
	}
}


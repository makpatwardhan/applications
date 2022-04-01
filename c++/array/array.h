#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>
#include <memory>

namespace MyArray
{
	template <typename T>
	class Array
	{
		public:		
		Array(int capacity);
		Array(const Array &obj);
		Array<T>& operator =(const Array& obj);
		Array(const Array &&obj);
		Array&& operator = (const Array&& obj);
		T& operator[](const T& index);
		void push(const T& ele);
		void print();
		
		private:
		int m_capacity;
		int m_size;
		std::unique_ptr<T*> arr;
		
	};
	#include "array.cpp"
}
#endif 

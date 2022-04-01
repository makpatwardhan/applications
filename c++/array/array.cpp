#include "array.h"
#include <string.h>

template <typename T>
Array<T>::Array(int capacity):
m_capacity(capacity)
{
	arr = std::make_unique<T*>(new T[m_capacity]);
	m_size = 0;
}

template <typename T>
Array<T>::Array(const Array &obj)
{
	m_capacity = obj.m_capacity;
	m_size = obj.m_size;
	arr = std::make_unique<T*>(new T[m_capacity]);
	memcpy(*arr, *obj.arr, m_size*sizeof(int));
}

template <typename T>	
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	std::unique_ptr<T*> arr1 = std::make_unique<T*>(new T[m_capacity]);
	m_capacity = obj.m_capacity;
	m_size = obj.m_size;
	arr.reset();
	arr = std::move(arr1);
	memcpy(*arr, *obj.arr, m_size*sizeof(int));
	return *this;
}

template <typename T>	
T& Array<T>::operator[](const T& index)
{
	if ( index > m_size)
	{
		throw "invalid index";
	}
	return arr[index];		
}

template <typename T>	
void Array<T>::push(const T& ele)
{
	(*arr)[m_size++] = ele;
}

template <typename T>	
void Array<T>::print()
{
	for(int i = 0; i < m_size; i++)
	{
		std::cout << (*arr)[i] << std::endl;
	}
}


	
	
	


#include<iostream>
#include <cstring>
#include "string.h"	

namespace MyDataStructure
{
	string::string(char *str)
	{
		m_capacity = m_size = strlen(str);
		m_str = std::make_unique<char *>(new char[m_capacity]);
		strcpy(*m_str, str);
	}

	string::string(const string& obj)
	{
		m_capacity = obj.m_capacity;
		m_size = obj.m_size;
		m_str = std::make_unique<char *>(new char[m_capacity]);
		strcpy(*m_str, *obj.m_str);
	}

	string& string::operator=(const string &obj)
	{
		m_str.reset();
		m_str = nullptr;
		m_capacity =obj.m_capacity;
		m_size = obj.m_size;
		m_str = std::make_unique<char *>(new char[m_capacity]);
		strcpy(*m_str,*obj.m_str);
		return *this;
	}

	string::string(string &&obj)
	{
		m_str = std::move(obj.m_str);
		obj.m_str = nullptr;
		m_capacity = std::move(obj.m_capacity);
		m_size = std::move(obj.m_size);

	}

	string&& string::operator==(string &&obj)
	{
		m_str.reset();
		m_str = nullptr;
		m_str = std::make_unique<char *>(new char[obj.m_capacity]);
		m_str = std::move(obj.m_str);
		obj.m_str = nullptr;
		m_capacity = std::move(obj.m_capacity);
		m_size = std::move(obj.m_size);
		return std::move(*this);
	}

	std::ostream & operator<<(std::ostream& out , string&obj)
	{
		out << "The string is " << *obj.m_str <<std::endl;
		return out;		
	}
	
}



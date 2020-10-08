#include "string.h"	
#include<iostream>

using namesapce MyDataStructure;

string::string():
capcity(10),
m_str(nullptr)
{
	m_str = std::make_shared<char *>(new char[10]);
	memset(m_str.get(),0x0,10);

}
string::string(const char *str);
{
	m_str = std::make_shared<char *>(new char[strlen(str)+1]);
	memset(m_str.get(),0x0,10);
	memcpy(m_str.get(),str,[strlen(str));
}
string::string (const int capacity)
{
}
string::string(const string& obj);
{
}
string::string(string&& obj)
{
	
}
string::~string()
{
	m_str.reset();
}

	
	

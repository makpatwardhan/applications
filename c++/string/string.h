#ifndef _STRING_H_
#define _STRING_H_

#include <memory>

namespace MyDataStructure
{
	
class string
{
	public:
	string();
	string(const char *str);
	string (const int capacity);
	string(const string& obj);
	string(string&& obj);~string()
	~string();

	private:
	std::shared_ptr<char *> m_str;
	int m_size;	
}; 
	
}
#endif

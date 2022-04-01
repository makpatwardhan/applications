#ifndef _STRING_H_
#define _STRING_H_

#include <memory>
#include <iostream>

namespace MyDataStructure
{
	class string
	{
		public:
		string(char *str);
		string (const string& obj);
		string& operator=(const string &obj);
		string(string &&obj);
		string && operator==(string &&obj);
		friend std::ostream & operator<<(std::ostream& out , string&obj);
		private:
		int m_capacity;
		int m_size;
		std::unique_ptr<char *> m_str;
	};
}
#endif 

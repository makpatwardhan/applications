#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> str;
	std::string str1 = "abc"; 
	//str.push_back(str1);
	str.emplace_back(std::move(str1));
	std::cout << str1 <<std::endl;
}

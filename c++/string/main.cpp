#include "string.h"
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace MyDataStructure;


int main()
{
    char *str = "makarand";
    string s1(str);
    string s2 = s1;
    string s3("");
    s3 = s2;
    std::cout << s3;
    string s4(std::move(s3));
    string s5("siddartha");
    std::cout << s4;
    s5 = std::move(s4);
    std::cout << s5;
}
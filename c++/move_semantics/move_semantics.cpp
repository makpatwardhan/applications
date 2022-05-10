/* Move semantics is about transferring resources rather than copying them 
when nobody needs the source value anymore.
Move semantics allows you to avoid unnecessary copies when working with temporary objects that are about to evaporate, and whose resources can 
safely be taken from that temporary object and used by another*/
#include <iostream>
#include <cstring>
#include <cstdint>

class MyString
{
public:
    MyString(const char *str)
    {
        std::cout << "Constructor" <<std::endl;
        m_size = strlen(str) + 1;
        m_data = new char[m_size];
        memset(m_data,0,m_size);
        memcpy(m_data,str,m_size);
    }
    MyString(const MyString& obj)
    {
        std::cout << "Copying" <<std::endl;
        m_size = obj.m_size;
        m_data = new char[m_size];
        memcpy(m_data,obj.m_data,m_size);
    }
    MyString(MyString&& obj)
    {
        std::cout << "Moved!!" <<std::endl;
        m_size = obj.m_size;
        m_data = obj.m_data;
        obj.m_data = nullptr;
        obj.m_size = 0;
    }
    void print()
    {
        std::cout << "The string is " << m_data <<std::endl;
    }
    ~ MyString()
    {
        std::cout << "destructor" <<std::endl;
        delete[] m_data;
    }
private:
    char *m_data;
    uint32_t m_size;     
};

class MyStringWrapper
{
    public:
    MyStringWrapper(const MyString& str):
    m_name(str)
    {            
    }
    MyStringWrapper(MyString&& str):
    m_name(std::move(str))
    {
    }
    void printName()
    {
        m_name.print();
    }
    MyString m_name;
};


int main(void)
{
    MyStringWrapper m("Makarand");
    m.printName();
}
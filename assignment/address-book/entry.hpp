#ifndef ENTRY_HPP_
#define ENTRY_HPP_

#include <string>
struct Entry
{
    Entry(const std::string& fist_name, const std::string& last_name = "", const std::string phone_number = ""):
    m_first_name(fist_name),
    m_last_name(last_name),
    m_phone_number(phone_number){}
    
    const std::string& getFirstName(){return m_first_name;}
    const std::string& getLastName(){return m_last_name;}
    const std::string& getPhoneNumber(){return m_phone_number;}

    private:
    std::string m_first_name;
    std::string m_last_name;
    std::string m_phone_number;
};
#endif
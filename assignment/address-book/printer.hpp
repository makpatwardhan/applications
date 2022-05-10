#ifndef PRINTER_HPP_
#define PRINTER_HPP_

#include    "entry.hpp"
#include    <string>
#include    <list>
#include    <map>
#include    <memory>
#include    <iostream>
#include    <utility>

namespace AddressBookApp
{
    using AddressMap = std::map<std::string, std::shared_ptr<Entry> >;
    using AddressList = std::list<std::shared_ptr<Entry> >;
    using AddressMultiMap = std::multimap<std::string, std::shared_ptr<Entry> >;

    class Printer
    {
        public:
        static void print(const std::shared_ptr<Entry>& entry)
        {
                std::cout << "###################################################" <<std::endl;
                std::cout << " First Name : " << entry->getFirstName() <<std::endl;
                std::string last_name = entry->getLastName();
                if(!last_name.empty())
                {
                    std::cout << " Last Name : " << entry->getLastName() <<std::endl; 
                }
                else
                {
                    std::cout << " Last Name : N/A" << std::endl; 
                }
                std::string phone_number = entry->getPhoneNumber();
                if(!phone_number.empty())
                {
                    std::cout << " phone number : " << entry->getLastName() <<std::endl; 
                }
                else
                {
                    std::cout << " phone number : N/A" << std::endl; 
                }
                std::cout << "###################################################" <<std::endl;

        }
        static void print(const AddressList& list)
        {
            for(auto& it: list)
            {
                print(it);
            }
        }
    };
}
#endif
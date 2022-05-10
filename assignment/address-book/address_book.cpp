#include <iostream>
#include <algorithm>
#include "address_book.hpp"


namespace AddressBookApp
{
    void AddressBook::add(const std::string& first_name, const std::string& last_name ,const std::string& phone_number)
    {
        std::shared_ptr<Entry> address = std::make_shared<Entry>(first_name,last_name,phone_number);
        m_lock.lock();
        m_addresses.emplace_back(address);
        m_first_names.emplace(first_name,address);
        if(last_name != "")
        {
            m_last_names.emplace(last_name,address);
        }
        m_lock.unlock();
    }

    void AddressBook::remove(const std::string& first_name)
    {
        std::string last_name = "";
        m_first_names.erase(first_name);
        m_lock.lock();
        m_addresses.remove_if([first_name, &last_name](const auto& entry)
        {   
            if(first_name == entry->getFirstName())
            {
                last_name = entry->getLastName();
                return true;
            }
            return false;
        });       
        if(!last_name.empty())
        {
            if(m_last_names.count(last_name) == 1)
            {
                m_last_names.erase(last_name);
            }
            else
            {
                using iterator = AddressMultiMap::iterator;
                std::pair<iterator, iterator> iterpair = m_last_names.equal_range(last_name);
                iterator it = iterpair.first;
                    while(it != iterpair.second) 
                    {
                        if (it->second->getFirstName() == first_name) { 
                            it = m_last_names.erase(it);
                        }
                        else
                        {
                            ++it;
                        }
                    }
            }
        }
        m_lock.unlock();       
    }

    void AddressBook::search(std::string name, AddressList& result)
    {   
        std::transform(name.begin(), name.end(),name.begin(),::tolower);

        std::find_if(m_first_names.begin(),m_first_names.end(),[name, &result](const auto &it){
                std::string tempStr = it.first;
                std::transform(tempStr.begin(), tempStr.end(),tempStr.begin(),::tolower);
                if(tempStr.compare(0, name.size(), name) == 0)
                {
                    result.emplace_back(it.second);            
                }
            return false;
        });

        std::find_if(m_last_names.begin(),m_last_names.end(),[name, &result](const auto &it){
                std::string tempStr = it.first;
                std::transform(tempStr.begin(), tempStr.end(),tempStr.begin(),::tolower);
                if(tempStr.compare(0, name.size(), name) == 0)
                {
                    result.emplace_back(it.second);            
                }
                return false;
        });
    }
    const AddressMap& AddressBook::getAllEntriesByFirstName()
    {
        return  m_first_names;
    }
    const AddressMultiMap& AddressBook::getAllEntriesByLastName()
    {
        return m_last_names;   
    }
    const AddressList& AddressBook::getAddressBook()
    {
        return m_addresses;
    }

}

#ifndef ADDRESS_BOOK_HPP_
#define ADDRESS_BOOK_HPP_

#include    <string>
#include    <list>
#include    <map>
#include    <memory>
#include    <vector>
#include    <mutex>
#include    "entry.hpp"

namespace AddressBookApp
{
    using AddressMap = std::map<std::string, std::shared_ptr<Entry> >;
    using AddressList = std::list<std::shared_ptr<Entry> >;
    using AddressMultiMap = std::multimap<std::string, std::shared_ptr<Entry> >;

    class AddressBook
    {
        public:
        AddressBook(){}
        void add(const std::string& first_name, const std::string& last_name = "",  
                    const std::string& phone_number = "");                    
        void remove(const std::string& name);        
        void search(std::string name, AddressList& result);
        const AddressMap& getAllEntriesByFirstName();
        const AddressMultiMap& getAllEntriesByLastName();
        const AddressList& getAddressBook();
        AddressBook(const AddressBook& obj) = delete;
        AddressBook& operator= (const AddressBook& obj) = delete;
        ~AddressBook(){}

        private:
        AddressList m_addresses;
        AddressMap m_first_names;
        AddressMultiMap m_last_names;
        std::mutex m_lock;
    };
}

#endif
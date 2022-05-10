#include "address_book.hpp"
#include "printer.hpp"
#include <memory>
#include <iostream>
#include <exception>

using namespace AddressBookApp;

int main (void)
{
    try
    {
        std::shared_ptr<AddressBook> address_book = std::make_shared<AddressBook>();
        address_book->add("Supriya", "Kirperkar");
        address_book->add("Rugved" ,"Patwardhan" , "+31620673958");
        address_book->add("Makarand" ,"Patwardhan" , "+31620673958");
        address_book->add("Mak" ,"Limaye");
        address_book->add("Ashok" ,"Joshi" , "+919011046410");
        address_book->add("Mandar" ,"Makarand" , "+919011046410");
        address_book->add("John");

        std::cout << " ******* Address book sorted by first name ******" <<std::endl;

        for(auto &it : address_book->getAllEntriesByFirstName())
        {
            Printer::print(it.second);
        }
        std::cout << "******************************************************" <<std::endl <<std::endl;

        std::cout << " ******* Address book sorted by last name ******" <<std::endl;

        for(auto &it : address_book->getAllEntriesByLastName())
        {
            Printer::print(it.second);
        }
        std::cout << "******************************************************" <<std::endl << std::endl;

        AddressList result;
        std::cout << " *************** Search name pattern in address book **********" <<std::endl;
        address_book->search("mak", result);
        Printer::print(result);
        std::cout << " ****************************************************************" <<std::endl <<std::endl;

        address_book->remove("Makarand");

        std::cout << "***************** Address book after removing the record **********" << std::endl;
        Printer::print(address_book->getAddressBook());
        std::cout << " ****************************************************************" <<std::endl <<std::endl;
        
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }       
    return 0;
}
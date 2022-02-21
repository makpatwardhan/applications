#include "unique_pointer.hpp"

#include <iostream>  //main header
using namespace std; //namespace

int main()
{
    the_unique_ptr<int> up1 = new int(2);
    
    //the_unique_ptr<int> up2 = up1;
        
    the_unique_ptr<int> up2 = std::move(up1);
    
    the_unique_ptr<int> up3 ;
    
    up3 = std::move(up2);
    
    *up2 = 4;
    cout << *up2 << endl;

    the_unique_ptr<std::string> up3 = 
                       new std::string("mainfunda");
    the_unique_ptr<std::string> up4 = std::move(up3);
    cout << *up4 << endl;
    cout << up4->size() << endl;

    return 0;
}

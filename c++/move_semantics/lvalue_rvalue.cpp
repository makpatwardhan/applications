/* In C++, there are rvalues and lvalues. An lvalue is an expression whose address can be taken, a locator value--essentially, an lvalue provides a (semi)permanent piece of memory. 
You can make assignments to lvalues. For example*/

/*Rvalues are--well, rvalues are not lvalues. An expression is an rvalue 
if it results in a temporary object.
*/
#include <string>
#include <iostream>

int x;
int& getRef () 
{
        return x;
}

std::string getName ()
{
    return "Alex";
}

void printReference (const std::string& str)
{
    std::cout << "calling l-value reference : " << str <<std::endl;
}
 
void printReference (std::string&& str)
{
    std::cout << "calling r-value reference :" << str << std::endl;
}

int main()
{
    /* Here, getRef returns a reference to a global variable, 
    so it's returning a value that is stored in a permanent location. (You could literally write & getRef() if you wanted to, and it would give you the address of x.)
    */
    getRef() = 4;
    /* Here, getName returns a string that is constructed inside the function
    you're assigning from a temporary object, not from some value that has a fixed location. getName() is an rvalue.*/
    std::string name = getName();
    /* This below function will call l-value reference version of printReference */
    printReference(name);
    /* This below function will call r-value reference version of printReference */
    printReference(getName());
}


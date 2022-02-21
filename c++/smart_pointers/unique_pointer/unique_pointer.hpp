#include <iostream>  //main header
using namespace std; //namespace

template<typename T>
class the_unique_ptr  //smart pointers implementation
{
    T* up_data;

    public:
    the_unique_ptr(T* p) 
    {
        up_data = p;
    }
    
    the_unique_ptr(const the_unique_ptr& up_rhs) = delete;
    
    the_unique_ptr(the_unique_ptr&& up_rhs)
    {
        up_data = std::move(up_rhs.up_data);
        up_rhs.up_data = NULL;
    }
    the_unique_ptr& operator=
            (const the_unique_ptr& up_rhs) = delete;

    the_unique_ptr& operator=
            (the_unique_ptr&& up_rhs)
    {
        up_data = std::move(up_rhs.up_data);

        up_rhs.up_data = NULL;
        return (*this);
    }
    T& operator*()
    {
        return (*up_data);
    }
    T* operator->()
    {
        return up_data;
    }
    ~the_unique_ptr()
    {
        cout << "Automatic clean-up" 
             << endl;
        if(up_data)
            delete up_data;
        up_data = NULL;
    }
};
  


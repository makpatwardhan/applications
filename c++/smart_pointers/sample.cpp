#include <memory>
#include <iostream>

class sample
{
	public:
	sample()
	{
		std::cout << "object created" <<std::endl;
	}
	
	~sample()
	{
		std::cout << "Object is destruction" <<std::endl;
	}
};
 

void func1(std::shared_ptr<sample>& ptr)
{
	std::cout << " the count is " << ptr.use_count() << std::endl;
}

int xyz()
{
	//sample *s = new sample();
	std::shared_ptr<sample> ptr(new sample);
	{
		//std::shared_ptr<sample>& ptr2 = ptr;		
		//std::cout << " the count is " << ptr.use_count() << std::endl;
	}
	func1(ptr);
	std::cout << " the count is " << ptr.use_count() << std::endl;	
	
	
	std::shared_ptr<sample> ptr2 = ptr;
}

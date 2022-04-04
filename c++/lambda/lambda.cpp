#include <iostream>
#include<functional>


/* basic labda */

auto lambda = [](auto x, auto y)->decltype(x+y)
{
	return x+y;
};

/* recursive lambda */

std::function<int (int)> f = [f](int x)->int 
{
	if (x == 0) return 1;
	if(x == 1 ) return 1;
	return x * f(x-1);
};

int main()
{
	
	std::cout << "The sum is " << f(4);
}

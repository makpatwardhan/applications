#include "queue.h"
#include <functional>


int main()
{
	MyApp::queue<std::function<void(int,int)> > q1;
	q1.push([](int a, int b)
	{
		
		std::cout << a << b << std::endl;
	});
	
	std::function<void(int,int)> func = q1.front();
	func(2,3);
	q1.pop();	
}

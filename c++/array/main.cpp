#include "array.h"

using namespace MyArray;

int main()
{
	Array<int> arr(10);
	Array<int> arr1(1);
	arr.push(10);
	arr.push(20);
	arr.push(30);
	arr.push(40);
	arr.push(50);
	arr.print();
	arr1 = arr;
	arr1.print();	
}

#include <iostream>
#include "NonNullObserverPtr.h"


int main()
{
	int x = 1;
	int* pX = &x;

	NonNullObserverPtrL<int> xWrap(pX);
	*xWrap = 2;
	std::cout << *xWrap;

	int* NULLPTR = nullptr;

	NonNullObserverPtrL<int> nullWrap(NULLPTR);

	try
	{
		NonNullObserverPtrT<int> qwe(NULLPTR);
	}
	catch (InvalidPointer& ip)
	{
		std::cout << ip.what();
	}



	return 0;
}